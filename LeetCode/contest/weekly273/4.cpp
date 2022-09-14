#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int,int> num_times;
    bool check(const vector<int>& nums,int k){
        map<int,int> tmp(num_times);
        for(auto c:nums){
            if(tmp[c]){
                tmp[c]--;
                if(tmp[c+2*k]==0){
                    return false;
                }else{
                    tmp[c+2*k]--;
                }
            }
        }
        return true;
    }
    vector<int> recoverArray(vector<int>& nums) {
        vector<int> possible_k;
        sort(nums.begin(),nums.end());
        num_times[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            num_times[nums[i]]++;
            if((nums[i]-nums[0])%2==0&&nums[i]!=nums[0]){
                possible_k.push_back((nums[i]-nums[0])/2);
            }
        }
        int k;
        for(auto c:possible_k){
            if(check(nums,c)){
                k=c;
                break;
            }
        }
        cout<<k<<endl;
        vector<int> ans;
        for(auto c:nums){
            if(num_times[c]){
                ans.push_back(c);
                num_times[c]--;
                num_times[c+2*k]--;
            }
        }
        for(auto& c:ans){
            c+=k;
        }
        return ans;
    }
};
