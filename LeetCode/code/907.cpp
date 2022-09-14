#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> monostack;
        int n=arr.size();
        vector<int> nextSmaller(n,n);
        vector<int> prevSmaller(n,-1);
        for(int i=0;i<n;i++){
            while(!monostack.empty()&&arr[monostack.top()]>arr[i]){
                nextSmaller[monostack.top()]=i;
                monostack.pop();
            }
            monostack.push(i);
        }
        while(!monostack.empty()){
            monostack.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!monostack.empty()&&arr[monostack.top()]>=arr[i]){
                prevSmaller[monostack.top()]=i;
                monostack.pop();
            }
            monostack.push(i);
        }
        long ret = 0;
        long M = 1e9 + 7;
        // 再扫一遍，每个元素左右边界
        for (int i = 0; i < n; ++i)
        {
            int a = prevSmaller[i];
            /*
            2 8 5 6 5 [7 5 5 5 5 6] 2
                         ^
                    a    i          b
            */
            int b = nextSmaller[i];
            long num = arr[i] % M * (i - a) * (b - i) % M; // subarray个数，数字太大，取余
            ret = (ret + num) % M;
        }
        return ret;
    }
};