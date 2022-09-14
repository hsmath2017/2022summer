#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> max_index;
        for(int i=0;i<k;i++){
            max_index.push_back(i);
            while(!max_index.empty()){
                int d=max_index.back();
                if(nums[i]>nums[d]){
                    max_index.pop_back();
                }
            }
            //max_index.push_back(i);
        }
        ans.push_back(nums[max_index.front()]);
        for(int i=k;i<nums.size();i++){
            max_index.push_back(i);
            while(!max_index.empty()){
                int d=max_index.back();
                if(nums[i]>nums[d]){
                    max_index.pop_back();
                }
            }
            while(!max_index.empty()&&max_index.front()<=i-k){
                max_index.pop_front();
            }
            ans.push_back(nums[max_index.front()]);
        }
        return ans;
    }
};