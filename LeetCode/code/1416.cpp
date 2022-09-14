#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> dp;
    int size;
    const int MOD=1e9+7;
    int upper_bound;
public:
    int dfs(int index,const string& s){
        if(index==size){
            return 1;
        }
        if(dp[index]!=0){
            return dp[index];
        }
        int nowidx=index;
        int ans=0;
        long tmp=0;
        while(index<size){
            tmp=tmp*10+(long)(s[index]-'0');
            if(1<=tmp&&tmp<=upper_bound){
                ans=ans+dfs(index+1,s);
                ans=ans%MOD;
                index++;
            }else{
                break;
            }
        }
        dp[nowidx]=ans;
        return ans;
    }
    int numberOfArrays(string s, int k) {
        upper_bound=k;
        size=s.length();
        dp.resize(size+1);
        int x=dfs(0,s);
        //upper_bound=k;
        return x%MOD;
    }
};