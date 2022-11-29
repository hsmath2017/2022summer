#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int,int> appear_times;
    int countSubarrays(vector<int>& nums, int k) {
        int pos=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k){
                pos=i;
                break;
            }
        }
        int c=0;
        for(int j=pos+1;j<nums.size();j++){
            if(nums[j]>k){
                c++;
            }else{
                c--;
            }
            appear_times[c]++;
        }
        int ans=0;
        ans=ans+(appear_times[0]+appear_times[1]);
        c=0;
        for(int j=pos-1;j>=0;j--){
            if(nums[j]>k){
                c--;
            }else{
                c++;
            }
            ans=ans+(appear_times[c]+appear_times[c+1]);
        }
        return ans;
    }
};