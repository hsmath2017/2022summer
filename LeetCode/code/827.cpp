#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool indomain(const vector<int>& pt,int n){
        if(pt[0]>=0&&pt[0]<n&&pt[1]>=0&&pt[1]<n){
            return true;
        }else{
            return false;
        }
    }
    int dfs(const vector<int>& pos,vector<vector<int>>& grid,int n,int index){
        const vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto v:dir){
            vector<int> tmp;
            tmp[0]=pos[0]+v[0];
            tmp[1]=pos[1]+v[1];
            grid[pos[0]][pos[1]]=index;
            if(indomain(tmp)==true&&grid[tmp[0]][tmp[1]]==1){
                
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        //step 0:特判
        int n=grid.size();
        bool haveone=false;
        bool havezero=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    havezero=true;
                }
                if(grid[i][j]==1){
                    haveone=true;
                }
            }
        }
        if(havezero==false){
            return n*n;
        }
        if(haveone==false){
            return 0;
        }
        //step 1:找到所有的连通块并标号
        int index=2;//标号从2开始
        map<int,int> index2area;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vector<int> pos{i,j};
                    index2area[index]=dfs(pos,grid,n,index);
                    index++;
                }
            }
        }
    }
};