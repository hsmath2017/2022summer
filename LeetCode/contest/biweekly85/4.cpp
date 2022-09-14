#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        vector<ll> psum;
        set<ll> numsets;
        psum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            psum[i]=psum[i-1]+nums[i];
        }
    }
};