"""手写多头自注意力：投影 -> 拆头 -> 算注意力 -> 合并 -> 输出。

先看 forward，再盖住代码，按这五步自己写一遍。
B = batch 大小，T = 序列长度，C = d_model，H = 头数，D = C // H。
"""

import math

import torch
from torch import nn


class MultiHeadAttention(nn.Module):
    def __init__(self, d_model: int, num_heads: int):
        super().__init__()
        if d_model <= 0 or num_heads <= 0 or d_model % num_heads != 0:
            raise ValueError("d_model 和 num_heads 必须为正数，且 d_model 能被 num_heads 整除")

        self.num_heads = num_heads
        self.head_dim = d_model // num_heads

        # Q：我想找什么；K：我有什么特征；V：我提供什么信息。
        self.q_proj = nn.Linear(d_model, d_model)
        self.k_proj = nn.Linear(d_model, d_model)
        self.v_proj = nn.Linear(d_model, d_model)
        self.out_proj = nn.Linear(d_model, d_model)

    def forward(self, x: torch.Tensor, causal: bool = False):
        """输入 x: [B, T, C]；返回输出 [B, T, C] 和注意力权重 [B, H, T, T]。

        这是 self-attention：Q、K、V 都来自 x。
        causal=True 时，每个位置只能关注自己和前面的位置。
        """
        B, T, C = x.shape
        H, D = self.num_heads, self.head_dim

        # 1. 三组独立线性投影：[B, T, C] -> [B, T, C]
        q = self.q_proj(x)
        k = self.k_proj(x)
        v = self.v_proj(x)

        # 2. 拆成 H 个头：[B, T, C] -> [B, T, H, D] -> [B, H, T, D]
        # 把 H 移到前面后，矩阵乘法会在每个 batch 的每个头内独立计算。
        q = q.reshape(B, T, H, D).transpose(1, 2)
        k = k.reshape(B, T, H, D).transpose(1, 2)
        v = v.reshape(B, T, H, D).transpose(1, 2)

        # 3. Attention(Q, K, V) = softmax(Q @ K^T / sqrt(D)) @ V
        # [T, D] @ [D, T] -> [T, T]；scores[..., i, j] 表示 i 对 j 的打分。
        # 除以 sqrt(D)，避免维度变大时点积过大，使 softmax 过于尖锐。
        scores = q @ k.transpose(-2, -1) / math.sqrt(D)
        if causal:
            # 上三角（不含对角线）代表未来位置；-inf 经 softmax 后变成 0。
            future = torch.ones(T, T, dtype=torch.bool, device=x.device).triu(1)
            scores = scores.masked_fill(future, float("-inf"))
        weights = torch.softmax(scores, dim=-1)  # 沿被关注的位置 j 归一化
        heads = weights @ v                    # [B, H, T, D]

        # 4. 合并各头：先换回 T、H 的顺序，再把 H * D 拼成 C。
        merged = heads.transpose(1, 2).reshape(B, T, C)

        # 5. 输出投影：让不同头的信息相互组合。
        output = self.out_proj(merged)
        return output, weights


if __name__ == "__main__":
    torch.manual_seed(42)
    torch.set_printoptions(precision=3, sci_mode=False)

    # 1 个样本，4 个 token，每个 token 用 8 维向量表示；2 个头，各 4 维。
    x = torch.randn(1, 4, 8)
    mha = MultiHeadAttention(d_model=8, num_heads=2)
    output, weights = mha(x, causal=True)

    print("输入形状：", tuple(x.shape))
    print("输出形状：", tuple(output.shape))
    print("权重形状：", tuple(weights.shape))
    print("第 1 个头的注意力（行=查询位置，列=被关注位置）：")
    print(weights[0, 0].detach())
    print("每行权重之和：", weights[0, 0].sum(dim=-1).detach())
