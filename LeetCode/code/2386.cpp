#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    using pli=pair<ll,int>;
    long long kSum(vector<int>& nums, int k) {
        ll sum=0;
        int n=nums.size();
        for(auto& v:nums){
            if(v>0){
                sum+=v;
            }else{
                v=-v;
            }
        }
        pli p{sum,0};
        sort(nums.begin(),nums.end());
        priority_queue<pli> pq;
        pq.emplace(p);
        while(--k){
            pli tmp=pq.top();
            pq.pop();
            if(tmp.second<nums.size()){
            pli getelement{tmp.first-nums[tmp.second] ,tmp.second+1};
            pq.push(getelement);
            if(tmp.second){
                pli withoutelement{tmp.first-nums[tmp.second]+nums[tmp.second-1],tmp.second+1};
                pq.push(withoutelement);
            }
            }
        }
        auto pi=pq.top();
        return pi.first;
    }
};