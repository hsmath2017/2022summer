#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    using ll=long long;
    const ll infty=1e12;
    const int mod=1e9+7;
    vector<int> pathnums;
    vector<ll> nowDist;
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {
        for(int i=0;i<n;i++){
            nowDist.push_back(infty);
        }
        vector<vector<ll>> graph(n,vector<ll>(n,infty));
        for(auto r:roads){
            graph[r[0]][r[1]]=r[2];
            graph[r[1]][r[0]]=r[2];
        }
        vector<bool> visited(n);
        pathnums.resize(n);
        
    }
};