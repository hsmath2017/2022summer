#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    void handle(vector<ll>& ans,const vector<ll>& index_arr){
        int n=index_arr.size();
        ll delta=0;
        for(int i=0;i<n;i++){
            delta+=(index_arr[i]-index_arr[0]);
        }
        for(int i=0;i<n;i++){
            if(i==0){
                ans[index_arr[i]]=delta;
                continue;
            }else{
                delta+=(2*i-n)*(index_arr[i]-index_arr[i-1]);
                ans[index_arr[i]]=delta;
            }
        }
        return;
    }
    vector<long long> getDistances(vector<int>& arr) {
        map<int,vector<ll>> M;
        int n=arr.size();
        vector<ll> ans(n);
        for(int i=0;i<arr.size();i++){
            M[arr[i]].push_back(i);
        }
        for(auto it:M){
            handle(ans,it.second);
        }
        return ans;
    }
};