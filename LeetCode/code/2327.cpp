#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> s;
        s.resize(n+1);
        s[0]=0;
        s[1]=1;
        for(int i=2;i<=n;i++){
            int a=max(i-delay,0);
            int b=max(i-forget,0);
            int delta=s[a]-s[b];
            s[i]=(s[i-1]+delta+MOD)%MOD;
        }
        return (s[n]-s[max(n-forget,0)]+MOD)%MOD;
    }
};