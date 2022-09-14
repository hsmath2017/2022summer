#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        map<int,bool> avail;
        for(auto c:nums){
            avail[c]=true;
        }
        int ans=0;
        for(auto c:nums){
            if(avail[c]&&avail[c+diff]&&avail[c+2*diff]){
                ans++;
            }
        }
        return ans;
    }
};