#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    using pll=pair<ll,ll>;
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pll> cmps;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cmps.push_back(make_pair(nums[i],cost[i]));
        }
        sort(cmps.begin(),cmps.end());
        vector<ll> presum;
        ll s=0;
        for(auto it:cmps){
            s+=it.second;
            presum.push_back(s);
        }
        int targetind;
        for(int i=0;i<n;i++){
            if(presum[i]>=presum[n-1]-presum[i]){
                targetind=i;
                break;
            }
        }
        ll ans=0;
        for(auto it:cmps){
            ans=ans+abs((it.first-cmps[targetind].first)*it.second);
        }
        return ans;
    }
};