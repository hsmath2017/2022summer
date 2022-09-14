#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSpecialNumbers(int n) {
        auto s = to_string(n);
        int m = s.length(), dp[m][1 << 10];
        memset(dp,-1,sizeof(dp));
        function<int(int,int,bool,bool)> dfs=[&](int i,int mask,bool isLimit,bool isNum)->int{
            if(i==m){
                return isNum;
            }
            if(!isLimit&&isNum&&dp[i][mask]>=0){
                return dp[i][mask];
            }
            int res=0;
            if(!isNum){
                res=dfs(i+1,mask,false,false);
            }
            int upper_bound=isLimit?s[i]-'0':9;
            for(int d=1-isNum;d<=upper_bound;d++){
                if(((mask>>d)&1)==0){
                    res+=dfs(i+1,mask|(1<<d),isLimit&&(upper_bound==d),true);
                }
            }
            if(!isLimit&&isNum){
                dp[i][mask]=res;
            }
            return res;
        };
        return dfs(0,0,true,false);
    }
};