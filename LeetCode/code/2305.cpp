#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<vector<int>> dp(k,vector<int>(1<<n));
        vector<int> sum(1<<n);
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    sum[i]+=cookies[j];
                }
            }
        }
        dp[0]=sum;
        for(int i=1;i<k;i++){
            for(int j=0;j<(1<<n);j++){
                dp[i][j]=1e9;
                for(int s=j;s;s=((s-1)&j)){
                    dp[i][j]=min(dp[i][j],max(dp[i-1][j^s],sum[s]));
                }
            }
        }
        return dp[k-1][(1<<n)-1];
    }
};