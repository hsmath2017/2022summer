#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        int m=s.length(),dp[m];
        memset(dp,-1,sizeof(dp));
        function<int(int,bool,bool)> dfs=[&](int i,bool isLimit,bool isNum)->int{
            if(i==m){
                return isNum;
            }
            if(!isLimit&&isNum&&dp[i]>=0){
                return dp[i];
            }
            int res=0;
            if(!isNum){
                res=dfs(i+1,false,false);
            }
            char upper_bound=isLimit?s[i]:'9';
            for(auto c:digits){
                char myid=c[0];
                if(myid>upper_bound){
                    break;
                }
                else if(myid==upper_bound&&isLimit){
                    res+=dfs(i+1,true,true);
                }else{
                    res+=dfs(i+1,false,true);
                }
            }
            if(!isLimit&&isNum){
                dp[i]=res;
            }
            return res;
        };
        return dfs(0,true,false);
    }
};