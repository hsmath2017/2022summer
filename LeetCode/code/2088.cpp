#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int count(const vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=grid[i][j];
            }
        }
        for(int i=m-2;i>=0;i--){
            for(int j=1;j<n-1;j++){
                dp[i][j]=min((dp[i+1][j-1]+1,dp[i+1][j]+1),dp[i+1][j+1]+1);
            }
        }
        int ans=0;
        for(auto v:dp){
            for(auto x:v){
                ans=ans+(x-1);
            }
        }
        return ans;
    }
    int countPyramids(vector<vector<int>>& grid) {
        int ans=0;
        ans=ans+count(grid);
        vector<vector<int>> reversegrid(grid);
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                reversegrid[i][j]=grid[m-1-i][j];
            }
        }
        ans=ans+count(reversegrid);
        return ans;
    }
};