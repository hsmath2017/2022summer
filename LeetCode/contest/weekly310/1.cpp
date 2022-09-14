#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> freq;
        for(auto c:nums){
            if(c%2==0){
                freq[c]++;
            }
        }
        if(freq.size()==0){
            return -1;
        }
        int ans;
        int nowfreq=0;
        for(auto it:freq){
            if(it.second>nowfreq){
                ans=it.first;
                nowfreq=it.second;
            }
        }
        return ans;
    }
};