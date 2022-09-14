#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int _or=0;
            int j=i;
            while(j<n&&(nums[j]&_or)==0){
                _or=nums[j]|_or;
                j++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};