#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string ans=s;
        int n=s.length();
        for(int i=0;i<n;i++){
            string tmp=s.substr(1);
            tmp.push_back(s[0]);
            s=tmp;
            ans=min(ans,tmp);
        }
        return ans;
    }
};