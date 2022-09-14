#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int,bool> avail;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int d=nums[i]+nums[i+1];
            if(avail[d]){
                return true;
            }else{
                avail[d]=true;
            }
        }        
        return false;
    }
};