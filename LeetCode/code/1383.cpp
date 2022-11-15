#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    class Candidate{
    public:
        int s;
        int e;
        Candidate(int speed,int efficiency):s(speed),e(efficiency){}
        bool operator<(const Candidate& c){
            return s>c.s;
        }
    };
    using ll=long long;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Candidate> vec;
        for(int i=0;i<n;i++){
            Candidate c(speed[i],efficiency[i]);
            vec.push_back(c);
        }
        sort(vec.begin(),vec.end(),[](const Candidate& c1,const Candidate& c2){return c1.e>c2.e;});
        priority_queue<Candidate> pq;
        ll sum=0;
        ll nowefficient=0;
        ll ans=0;
        for(auto v:vec){
            nowefficient=v.e;
            if(pq.size()<k){
                pq.push(v);
                sum=sum+(ll)v.s;
            }
            else{
                auto w=pq.top();
                sum=sum-(ll)w.s+(ll)v.s;
                pq.pop();
                pq.push(v);
            }
            ans=max(ans,nowefficient*sum);
        }
        return (int)(ans%(int)(1e9+7));
    }
};