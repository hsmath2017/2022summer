#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD=1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k)));
        dp[0][0][grid[0][0]%k]=1;
        for(int j=1;j<n;j++){
            for(int l=0;l<k;l++){
                int t=((l-grid[0][j])%k+k)%k;
                dp[0][j][l]=dp[0][j-1][t];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<k;l++){
                    int t=((l-grid[i][j])%k+k)%k;
                    if(j==0){
                        dp[i][j][l]=(dp[i-1][j][t])%MOD;
                    }else{
                        dp[i][j][l]=(dp[i-1][j][t]+dp[i][j-1][t])%MOD;
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};