#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> presum(n);
        for(int i=0;i<n;i++){
            int s=0;
            for(auto c:piles[i]){
                s+=c;
                presum[i].push_back(s);
            }
        }
        vector<vector<int>> dp(n,vector<int>(k+1));
        //initialize
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=k;j++){
            int sz=presum[0].size();
            dp[0][j]=presum[0][min(j,sz-1)];
        }
        //dynamic programming
        for(int i=1;i<n;i++){
            int sz=presum[i].size();
            for(int j=1;j<=k;j++){
                int m=0;
                for(int l=0;l<=min(sz-1,j-1);l++){
                    m=max(m,presum[i][l]+dp[i-1][j-l-1]);
                }
                dp[i][j]=m;
            }
        }
        return dp[n-1][k];
    }
};