#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]-i;
        }
        map<int,int> times;
        for(auto v:nums){
            times[v]++;
        }
        long long good_pairs=0;
        for(auto it:times){
            long long n=it.second;
            good_pairs=good_pairs+(n*(n-1))/2;
        }
        long long t=nums.size();
        long long ans=t*(t-1)/2-good_pairs;
        return ans;
    }
};