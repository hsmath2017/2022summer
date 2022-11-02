#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deleteString(string s) {
        vector<int> dp;
        int n=s.length();
        dp.resize(n);
        dp[n-1]=1;
        int lcp[n + 1][n + 1]; // lcp[i][j] 表示 s[i:] 和 s[j:] 的最长公共前缀
        memset(lcp, 0, sizeof(lcp));
        for (int i = n - 1; i >= 0; --i)
            for (int j = n - 1; j > i; --j)
                if (s[i] == s[j])
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
        for(int i=n-2;i>=0;i--){
            int partialLen=n-i;
            int maxsubseqLen=partialLen/2;
            int ans=1;
            for(int j=1;j<=maxsubseqLen;j++){
                if(lcp[i][i+j]>=j){
                    ans=max(ans,1+dp[i+j]);
                }
            }
            dp[i]=ans;
        }        
        return dp[0];
    }
};