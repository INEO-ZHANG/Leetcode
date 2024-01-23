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
    void minDistance(vector<vector<int>>& dis, int i, int j){
        int distance=dis[i][j];
        if(i>0){
            distance=min(dis[i-1][j],distance);
        }
        if(i<dis.size()-1){
            distance=min(dis[i+1][j],distance);
        }
        if(j>0){
            distance=min(dis[i][j-1],distance);
        }
        if(j<dis[0].size()-1){
            distance=min(dis[i][j+1],distance);
        }
        dis[i][j]=distance+1;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int MAXlen=0;
        vector<vector<int>> dis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int, int>> dp;
        int flag=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    dp.push({i,j});
                    dis[i][j]=0;
                    visited[i][j]=1;
                }
                else{
                    flag=1;
                }
            }
        }
        if(flag==0)return -1;
        if(dp.empty())return -1;
        while(!dp.empty()){
            int i=dp.front().first,j=dp.front().second;
            if(i>0&&visited[i-1][j]==0){
                dp.push({i-1,j});
                minDistance(dis,i-1,j);
            }
            if(i<grid.size()-1&&visited[i+1][j]==0){
                dp.push({i+1,j});
                minDistance(dis,i+1,j);
            }
            if(j>0&&visited[i][j-1]==0){
                dp.push({i,j-1});
                minDistance(dis,i,j-1);
            }
            if(j<grid[0].size()-1&&visited[i][j+1]==0){
                dp.push({i,j+1});
                minDistance(dis,i,j+1);
            }
            visited[i][j]=1;
            MAXlen=max(MAXlen,dis[i][j]);
            dp.pop();
        }
        return MAXlen;
    }
};

int main(){
    Solution slo;
    vector<vector<int>> grid(3,vector<int>(3,0));
    grid[0][0]=1;
    cout<<slo.maxDistance(grid);
}