#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void topsort(const vector<vector<int>>& Graph,vector<int>& toporder){
        int n=Graph.size();
        vector<int> indegree(n);
        for(int i=1;i<n;i++){
            for(auto t:Graph[i]){
                indegree[t]++;
            }
        }
        queue<int> Q;
        for(int i=1;i<n;i++){
            if(indegree[i]==0){
                Q.push(i);
            }
        }
        while(Q.empty()==false){
            int x=Q.front();
            toporder.push_back(x);
            Q.pop();
            for(auto c:Graph[x]){
                indegree[c]--;
                if(indegree[c]==0){
                    Q.push(c);
                }
            }
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        //step 0: construct the graph
        vector<vector<int>> G1(k+1);
        vector<vector<int>> G2(k+1);
        for(auto v:rowConditions){
            G1[v[0]].push_back(v[1]);
        }
        for(auto v:colConditions){
            G2[v[0]].push_back(v[1]);
        }
        //step 1: topological sort
        vector<int> rowseq;
        vector<int> columnseq;
        topsort(G1,rowseq);
        topsort(G2,columnseq);
        //step 2: check
        vector<vector<int>> ans;
        if(rowseq.size()<k||columnseq.size()<k){
            return ans;
        }
        //step 3: construct the matrix
        ans.resize(k);
        for(int i=0;i<k;i++){
            ans[i].resize(k);
        }
        map<int,int> num2column;
        for(int i=0;i<k;i++){
            num2column[columnseq[i]]=i;
        }
        for(int i=0;i<k;i++){
            ans[i][num2column[rowseq[i]]]=rowseq[i];
        }
        return ans;
    }
};