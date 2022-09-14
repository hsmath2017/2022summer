#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bisection_find(int target,const vector<int>& arr,int left,int right){
        if(target>arr[right]){
            return right+1;
        }
        while(left<right){
            int mid=(left+right)/2;
            if(arr[mid]<target){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        //step 0: increasing sequence->return zero
        int n=arr.size();
        if(n==1){
            return 0;
        }
        bool increase=true;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                increase=false;
                break;
            }
        }
        if(increase){
            return 0;
        }
        //step 1: Find max left-increasing length & right-increasing length
        int left,right;
        left=right=1;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                break;
            }
            left++;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                break;
            }
            right++;
        }
        //step 2: Bisection Find
        int ans=0;
        for(int i=0;i<left;i++){
            int d=bisection_find(arr[i],arr,n-right,n-1);
            if((n-d)+i+1>ans){
                ans=n-d+i+1;
            }
        }
        //step 3: Maybe Totally remove one sequence
        ans=max(left,ans);
        ans=max(right,ans);
        //step 4: Return
        return n-ans;
    }
};