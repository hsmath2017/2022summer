#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        map<int,int> times;
        map<int,bool> avail;
        for(auto c:nums1){
            if(!avail[c]){
                avail[c]=true;
                times[c]++;
            }
        }       
        avail.clear(); 
        for(auto c:nums2){
            if(!avail[c]){
                avail[c]=true;
                times[c]++;
            }
        }
        avail.clear();
        for(auto c:nums3){
            if(!avail[c]){
                avail[c]=true;
                times[c]++;
            }
        }
        vector<int> ans;
        for(auto it:times){
            if(it.second>=2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};