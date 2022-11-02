#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<vector<ll>> dp(m,vector<ll>(n));
        for(int i=0;i<n;i++){
            dp[0][i]=points[0][i];
        }
        for(int i=1;i<m;i++){
            vector<ll> maxL(n);
            vector<ll> maxR(n);
            for(int j=0;j<n;j++){
                if(j==0){
                    maxL[j]=dp[i-1][j];
                }else{
                    maxL[j]=max(maxL[j-1],dp[i-1][j]+j);
                }
            }
            for(int j=n-1;j>=0;j--){
                if(j==n-1){
                    maxR[j]=dp[i-1][j]-j;
                }else{
                    maxR[j]=max(maxR[j+1],dp[i-1][j]-j);
                }
            }
            for(int j=0;j<n;j++){
                dp[i][j]=max((ll)points[i][j]-(ll)j+maxL[j],(ll)points[i][j]+(ll)j+maxR[j]);
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[m-1][i]);
        }
        return ans;
    }
};