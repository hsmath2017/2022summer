#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node,const vector<vector<int>>& graph,vector<bool>& visited){   
        visited[node]=true;
        for(auto c:graph[node]){
            if(!visited[c]){
                dfs(c,graph,visited);
            }
        }
    } 
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> graph;
        int n=bombs.size();
        graph.resize(n);
        auto measure=[](const vector<int>& bomb1,const vector<int>& bomb2){
            long m=0;
            m+=(pow((bomb1[0]-bomb2[0]),2)+pow((bomb1[1]-bomb2[1]),2));
            return m;
        };     
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i){
                    continue;
                }
                long dist=measure(bombs[i],bombs[j]);
                if(dist<=((long)(bombs[i][2])*(long)(bombs[i][2]))){
                    graph[i].push_back(j);
                }
            }
        }
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            vector<bool> visited(n);
            dfs(i,graph,visited);
            for(auto v:visited){
                if(v){
                    nums[i]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>ans){
                ans=nums[i];
            }
        }
        return ans;
    }
};