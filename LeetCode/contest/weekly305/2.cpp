#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> adj_table;
public:
    void dfs(int node,vector<bool>& visited,map<int,bool>& restricted){
        visited[node]=true;
        for(auto v:adj_table[node]){
            if(visited[v]==true||restricted[v]==true){
                continue;
            }else{
                dfs(v,visited,restricted);
            }
        }
        return;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool> visited(n);
        map<int,bool> isrestrict;
        for(auto v:restricted){
            isrestrict[v]=true;
        }
        adj_table.resize(n);
        for(auto v:edges){
            int x=v[0];
            int y=v[1];
            adj_table[x].push_back(y);
            adj_table[y].push_back(x);
        }
        dfs(0,visited,isrestrict);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==true){
                ans++;
            }
        }
        return ans;
    }
};