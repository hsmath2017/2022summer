#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(const vector<int>& nums,const int maxOperations,int cost){
        int op=0;
        for(auto c:nums){
            op=op+(c-1)/cost;
        }
        if(op<=maxOperations){
            return true;
        }else{
            return false;
        }
    }
    int binary_find(const vector<int>& nums,int left,int right,const int maxOperations){
        if(left==right){
            return left;
        }
        int mid=(left+right)/2;
        if(check(nums,maxOperations,mid)==true){
            return binary_find(nums,left,mid,maxOperations);
        }else{
            return binary_find(nums,mid+1,right,maxOperations);
        }
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int max=0;
        for(auto c:nums){
            if(c>max){
                max=c;
            }
        }
        int left=1;
        int ans=binary_find(nums,left,max,maxOperations);
        return ans;
    }
};