#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans;
        ans.resize(n-2);
        for(int i=0;i<n-2;i++){
            ans[i].resize(n-2);
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                int res=0;
                res=max(res,grid[i-1][j]);
                res=max(res,grid[i][j]);
                res=max(res,grid[i+1][j]);
                res=max(res,grid[i][j-1]);
                res=max(res,grid[i][j+1]);
                res=max(res,grid[i-1][j-1]);
                res=max(res,grid[i-1][j+1]);
                res=max(res,grid[i+1][j-1]);
                res=max(res,grid[i+1][j+1]);
                ans[i-1][j-1]=res;
            }
        }
        return ans;
    }
};