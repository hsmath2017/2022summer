#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void removezero(vector<int>& nums){
        vector<int> tmp;
        for(auto c:nums){
            if(c){
                tmp.push_back(c);
            }
        }
        nums=tmp;
    }
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        removezero(nums);
        int opera=0;
        while (nums.size())
        {
            opera++;
            int c=nums[0];
            for(int i=0;i<nums.size();i++){
                nums[i]=nums[i]-c;
            }
            removezero(nums);
        }
        return opera;
    }
};