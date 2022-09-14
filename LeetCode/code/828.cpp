#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.length();
        vector<int> dp(n);
        dp[0]=1;
        map<char,vector<int>> pos;
        pos[s[0]].push_back(0);
        for(int i=1;i<n;i++){
            char c=s[i];
            int first;
            int second;
            auto vec=pos[c];
            if(vec.size()==0){
                first=second=-1;
                pos[c].push_back(i);
            }
            else if(vec.size()==1){
                first=vec[0];
                second=-1;
                pos[c].push_back(i);
                swap(pos[c][0],pos[c][1]);
            }else{
                first=vec[1];
                second=vec[0];
                pos[c][0]=first;
                pos[c][1]=i;
            }
            dp[i]=dp[i-1]+(i-first)-(first-second);
        } 
        int ans=0;
        for(auto c:dp){
            ans+=c;
        }
        return ans;
    }
};