#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> monostack;
        int n=arr.size();
        vector<int> nextSmaller(n,n);
        vector<int> prevSmaller(n,-1);
        for(int i=n-1;i>=0;i++){
            while(!monostack.empty()&&arr[i]<=arr[monostack.top()]){
                prevSmaller[monostack.top()]=i;
                monostack.pop();
            }
            monostack.push(i);
        }
        while(!monostack.empty()){
            monostack.pop();
        }
        for(int i=0;i<n;i++){
            while(!monostack.empty()&&arr[i]<arr[monostack.top()]){
                nextSmaller[monostack.top()]=i;
                monostack.pop();
            }
            monostack.push(i);
        }
        using ll=long long;
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=ans+arr[i]%mod*(ll)(nextSmaller[i]-i)*(ll)(i-prevSmaller[i])%mod;
            ans=ans%mod;
        }
        return ans;
    }
};