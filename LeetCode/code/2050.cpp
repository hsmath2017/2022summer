#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> dp(n+1);
        queue<int> toporder;
        vector<int> indegree(n+1);
        vector<vector<int>> graph(n+1);
        for(auto r:relations){
            graph[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }
        for(int i=1;i<=n;i++){
            dp[i]=time[i];
        }
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                toporder.push(i);
            }
        }
        while(!toporder.empty()){
            int c=toporder.front();
            for(auto v:graph[c]){
                indegree[v]--;
                if(!indegree[v]){
                    toporder.push(v);
                }
                dp[v]=max(dp[v],time[v]+dp[c]);
            }
            toporder.pop();
        }
        int ans=0;
        for(auto v:dp){
            ans=max(ans,v);
        }
        return ans;
    }
};