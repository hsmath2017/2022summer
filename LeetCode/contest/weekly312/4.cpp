#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> ufs;
    vector<vector<int>> graph;
    map<int,bool> visited;
    map<int,vector<int>> val2index;
    using pii=pair<int,int>;
    void ufs_union(int a,int b){
        int x=ufs[a];
        int y=ufs[b];
        ufs[x]=y;
    }
    int ufs_find(int a){
        if(ufs[a]==a){
            return a;
        }
        ufs[a]=ufs_find(ufs[a]);
        return ufs[a];
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        for(int i=0;i<n;i++){
            ufs[i]=i;
        }
        int ans=0;
        graph.resize(n);
        for(auto v:edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        for(int i=0;i<vals.size();i++){
            val2index[vals[i]].push_back(i);
        }
        for(auto it:val2index){
            for(auto v:it.second){
                visited[v]=true;
            }
            for(auto v:it.second){
                for(auto w:graph[v]){
                    if(visited[w]){
                        ufs_union(v,w);
                    }
                }
            }
            map<int,int> find_idx;
            for(auto v:it.second){
                find_idx[v]=ufs_find(v);
            }
            for(auto it:find_idx){
                ans=ans+(it.second)*(it.second+1)/2;
            }
        }
        return ans;
    }
};