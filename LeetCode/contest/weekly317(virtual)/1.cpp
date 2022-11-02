#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    int averageValue(vector<int>& nums) {
        int n=0;
        ll s=0;
        for(auto c:nums){
            if(c%6==0){
                s+=(ll)c;
                n++;
            }
        }
        if(n==0){
            return 0;
        }
        ll res=s%n;
        int ans=(s-res)/n;
        return ans;
    }
};