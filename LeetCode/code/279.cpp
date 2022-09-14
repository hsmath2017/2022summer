#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int INF=1e6;
    int memorized_dfs(int x,vector<int>& dp){
        int d=sqrt(x);
        if(d*d==x){
            dp[x]=1;
            return 1;
        }
        for(int j=d;j>=1;j--){
            int lambda=x-j*j;
            if(dp[lambda]!=INF){
                dp[x]=min(dp[x],dp[lambda]+1);
            }else{
                dp[x]=min(memorized_dfs(lambda,dp)+1,dp[x]);
            }   
        }
        return dp[x];
    }
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(auto& c:dp){
            c=INF;
        }
        memorized_dfs(n,dp);
        return dp[n];
    }
};