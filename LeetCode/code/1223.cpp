#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const long long MOD=1e9+7;
    using ll=long long;
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<ll>> dp;
        dp.resize(n);
        for(int i=0;i<n;i++){
            dp[i].resize(7);
        }
        for(int i=1;i<=6;i++){
            dp[0][6]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=6;j++){
                for(int k=1;k<=6;k++){
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
                }
                if(i-rollMax[j]>=0){
                    dp[i][j]=(MOD+dp[i][j]-dp[i-rollMax[j]][j])%MOD;
                }
            }
        }
        int ans=0;
        for(auto c:dp[n-1]){
            ans=(ans+c)%MOD;
        }
        return ans;
    }
};