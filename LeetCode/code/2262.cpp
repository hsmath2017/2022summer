#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    long long appealSum(string s) {
        vector<ll> dp;
        int len=s.length();
        dp.resize(len);
        map<char,int> char2minindex;
        dp[0]=1;
        char2minindex[s[0]]=0;
        for(int i=1;i<len;i++){
            char c=s[i];
            if(char2minindex.count(c)==false){
                char2minindex[c]=i;
                dp[i]=dp[i-1]+i+1;
            }else{
                dp[i]=dp[i-1]+i-char2minindex[c];
                char2minindex[c]=i;
            }
        }
        ll ans=0;
        for(auto x:dp){
            ans+=x;
        }
        return ans;
    }
};