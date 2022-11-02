#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ans=false;
    vector<int> sum;
    void check(int start,const vector<int>& nums,int target){
        if(start==0){
            ans=true;
            return;
        }
        int tmp=start;
        for(tmp=start;tmp;tmp=(tmp-1)&start){
            if(sum[tmp]==target){
                check(start^tmp,nums,target);
            }
        }
        return;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0;
        for(auto c:nums){
            s+=c;
        }
        if(s%k){
            return false;
        }
        int target=s/k;
        int start=1<<n;
        sum.resize(start);
        for(int i=0;i<start;i++){
            for(int j=0;j<i;j++){
                if((i>>j)&1){
                    sum[i]+=nums[j];
                }
            }
        }
        check(start,nums,target);
        return ans;
    }
};