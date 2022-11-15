#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> antigraph;
        int n=graph.size();
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto v:graph[i]){
                antigraph[v].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> topsequence;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto c=q.front();
            for(auto v:antigraph[c]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
            topsequence.push_back(c);
            q.pop();
        }
        if(topsequence.empty()){
            return topsequence;
        }else{
            sort(topsequence.begin(),topsequence.end());
        }
        return topsequence;
    }
};