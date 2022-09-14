#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<long long> presum;
public:
    long long check(int num,const vector<int>& chargeTimes,const vector<int>& runningCosts){
        if(num==0){
            return 0;
        }
        long long ans=-1;
        deque<int> dq;
        vector<int> nowmax;
        for(int i=0;i<num;i++){
            while(!dq.empty()&&chargeTimes[i]>chargeTimes[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        nowmax.push_back(chargeTimes[dq.front()]);
        for(int i=num;i<chargeTimes.size();i++){
            if(!dq.empty()&&dq.front()<=i-num){
                dq.pop_front();
            }
            while(!dq.empty()&&chargeTimes[i]>chargeTimes[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            nowmax.push_back(chargeTimes[dq.front()]);
        }
        cout<<endl;
        for(int i=0;i<=chargeTimes.size()-num;i++){
            long long tmp=(presum[i+num]-presum[i])*(long long)num;
            tmp=tmp+(long long)nowmax[i];
            if(ans==-1){
                ans=tmp;
                continue;
            }
            if(tmp<ans){
                ans=tmp;
            }
        }
        return ans;
    }
    int binary_find(int start,int end,const vector<int>& chargeTimes,const vector<int>& runningCosts,const long long& budget){
        if(start==end){
            return start;
        }
        if(start==end-1){
            if(check(end,chargeTimes,runningCosts)<=budget){
                return end;
            }
            return start;
        }
        int mid=(start+end)/2;
        long long d=check(mid,chargeTimes,runningCosts);
        if(d<=budget){
            return binary_find(mid,end,chargeTimes,runningCosts,budget);
        }else{
            return binary_find(start,mid-1,chargeTimes,runningCosts,budget);
        }
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        presum.push_back(0);
        long long s=0;
        for(auto c:runningCosts){
            s=s+(long long)c;
            presum.push_back(s);
        }
        int n=chargeTimes.size();
        int start=0;
        int end=n;
        int ans=binary_find(start,end,chargeTimes,runningCosts,budget);
        return ans;
    }
};