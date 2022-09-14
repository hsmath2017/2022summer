#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using pli=pair<long,int>;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> book(n);
        priority_queue<int,vector<int>,greater<int>> idle;
        priority_queue<pli,vector<pli>,greater<pli>> busy;
        for(int i=0;i<n;i++){
            idle.push(i);
        }
        auto cmp=[](const vector<int>& v1,const vector<int>& v2){
            return v1[0]<v2[0];
        };
        sort(meetings.begin(),meetings.end(),cmp);
        for(auto m:meetings){
            long start=m[0];
            long end=m[1];
            int id;
            while(!busy.empty()){
                auto pair=busy.top();
                if(start>=pair.first){
                    idle.push(pair.second);
                    busy.pop();
                }else{
                    break;
                }
            }
            if(idle.empty()){
                auto pair=busy.top();
                end=end+(-start+pair.first);
                id=pair.second;
                busy.pop();
            }else{
                id=idle.top();
                idle.pop();
            }
            book[id]++;
            busy.push(make_pair(end,id));
        }
        int nowmax=0;
        int ans;
        for(int i=0;i<n;i++){
            if(book[i]>nowmax){
                nowmax=book[i];
                ans=i;
            }
        }
        return ans;
    }
};