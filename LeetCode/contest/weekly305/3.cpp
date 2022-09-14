#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool> dp;
        int n=nums.size();
        dp.resize(n);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                int tmp=i-2;
                if(tmp<0){
                    dp[i]=true;
                    continue;
                }else{
                    dp[i]=dp[i-2];
                    if(dp[i]==true){
                        continue;
                    }
                }
            }
            if(i>=2&&nums[i]==nums[i-1]&&nums[i-1]==nums[i-2]){
                int tmp=i-3;
                if(tmp<0){
                    dp[i]=true;
                    continue;
                }else{
                    dp[i]=dp[i-3];
                    if(dp[i]==true){
                        continue;
                    }
                }
            }
            if(i>=2&&nums[i]==nums[i-1]+1&&nums[i-1]==nums[i-2]+1){
                int tmp=i-3;
                if(tmp<0){
                    dp[i]=true;
                    continue;
                }else{
                    dp[i]=dp[i-3];
                    if(dp[i]==true){
                        continue;
                    }
                }                
            }
        }
        return dp[n-1];
    }
};