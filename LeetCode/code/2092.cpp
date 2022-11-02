#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> ufs;
    void Union(int x,int y){
        int fx=find(x);
        int fy=find(y);
        ufs[fx]=fy;
    }
    int find(int x){
        if(ufs[x]==x){
            return x;
        }
        ufs[x]=find(ufs[x]);
        return ufs[x];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        ufs.resize(n);
        for(int i=0;i<n;i++){
            ufs[i]=i;
        }
        Union(0,firstPerson);
        map<int,vector<vector<int>>> time2graph;
        for(auto v:meetings){
            time2graph[v[2]].push_back({v[0],v[1]});
        }
        for(auto it:time2graph){
            for(auto v:it.second){
                Union(v[0],v[1]);
            }
            for(auto v:it.second){
                if(find(0)!=find(v[0])){
                    ufs[v[0]]=v[0];
                    ufs[v[1]]=v[1];
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(find(i)==find(0)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};