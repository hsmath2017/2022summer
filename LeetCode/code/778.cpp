#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using pii=pair<int,int>;
    int n;
    bool getpos=false;
    const vector<pii> dir={{1,1},{1,-1},{-1,1},{-1,-1}};
    void dfs(pii pos,const vector<vector<bool>>& boolean_mat,vector<vector<bool>>& visited,bool& check){
        if(getpos){
            return;
        }
        if(pos.first==n-1&&pos.second==n-1){
            check=true;
            getpos=true;
            return;
        }
        visited[pos.first][pos.second]=true;
        for(auto v:dir){
            pii tmp={pos.first+v.first,pos.second+v.second};
            if(tmp.first>=0&&tmp.first<n&&tmp.second>=0&&tmp.second<n&&visited[tmp.first][tmp.second]==false&&boolean_mat[tmp.first][tmp.second]==true){
                dfs(tmp,boolean_mat,visited,check);
            }
        }
        return;
    }
    int binary_find(int left,int right,const vector<vector<int>>& grid){
        if(left==right){
            return left;
        }
        int mid=(left+right)/2;
        vector<vector<bool>> boolean_mat(n,vector<bool>(n));
        vector<vector<bool>> visited(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>=mid){
                    boolean_mat[i][j]=true;
                }
            }
        }
        pii start{0,0};
        bool check=false;
        getpos=false;
        if(boolean_mat[start.first][start.second]==false||boolean_mat[n-1][n-1]==false){
            check=false;
        }else{
            dfs(start,boolean_mat,visited,check);
        }
        if(check){
            return binary_find(left,mid,grid);
        }else{
            return binary_find(mid+1,right,grid);
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        int left=0;
        int right=0;
        for(auto v:grid){
            for(auto c:v){
                right=max(right,c);
            }
        }
        int ans=binary_find(left,right,grid);
    }
};