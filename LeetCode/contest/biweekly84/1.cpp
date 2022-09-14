#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> res;
        map<int,int> weight2value;
        for(auto v:items1){
            weight2value[v[0]]+=v[1];
        }   
        for(auto v:items2){
            weight2value[v[0]]+=v[1];
        }
        for(auto it:weight2value){
            int x=it.first;
            int y=it.second;
            vector<int> good{x,y};
            res.push_back(good);
        }
        return res;
    }
};