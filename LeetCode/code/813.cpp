#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const double inf=1e15;
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<double>> dp(n,vector<double>(k,0));
        long long s=0;
        for(int i=0;i<n;i++){
            s=s+nums[i];
            dp[i][0]=1.0*s/(i+1);
        }
        for(int i=1;i<k;i++){
            for(int j=i;j<n;j++){
                long long tmp=0;
                for(int l=j;l>0;l--){
                    tmp=tmp+nums[l];
                    double res=1.0*tmp/(j-l+1);
                    dp[j][i]=max(dp[j][i],dp[l-1][i-1]+res);
                }
            }
        }
        return dp[n-1][k-1];
    }
};