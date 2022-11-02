#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod=1e9+7;
    int waysToSplit(vector<int>& nums) {
        vector<int> presum;
        int s=0;
        for(auto c:nums){
            presum.push_back(s);
            s+=c;
        }
        int n=nums.size();
        int ans=0;
        for(int i=1,j=2,k=2;i<n-1&&presum[i]*3<=presum[n];i++){
            int left=presum[i];
            j=max(i+1,j);
            while(j<n-1&&presum[j]-presum[i]<left){
                j++;
            }
            while(k<n-1&&presum[k+1]-presum[i]<=presum[n]-presum[k+1]){
                k++;
            }
            ans=ans+(k-j+1);
            ans=ans%mod;
        }
        return ans;
    }
};