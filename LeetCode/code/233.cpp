#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDigitOne(int n) {
        auto s=to_string(n);
        int m=s.length(),dp[m];
        memset(dp,-1,sizeof(dp));
        function<int(int,int,bool,bool)> dfs=[&](int i,int cnt1,bool isLimit,bool isNum)->int{
            if(i==m){
                if(!isNum){
                    return 0;
                }
                return cnt1;
            }
            if(!isLimit&&isNum&&dp[i]>=0){
                return dp[i];
            }
            int res=0;
            if(!isNum){
                res=dfs(i+1,cnt1,false,false);
            }
            int upper_bound=isLimit?s[i]-'0':9;
            for(int d=1-isNum;d<=upper_bound;d++){
                if(d==1){
                    res+=dfs(i+1,cnt1+1,isLimit&&(d==upper_bound),true);
                }
            }
            if(!isLimit&&isNum){
                dp[i]=res;
            }
            return res;
        };
        return dfs(0,0,true,false);
    }
};