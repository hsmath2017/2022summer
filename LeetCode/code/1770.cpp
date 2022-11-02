#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size();
        int m=multipliers.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1));
        dp[0][0]=0;
        for(int i=1;i<=m;i++){
            dp[i][0]=dp[i-1][0]+nums[i-1]*multipliers[i-1];
            dp[0][i]=dp[0][i-1]+nums[n-i]*multipliers[m-i];
        }
        for(int i=1;i<m;i++){
            for(int j=1;i+j<=m;j++){
                dp[i][j]=max(dp[i-1][j]+nums[i-1]*multipliers[i+j-1],dp[i][j-1]+nums[n-j]*multipliers[m-i-j]);
            }
        }
        int ans=0;
        for(int i=0;i<=m;i++){
            ans=max(ans,dp[i][m-i]);
        }
        return ans;
    }
};