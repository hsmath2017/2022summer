#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    ll ans=0;
    void handle(vector<int>& nums,vector<int>& target){
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end()); 
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[i]-target[i])/2;
        }
    }
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> oddnums;
        vector<int> oddtarget;
        vector<int> evennums;
        vector<int> eventarget;
        for(auto c:nums){
            if(c%2){
                oddnums.push_back(c);
            }else{
                evennums.push_back(c);
            }
        }
        for(auto c:target){
            if(c%2){
                oddtarget.push_back(c);
            }else{
                eventarget.push_back(c);
            }
        }
        handle(oddnums,oddtarget);
        handle(evennums,eventarget);
        ans=ans/2;
        return ans;
    }   
};