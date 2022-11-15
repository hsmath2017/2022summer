#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size()+1;
        int x=0;
        for(int i=1;i<=n;i++){
            x=x^i;
        }
        int a0=x;
        for(int i=1;i<n-1;i=i+2){
            a0=a0^encoded[i];
        }
        vector<int> ans;
        ans.push_back(a0);
        vector<int> prexor;
        int now=encoded[0];
        prexor.push_back(now);
        for(int i=1;i<n-1;i++){
            now=now^encoded[i];
            prexor.push_back(now);
        }
        for(auto x:prexor){
            int tmp=a0^x;
            ans.push_back(tmp);
        }
        return ans;
    }
};