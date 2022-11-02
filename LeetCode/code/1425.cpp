#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp;
        multiset<int,std::greater<int>> window;
        int n=nums.size();
        dp.resize(n);
        dp[0]=nums[0];
        window.insert(dp[0]);
        for(int i=1;i<=k;i++){
            if(i<n){
                int m=max(*window.begin(),0);
                dp[i]=m+nums[i];
                window.insert(dp[i]);
            }
        }
        for(int i=k+1;i<n;i++){
            window.erase(dp[i-k-1]);
            int m=max(*window.begin(),0);
            dp[i]=m+nums[i];
            window.insert(dp[i]);
        }
        int ans=-1e5;
        for(auto c:dp){
            if(c>ans){
                ans=c;
            }
        }
        return ans;
    }
};