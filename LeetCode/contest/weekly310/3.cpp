#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using pii=pair<int,int>;
    int minGroups(vector<vector<int>>& intervals) {
        vector<pii> input;
        for(auto v:intervals){
            pii pair{v[0],v[1]};
            input.push_back(pair);
        }
        sort(input.begin(),input.end());
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        int ans=0;
        for(auto v:input){
            if(pq.empty()){
                pq.push(make_pair(v.second,ans));
                ans++;
                continue;
            }
            auto tmp=pq.top();
            if(v.first<=tmp.first){
                pq.push(make_pair(v.second,ans));
                ans++;
            }else{
                pq.pop();
                pq.push(make_pair(v.second,ans));
            }
        }
        return ans;
    }
};