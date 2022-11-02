#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int max=INT_MAX;
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int maxsize=1<<n;
        vector<int> dp(maxsize);
        dp[0]=0;
        vector<int> ones(maxsize);
        for(int mask=1;mask<maxsize;mask++){
            ones[mask]=mask%2+ones[mask>>1];
        }
        for(int mask=1;mask<maxsize;mask++){
            int tmp=max;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    tmp=min(tmp,dp[mask^(1<<i)]+(nums2[i]^nums1[ones[mask]-1]));
                }
            }
            dp[mask]=tmp;
        }
        /*
        for(auto c:dp){
            cout<<c<<endl;
        }
        */
        return dp[maxsize-1];
    }
};