#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int MOD=1e9+7;
    vector<vector<int>> DP;
public:
    int dfs(int now,int len,int maxValue){
        if(DP[len][now]!=-1){
            return DP[len][now];
        }
        if(now>maxValue/2){
            return 1;
        }
        if(len==0){
            return DP[len][now]=1;
        }
        int val=0;
        for(int i=0;;i++){
            if(now*i>maxValue){
                break;
            }
            val=val+dfs(now*i,len-1,maxValue);
            val=val%MOD;
        }
        return DP[len][now]=val;
    }
    int idealArrays(int n, int maxValue) {
        DP.resize(n);
        for(int i=0;i<n;i++){
            //DP[i].resize(maxValue/2);
            for(int j=0;j<=maxValue/2;j++){
                DP[i].push_back(-1);
            }
        }
        int res=0;
        for(int k=1;k<=maxValue/2;k++){
            res+=dfs(k,n-1,maxValue);
            res=res%MOD;
        }
        res+=(maxValue-maxValue/2);
        res=res%MOD;
        return res;
    }
};