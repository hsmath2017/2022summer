#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int ans=0;
        for(auto c:coins){
            if(c>ans+1){
                break;
            }else{
                ans+=c;
            }
        }
        return ans;
    }
};