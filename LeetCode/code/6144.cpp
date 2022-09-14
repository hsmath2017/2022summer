#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    void operate(int num,int& target,ll& replace){
        if(num<=target){
            target=num;
            replace=0;
            return;
        }else{
            int k=num/target;
            if(num==k*target){
                replace=k-1;
                return;
            }else{
                target=num/(k+1);
                replace=k;
                return;
            }
        }
        return;
    }
    long long minimumReplacement(vector<int> &nums) {
        reverse(nums.begin(),nums.end());
        ll ans=0;
        int n=nums.size();
        int target=nums[0];
        for(int i=1;i<n;i++){
            ll replace;
            operate(nums[i],target,replace);
            ans+=replace;
        }
        return ans;
    }
};