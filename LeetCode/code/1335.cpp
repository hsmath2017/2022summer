#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n){
            return -1;
        }
        //预处理最大值
        vector<vector<int>> partial_max(n,vector<int>(n));
        for(int i=0;i<n;i++){
            int ans=0;
            for(int j=i;j<n;j++){
                ans=max(jobDifficulty[j],ans);
                partial_max[i][j]=ans;
            }
        }
        //DP
        vector<vector<int>> dp(n,vector<int>(d));
        for(int i=0;i<n;i++){
            for(int j=0;j<d;j++){
                dp[i][j]=1e9;
            }
        }
        for(int i=0;i<n;i++){
            dp[i][0]=partial_max[0][i];
        }
        for(int j=1;j<d;j++){
            for(int i=j;i<n;i++){
                int ans=1e9;
                for(int k=1;k<=i;k++){
                    ans=min(ans,dp[i-k][j-1]+partial_max[i-k+1][i]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[n-1][d-1];
    }
};