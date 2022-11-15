#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> dp(n);
        vector<vector<int>> graph(n);
        vector<int> sz(n);
        vector<int> ans(n);
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        //dfs1: root dfs from point zero
        function<void(int,int)> dfs1=[&](int rt,int fa){
            sz[rt]=1;
            dp[rt]=0;
            for(auto v:graph[rt]){
                if(v==fa){
                    continue;
                }
                dfs1(v,rt);
                sz[rt]=sz[rt]+sz[v];
                dp[rt]=dp[rt]+dp[v]+sz[v];
            }
            return;
        };
        dfs1(0,-1);
        function<void(int,int)> dfs2=[&](int rt,int fa){
            ans[rt]=dp[rt];
            for(auto v:graph[rt]){
                if(v==fa){
                    continue;
                }
                int dpu=dp[rt],szu=sz[rt],dpv=dp[v],szv=sz[v];
                dp[rt]=dp[rt]-(sz[v]+dp[v]);
                sz[rt]=sz[rt]-sz[v];
                dp[v]=dp[v]+(sz[rt]+dp[rt]);
                sz[v]=sz[v]+sz[rt];
                dfs2(v,rt);
                dp[rt]=dpu;
                sz[rt]=szu;
                dp[v]=dpv;
                sz[v]=szv;
            }
            return;
        };
        dfs2(0,-1);
        return ans;
    }
};