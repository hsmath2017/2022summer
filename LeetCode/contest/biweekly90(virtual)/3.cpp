#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int,int> appeartimes;
        for(auto c:nums){
            appeartimes[c%space]++;
        }
        int ans=0;
        set<int> mod;
        for(auto it:appeartimes){
            if(it.second>ans){
                ans=it.second;
                mod.clear();
                mod.insert(it.first);
            }else if(it.second==ans){
                mod.insert(it.first);
            }
        }
        sort(nums.begin(),nums.end());
        for(auto c:nums){
            int m=c%space;
            if(mod.count(m)){
                ans=c;
                break;
            }
        }
        return ans;
    }
};