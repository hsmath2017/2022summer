#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime){
        int n=tasks.size();
        int m=1<<n;
        vector<int> dp(m,n);
        vector<int> sum(m);
        for(int i=0;i<m;i++){
            int tmp=i;
            int s=0;
            int j=0;
            while(tmp){
                if(tmp&1){
                    s+=tasks[j];
                }
                tmp=(tmp>>1);
                j++;
            }
            sum[tmp]=s;
        }
        dp[0]=0;
        for(int i=1;i<m;i++){
            for(int j=0;j<=i;j++){
                if(sum[j]<=sessionTime){
                    dp[i]=min(dp[i],dp[i^j]+1);
                }
            }
        }
        return dp[m-1];
    }
};