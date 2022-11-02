#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        if(n%2){
            for(auto c:nums2){
                ans^=c;
            }
        }
        if(m%2){
            for(auto c:nums1){
                ans^=c;
            }
        }
        return ans;
    }
};