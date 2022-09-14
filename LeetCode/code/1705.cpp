#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using pii=pair<int,int>;
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        int ans=0;
        int n=apples.size();
        int i=0;
        //step1: add apples while eat apples
        for(i=0;i<n;i++){
            int apple_num=apples[i];
            int rotten_day=i+days[i];
            pii p(rotten_day,apple_num);
            //add pair
            if(apple_num){
                pq.push(p);
            }
            //remove rottened ones
            while(!pq.empty()&&pq.top().first<=i){
                pq.pop();
            }
            //eat
            if(!pq.empty()){
                pii tmp=pq.top();
                pq.pop();
                tmp.second--;
                ans++;
                if(tmp.second){
                    pq.push(tmp);
                }
            }
        }
        //step2:without new apples
        while(!pq.empty()){
            //remove rottened ones
            while(!pq.empty()&&pq.top().first<=ans){
                pq.pop();
            }
            if(pq.empty()){
                break;
            }
            //eat
            pii curr = pq.top();
            pq.pop();
            int num = min(curr.first - i, curr.second);
            ans += num;
            i += num;
        }
        return ans;
    }
};
