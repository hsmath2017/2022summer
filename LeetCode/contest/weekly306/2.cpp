#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int,int> score;
        int n=edges.size();
        for(int i=0;i<n;i++){
            score[edges[i]]+=i;
        }
        int ans=0;
        int nowscore=-1;
        for(auto it:score){
            if(it.second>nowscore){
                nowscore=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};