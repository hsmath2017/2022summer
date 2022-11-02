#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using LL=long long;
    const int mod=1e9+7;
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n), right(n, n - 1);
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&nums[i]<=nums[st.top()]){
                right[st.top()]=i-1;
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top()+1;
            }
            st.push(i);
        }
        vector<LL> pre(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        
        LL best = 0;
        for (int i = 0; i < n; ++i) {
            best = max(best, (pre[right[i] + 1] - pre[left[i]]) * nums[i]);
        }
        return best % mod;
    }
};