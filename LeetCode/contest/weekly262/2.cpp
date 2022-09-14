#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> seq;
        for(auto vec:grid){
            for(auto d:vec){
                seq.push_back(d);
            }
        }        
        sort(seq.begin(),seq.end());
        int n=seq.size();
        int target=seq[n/2];
        int ans=0;
        for(auto d:seq){
            if(abs(target-d)%x){
                return -1;
            }else{
                ans=ans+(abs(target-d))/x;
            }
        }
        return ans;
    }
};