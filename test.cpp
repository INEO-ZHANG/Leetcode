#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;


void bfs(int x, int y, int n, int m, vector<vector<char>> h, vector<vector<bool>> &visited){
    char color=h[x][y];
    queue<int> a;
    queue<int> b;
    a.push(x);
    b.push(y);
    visited[x][y]=true;
    while(!a.empty()){
        if(a.front()>0&&visited[a.front()-1][b.front()]==false&&h[a.front()-1][b.front()]==color){
            a.push(a.front()-1);
            b.push(b.front());
            visited[a.front()-1][b.front()]=true;
        }
        if(a.front()<n-1&&visited[a.front()+1][b.front()]==false&&h[a.front()+1][b.front()]==color){
            a.push(a.front()+1);
            b.push(b.front());
            visited[a.front()+1][b.front()]=true;
        }
        if(b.front()>0&&visited[a.front()][b.front()-1]==false&&h[a.front()][b.front()-1]==color){
            a.push(a.front());
            b.push(b.front()-1);
            visited[a.front()][b.front()-1]=true;
        }
        if(b.front()<m-1&&visited[a.front()][b.front()+1]==false&&h[a.front()][b.front()+1]==color){
            a.push(a.front());
            b.push(b.front()+1);
            visited[a.front()][b.front()+1]=true;
        }
        a.pop();
        b.pop();
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    //cout<<n<<' '<<m<<endl;
    vector<vector<char>> h(n,vector<char>(8));
    vector<vector<char>> h1(n,vector<char>(8));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>h[i][j];
            h1[i][j]=h[i][j];
            if(h1[i][j]=='B')h1[i][j]='G';
            //cout<<h[i][j];
        }
    
    vector<vector<bool>> visited1(n,vector<bool>(m,false));
    vector<vector<bool>> visited2(n,vector<bool>(m,false));

    int ans=0,nAns=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited1[i][j]==false){
                ans++;
                bfs(i,j,n,m,h,visited1);
            }
            if(visited2[i][j]==false){
                nAns++;
                bfs(i,j,n,m,h1,visited2);
            }
        }
    }
    cout<<ans-nAns;
}