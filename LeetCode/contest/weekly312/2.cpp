#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m=0;
        for(auto c:nums){
            if(c>m){
                m=c;
            }
        }        
        vector<int> indexes;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==m){
                indexes.push_back(i);
            }
        }
        int ans=1;
        int tmp=1;
        for(int i=1;i<indexes.size();i++){
            if(indexes[i]==indexes[i-1]+1){
                tmp++;
            }else{
                ans=max(ans,tmp);
                tmp=1;
            }
        }
        ans=max(ans,tmp);
        return ans;
    }
};