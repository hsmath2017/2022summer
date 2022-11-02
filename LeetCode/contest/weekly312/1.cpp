#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        using pii=pair<int,int>;
        vector<pii> ids;
        for(int i=0;i<heights.size();i++){
            pii pair{i,heights[i]};
            ids.push_back(pair);
        }     
        auto cmp=[](const pii& p1,const pii& p2){
            return p1.second>p2.second;
        };
        sort(ids.begin(),ids.end(),cmp);
        vector<string> ans;
        for(auto c:ids){
            ans.push_back(names[c.first]);
        }
        return ans;
    }
};