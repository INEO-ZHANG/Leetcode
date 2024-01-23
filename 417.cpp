#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j, int& AO, int& PO){
        if(i==0||j==0)PO=1;
        if(i==(heights.size()-1)||j==(heights[0].size()-1))AO=1;
        if(AO==1&&PO==1)return;
        int H=heights[i][j];

        if(i>0&&heights[i-1][j]<=H)dfs(heights,i-1,j,AO,PO);
        if(i<heights.size()-1&&heights[i+1][j]<=H)dfs(heights,i+1,j,AO,PO);
        if(j>0&&heights[i][j-1]<=H)dfs(heights,i,j-1,AO,PO);
        if(j<heights[0].size()-1&&heights[i][j+1]<=H)dfs(heights,i,j+1,AO,PO);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                int AO=0,PO=0;
                dfs(heights,i,j,AO,PO);
                if(AO==1&&PO==1){
                    vector<int> tmp(i,j);
                    res.emplace_back(tmp);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution slo;
    vector<vector<int>> grid(3,vector<int>(3,0));
    grid[0][2]=1;
    vector<vector<int>> res=slo.pacificAtlantic(grid);
    for(int i=0;i<res.size();i++)
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
}