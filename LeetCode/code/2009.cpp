#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> except_multiple;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                except_multiple.push_back(nums[i]);
                continue;
            }
            if(nums[i]==nums[i-1]){
                continue;
            }
            except_multiple.push_back(nums[i]);
        }
        int ans=0;
        int left=0;
        int right=0;
        int n=except_multiple.size();
        while(right<n){
            while(nums[right]-nums[left]>=n){
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return n-ans;
    }
};