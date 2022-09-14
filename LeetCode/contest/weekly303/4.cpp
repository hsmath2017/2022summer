#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    ll getones(int x){
        ll res=0;
        while(x){
            if(x%2){
                res++;
            }
            x/=2;
        }
        return res;
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
        map<int,ll> ones;
        vector<int> complicated;
        map<int,int> avail;
        vector<int> except_complicated;
        ll res=0;
        for(auto c:nums){
            ones[c]=getones(c);
            if(avail[c]==0){
                avail[c]=1;
                except_complicated.push_back(c);
            }else if(avail[c]==1){
                complicated.push_back(c);
                avail[c]=2;
            }else{
                continue;
            }
        }
        for(auto x:complicated){
            if(2*ones[x]>=k){
                res++;
            }
        }
        map<int,ll> nums_greater_than_k;
        ll n=except_complicated.size();
        for(int i=1;i<=k;i++){
            for(auto c:except_complicated){
                if(ones[c]>=i){
                    nums_greater_than_k[i]++;
                }
            }
        }
        for(auto c:except_complicated){
            if(nums[c]>=k){
                res=res+n;
            }else{
                res=res+nums_greater_than_k[k-nums[c]];
            }
        }
        return res;
    }
};