#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using pii=pair<int,int>;
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<pii> diff;
        for(int i=0;i<tasks.size();i++){
            pii pi;
            pi.first=i;
            pi.second=tasks[i][1]-tasks[i][0];
            diff.push_back(pi);
        }
        auto cmp=[tasks](const pii& p1,const pii& p2){
            if(p1.second==p2.second){
                return tasks[p1.first][1]<tasks[p2.first][1];
            }
            return p1.second<p2.second;
        };
        sort(diff.begin(),diff.end(),cmp);
        int energy=0;
        for(auto it:diff){
            int demand=max(tasks[it.first][1],energy+tasks[it.first][0]);
            energy=demand;
        }
        return energy;
    }
};