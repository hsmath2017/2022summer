#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans=0;
    int check(const vector<int>& columns,const vector<vector<int>>& mat){
        int n=mat[0].size();
        map<int,bool> avail;
        for(auto c:columns){
            avail[c]=true;
        }
        int res=0;
        for(int i=0;i<mat.size();i++){
            res++;
            for(int j=0;j<n;j++){
                if(avail[j]==false){
                    if(mat[i][j]==1){
                        res--;
                        break;
                    }
                }
            }
        }
        return res;
    }
    void dfs(int start,int end,const vector<vector<int>>& mat,vector<int>& columns,const int& cols){
        if(columns.size()==cols){
            ans=max(ans,check(columns,mat));
            columns.pop_back();
            return;
        }
        for(int i=start;i<end;i++){
            columns.push_back(i);
            dfs(i+1,end,mat,columns,cols);
        }
        columns.pop_back();
        return;
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m=mat.size();
        int n=mat[0].size();
        int start=0;
        int end=n-1;
        vector<int> columns;
        dfs(0,n,mat,columns,cols);
        return ans;
    }
};