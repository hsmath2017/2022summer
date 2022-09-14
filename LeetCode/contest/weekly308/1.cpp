#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(const vector<int>& nums,int target){
        int res=0;
        int sum=0;
        while(sum<=target&&res<nums.size()){
            sum+=nums[res];
            res++;
        }
        if(sum>target){
            res--;
        }
        return res;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(auto d:queries){
            int x=check(nums,d);
            ans.push_back(x);
        }
        return ans;
    }
};