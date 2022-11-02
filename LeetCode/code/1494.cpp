#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> dp(1<<n,16);
        dp[0]=0;
        vector<int> pre_requesites(n);
        for(auto rel:relations){
            pre_requesites[rel[1]-1]=pre_requesites[rel[1]-1]|(1<<(rel[0]-1));
        }
        int total_state=1<<n;
        vector<int> cnt(total_state);
        cnt[0] = 0;
        // 小技巧，计算每个数字的二进制数中，1的个数
        for (int i = 1; i < total_state; ++i) {
            cnt[i] = cnt[i>>1] + (i&1);
        }
        for(int taken=0;taken<total_state;taken++){
            if(dp[taken]>n){
                continue;
            }
            int curr=0;//能修的课程,用一个数字表示
            for(int j=0;j<n;j++){
                if(((taken&(1<<j))==0)&&((pre_requesites[j]&taken)==pre_requesites[j])){
                    curr=curr|(1<<j);
                }
            }
            //枚举curr子集
            for(int subMask=curr;subMask>0;subMask=(subMask-1)&curr){
                if(cnt[subMask]<=k){
                    dp[taken|subMask]=min(dp[taken|subMask],dp[taken]+1);
                }
            }
        }
        return dp[total_state-1];
    }
};