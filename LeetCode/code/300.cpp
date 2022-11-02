#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binary_find(int target,const vector<int>& ans,int left,int right){
        if(left==right){
            return left;
        }
        int mid=(left+right)/2;
        if(ans[mid]>=target){
            return binary_find(target,ans,left,mid);
        }else{
            return binary_find(target,ans,mid+1,right);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(auto c:nums){
            if(ans.size()==0){
                ans.push_back(c);
                continue;
            }
            int d=*(ans.end()-1);
            if(c>d){
                ans.push_back(c);
            }else{
                int index=binary_find(c,ans,0,ans.size()-1);
                ans[index]=c;
            }
        }
        return ans.size();
    }
};