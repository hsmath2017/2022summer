#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int node,int& ans,const vector<vector<int>>& graph,const string& s){
        int nowmax=0;
        for(auto y:graph[node]){
            int dist=dfs(y,ans,graph,s)+1;
            if(s[node]!=s[y]){
                ans=max(ans,nowmax+dist);
                nowmax=max(nowmax,dist);
            }
        }
        return nowmax;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> graph;
        graph.resize(n);
        for(int i=0;i<n;i++){
            if(parent[i]!=-1){
                graph[parent[i]].push_back(i);
            }
        }
        int ans=0;
        dfs(0,ans,graph,s);
        return ans+1;
    }
};