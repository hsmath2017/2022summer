#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD=1e9+7;
    int countSpecialSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(3));
        dp[0][0]=(nums[0]==0);
        dp[0][1]=dp[0][2]=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=0){
                dp[i][0]=dp[i-1][0];
            }else{
                dp[i][0]=(1+2*dp[i-1][0])%MOD;
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i]!=1){
                dp[i][1]=dp[i-1][1];
            }else{
                dp[i][1]=(2*dp[i-1][1]%MOD+dp[i-1][0]%MOD)%MOD;
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i]!=2){
                dp[i][2]=dp[i-1][2];
            }else{
                dp[i][2]=(2*dp[i-1][2]+dp[i-1][1])%MOD;
            }
        }
        return dp[n-1][2];
    }
};