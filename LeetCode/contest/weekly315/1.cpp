#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,bool> avail;
        for(auto c:nums){
            avail[c]=true;
        }        
        int ans=-1;
        for(auto c:nums){
            if(c>0&&avail[-c]==true){
                ans=max(ans,c);
            }
        }
        return ans;
    }
};