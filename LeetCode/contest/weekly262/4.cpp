#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        n/=2;
        vector<vector<int>>s(n+1);
        
        int res = INT_MAX;
        for(int i=0; i<1<<n; i++){
            int sum = 0, cnt = 0;
            for(int j=0; j<n; j++){
                if(i>>j&1){
                    sum+=nums[j];
                    cnt++;
                }else {
                    sum-=nums[j];
                }
            }
            s[cnt].push_back(sum);
        }
        
        for(int i=0; i<s.size(); i++)sort(s[i].begin(), s[i].end());

        for(int i=0; i<1<<n; i++){
            int sum = 0, cnt = 0;
            for(int j = 0; j < n; j++){
                if(i>>j&1){
                    sum+=nums[n+j];
                    cnt++;
                }else {
                    sum-=nums[n+j];
                }
            }
            // 这里有cnt个正号，要到前面取n-cnt个正号的数组匹配 
            // 要使A+B最小，则A <= -B,二分查找到边界左右的值，即使答案。  
            int l = 0, r = s[n-cnt].size()-1;
            while(l<r){
                int mid = l+r+1>>1;
                if(s[n-cnt][mid] <= -sum )l=mid;
                else r = mid-1;
            }
            res = min(res, abs(sum + s[n-cnt][l]));
            if(r<s[n-cnt].size()-1)res = min(res, abs(sum + s[n-cnt][r+1]));
        }
        return res;
    }
};