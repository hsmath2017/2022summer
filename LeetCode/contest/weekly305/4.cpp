#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp;
        int n=s.length();
        map<char,int> M;
        for(auto c='a';c<='z';c++){
            M[c]=-1;
        }
        dp.resize(n);
        dp[0]=1;
        M[s[0]]=0;
        for(int i=1;i<n;i++){
            char c=s[i];
            int res=1;
            char left,right;
            if(c-k<'a'){
                left='a';
            }else{
                left=c-k;
            }
            if(c+k>'z'){
                right='z';
            }else{
                right=c+k;
            }
            for(char l=left;l<=right;l++){
                if(M[l]!=-1){
                    res=max(res,dp[M[l]]+1);
                }
            }
            M[c]=i;
            dp[i]=res;
        }
        int ans=1;
        for(auto c:dp){
            if(c>ans){
                ans=c;
            }
        }
        return ans;
    }
};