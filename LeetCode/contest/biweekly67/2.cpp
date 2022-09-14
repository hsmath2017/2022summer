#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        if(n==1){
            if(time==0){
                return {0};
            }else{
                return {};
            }
        }
        map<int,bool> decrease_times;
        map<int,bool> increase_times;
        int decrease_len=1;
        for(int i=0;i<n;i++){
            if(i==0){
                if(time==0){
                    decrease_times[i]=true;
                }
                continue;
            }
            if(security[i]<=security[i-1]){
                decrease_len++;
            }else{
                decrease_len=1;
            }
            if(decrease_len>=time+1){
                decrease_times[i]=true;
            }
        }
        int increase_len=1;
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                if(time=0){
                    increase_times[i]=true;
                    continue;
                }
            }
            if(security[i]<=security[i+1]){
                increase_len++;
            }else{
                increase_len=1;
            }
            if(increase_len>=time+1){
                increase_times[i]=true;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(increase_times[i]&&decrease_times[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};