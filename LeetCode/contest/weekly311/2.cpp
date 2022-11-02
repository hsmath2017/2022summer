#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=1;
        char c=s[0];
        int tmp=1;
        for(int i=1;i<s.length();i++){
            if(s[i]-c==1){
                tmp++;
            }else{
                ans=max(ans,tmp);
                tmp=1;
            }
            c=s[i];
        }
        ans=max(ans,tmp);
        return ans;
    }
};