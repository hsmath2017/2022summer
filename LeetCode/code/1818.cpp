#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD=1e9+7;
    int BinarySearch(int target,const vector<int>& ordered_seq,int Left,int Right){
        if(Left==Right){
            return Left;
        }
        int mid=(Left+Right)/2;
        if(ordered_seq[mid]<=target){
            return BinarySearch(target,ordered_seq,mid,Right);
        }else{
            return BinarySearch(target,ordered_seq,Left,mid-1);
        }
    }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int n=nums1.size();
        //step 1: get the absolute sum diff of nums1 and nums2
        for(int i=0;i<n;i++){
            ans=ans+abs(nums1[i]-nums2[i]);
            ans=ans%MOD;
        }
        //step 2: create an ordered sequence by vector nums1
        vector<int> ordered_seq=nums1;
        sort(ordered_seq.begin(),ordered_seq.end());
        //step 3: bisection find the nearest elements, and calculate the minus created by instituting.
        int minus=0;
        for(int i=0;i<n;i++){
            int origin=abs(nums1[i]-nums2[i]);
            int changed;
            if(nums2[i]<=ordered_seq[0]){
                changed=ordered_seq[0]-nums2[i];
            }else if(nums2[i]>=ordered_seq[n-1]){
                changed=nums2[i]-ordered_seq[n-1];
            }else{
                int index=BinarySearch(nums2[i],ordered_seq,0,n-1);
                changed=std::min(abs(nums2[i]-ordered_seq[index]),abs(nums2[i]-ordered_seq[index+1]));
            }
            if(origin-changed>minus){
                minus=origin-changed;
            }
        }
        //step4: get the result.
        ans-=minus;
        if(ans<0){
            ans+=MOD;
        }
        return ans;
    }
};