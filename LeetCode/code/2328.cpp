#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int m;
    int n;
    bool inDomain(const vector<int>& point){
        if(point[0]>=0&&point[0]<m&&point[1]>=0&&point[1]<n){
            return true;
        }else{
            return false;
        }
    }    
    int dfs(int x,int y,vector<vector<int>>& DP,const vector<vector<int>>& grid){
        if(DP[x][y]!=-1){
            return DP[x][y];
        }
        vector<int> start{x,y};
        int val=1;
        for(auto d:dir){
            vector<int> tmp{x+d[0],y+d[1]};
            if(inDomain(tmp)==false){
                continue;
            }
            if(grid[tmp[0]][tmp[1]]>grid[x][y]){
                val=(val+dfs(tmp[0],tmp[1],DP,grid))%MOD;
            }
        }
        //记忆化搜索
        return DP[x][y]=val;
    }
public:
    const int MOD=1e9+7;
    const vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    int countPaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> DP;
        DP.resize(m);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                DP[i].push_back(-1);//-1 means this point isn't traversed
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=(res+dfs(i,j,DP,grid))%MOD;
            }
        }
        return res;
    }
};
