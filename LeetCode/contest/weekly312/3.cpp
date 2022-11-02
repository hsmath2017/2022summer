#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        deque<int> dq;
        map<int,bool> frontdecrease;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(dq.empty()==true){
                dq.push_back(i);
                continue;
            }
            if(dq.size()==k){
                frontdecrease[i]=true;
                dq.pop_front();
            }
            if(!dq.empty()){
                int back=dq.back();
                if(nums[i]<=nums[back]){
                    dq.push_back(i);
                }else{
                    dq.clear();
                    dq.push_back(i);
                }
            }else{
                dq.push_back(i);
            }
        }
        vector<int> ans;
        dq.clear();
        for(int j=n-1;j>=0;j--){
            if(dq.empty()==true){
                dq.push_back(j);
                continue;
            }
            if(dq.size()==k){
                if(frontdecrease[j]){
                    ans.push_back(j);
                }
                dq.pop_front();
            }
            if(!dq.empty()){
                int back=dq.back();
                if(nums[j]<=nums[back]){
                    dq.push_back(j);
                }else{
                    dq.clear();
                    dq.push_back(j);
                }
            }else{
                dq.push_back(j);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};