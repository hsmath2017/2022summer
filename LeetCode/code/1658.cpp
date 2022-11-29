#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(auto c:nums){
            sum+=c;
        }
        if(sum<x){
            return -1;
        }
        int left=0;
        int right=0;
        int target=sum-x;
        int ans=-1;
        int total=0;
        while(right<nums.size()){
            total=total+nums[right];
            while(total>target){
                total-=nums[left];
                left++;
            }          
            if(total==target){
                ans=max(ans,right-left+1);
            }  
            right++;
        }
        return ans;
    }
};