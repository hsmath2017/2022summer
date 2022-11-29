#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int infty=1e9+7;
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[m-1][n-1]=grid[m-1][n-1];
        function<int(int,int)> dfs=[&](int row,int column)->int{
            if(row>=m||column>=n){
                return infty;
            }
            if(dp[row][column]!=-1){
                return dp[row][column];
            }
            int x=dfs(row+1,column);
            int y=dfs(row,column+1);
            int m=min(x,y);
            dp[row][column]=m+grid[row][column];
            return dp[row][column];
        };
        return dfs(0,0);
    }
};