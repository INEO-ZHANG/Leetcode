# Leetcode

个人算法练习仓库，收录 LeetCode 题目、面试题和其他练习，主要使用 C++，另有 Python、Java 和 JavaScript 文件。

## 文件说明

- 数字命名的 C++ 文件对应 LeetCode 题号，例如 `125.cpp`、`228.cpp`、`242.cpp`、`290.cpp`。
- `add_two_numbers.py`：两数相加练习。
- `merge_intervals.py`：合并区间练习。
- `mha.py`：带维度注释的多头自注意力（MHA）练习。
- `offer24.cpp`、`nqueens.cpp`、`honor_2.cpp` 等为其他算法练习。
- `test*` 和 `leetcode.py` 为实验或草稿文件。
- `.vscode/` 保存本地编辑和调试配置，编译器及调试器路径需要按实际环境调整。

各文件独立使用，没有统一的应用入口。部分代码仍为练习草稿，示例不代表已通过所有测试。

## 本地运行

使用支持 C++11 或更新标准的编译器，以及 Python 3。以下命令在仓库根目录的 PowerShell 中执行。

编译并运行一个带 `main` 函数的 C++ 文件：

```powershell
New-Item -ItemType Directory -Force build | Out-Null
g++ -std=c++17 125.cpp -o build/125.exe
.\build\125.exe
```

运行 Python 示例：

```powershell
python merge_intervals.py
```

Java 练习可使用 JDK 编译运行：

```powershell
New-Item -ItemType Directory -Force build | Out-Null
javac -d build test.java
java -cp build test
```

新增练习时保留源文件，将编译产物放入 `build/`；该目录及常见缓存、二进制文件已通过 `.gitignore` 排除。

## 快速练习 MHA

`mha.py` 使用 PyTorch，手写多头自注意力的核心计算，可选开启因果遮罩。为方便练习，省略 dropout、padding 遮罩、残差连接和 LayerNorm。

首次运行时安装依赖（CPU 版即可）：

```powershell
python -m venv .venv
.\.venv\Scripts\python.exe -m pip install torch --index-url https://download.pytorch.org/whl/cpu
.\.venv\Scripts\python.exe -m pip install numpy
.\.venv\Scripts\python.exe mha.py
```

记住这条主线：**Q/K/V 投影 → 拆头 → softmax(QKᵀ / √head_dim)V → 合并各头 → 输出投影**。

| 步骤 | 张量形状 |
| --- | --- |
| 输入和 Q/K/V 投影 | `[B, T, C]` |
| 拆头 | `[B, H, T, D]`，其中 `D = C / H` |
| 注意力分数和权重 | `[B, H, T, T]` |
| 权重乘 V | `[B, H, T, D]` |
| 合并及输出 | `[B, T, C]` |

建议花 10 分钟练习：

1. 运行示例，观察权重矩阵每行之和为 1，未来位置的权重为 0。
2. 把 `causal=True` 改成 `False`，观察上三角区域的变化；再把头数改成 4，预测权重形状。
3. 盖住 `forward`，按五步重写。重点想清楚：为什么转置 K 的最后两维？为什么 softmax 用 `dim=-1`？为什么合并前还要转置？

参考：[PyTorch MultiheadAttention 文档](https://docs.pytorch.org/docs/stable/generated/torch.nn.MultiheadAttention.html)。
