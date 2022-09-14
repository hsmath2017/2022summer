#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findmax(const vector<int>& arr,int fptr,int rptr){
        int M=0;
        for(int i=fptr+1;i<=rptr;i++){
            if(arr[i]>M){
                M=arr[i];
            }
        }
        return M;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n);
        int nowmax=0;
        for(int i=0;i<k;i++){
            if(arr[i]>nowmax){
                nowmax=arr[i];
            }
            dp[i]=(i+1)*nowmax;
        }
        for(int i=k;i<n;i++){
            nowmax=0;
            for(int j=1;j<=k;j++){
                int tmp=dp[i-j]+j*findmax(arr,i-j,i);
                if(tmp>nowmax){
                    nowmax=tmp;
                }
            }
            dp[i]=nowmax;
        }
        return dp[n-1];
    }
};