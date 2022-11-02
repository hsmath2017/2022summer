#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    ll count(const vector<int>& a,int minK,int maxK){
        ll minKind=-1;
        ll maxKind=-1;
        ll ans=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==minK){
                minKind=i;
            }
            if(a[i]==maxK){
                maxKind=i;
            }
            ans=ans+min(minKind,maxKind)+1;
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<vector<int>> partitioned_seq;
        vector<int> tmp;
        for(auto v:nums){
            if(minK<=v&&v<=maxK){
                tmp.push_back(v);
            }
            else{
                if(tmp.empty()==false){
                    partitioned_seq.push_back(tmp);
                }
                tmp.clear();
            }
        };
        partitioned_seq.push_back(tmp);
        long long ans;
        for(auto a:partitioned_seq){
            ans=ans+count(a,minK,maxK);
        }
        return ans;
    }
};