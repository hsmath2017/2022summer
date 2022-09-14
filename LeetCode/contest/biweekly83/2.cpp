#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        using ll=long long;
        ll res=0;
        int tmp=0;
        for(auto d:nums){
            if(d==0){
                tmp++;
            }else{
                res=res+(tmp*(tmp+1))/2;
                tmp=0;
            }
        }
        res=res+tmp*(tmp+1)/2;
        return res;
    }
};