#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<vector<int>> nums_new;
        for(int i=0;i<nums.size();i++){
            nums_new.push_back({nums[i],i});
        }
        auto cmp1=[](const vector<int>& v1,const vector<int>& v2){
            return v1[0]>v2[0];
        };
        auto cmp2=[](const vector<int>& v1,const vector<int>& v2){
            return v1[1]<v2[1];
        };
        sort(nums_new.begin(),nums_new.end(),cmp1);
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(nums_new[i]);
        }
        sort(ans.begin(),ans.end(),cmp2);
        vector<int> res;
        for(auto v:ans){
            res.push_back(v[0]);
        }
        return res;
    }
};