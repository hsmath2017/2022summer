#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<int> pos;
        pos.push_back(0);
        for(auto c:cuts){
            pos.push_back(c);
        }
        pos.push_back(n);
        int m=pos.size();
        vector<vector<int>> dp(m,vector<int>(m));
        for(int i=0;i<m-1;i++){
            dp[i][i+1]=pos[i+1]-pos[i];
        }
        const int MAX=1e9+7;
        for(int l=2;l<m;l++){
            for(int i=0;i+l<m;i++){
                int ans=MAX;
                for(int k=1;k<l;k++){
                    ans=min(ans,dp[i][i+k]+dp[i+k][i+l]+max(k,l-k));
                }
                dp[i][i+l]=ans;
            }
        }
        return dp[0][m-1];
    }
};