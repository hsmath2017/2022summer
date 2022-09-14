#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        using ll=long long;
        ll best1=0;
        ll best2=0;
        int i,j;
        i=j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                best1+=nums1[i];
                i++;
            }
            else if(nums1[i]>nums2[j]){
                best2+=nums2[j];
                j++;
            }else{
                ll common=max(best1,best2);
                best1=common+nums1[i];
                best2=common+nums2[j];
                i++;
                j++;
            }
        }
        while(i<nums1.size()){
            best1+=nums1[i++];
        }
        while(j<nums2.size()){
            best2+=nums2[j++];
        }
        ll ans=max(best1,best2);
        const int M=1e9+7;
        ans=ans%M;
        return ans;
    }
};