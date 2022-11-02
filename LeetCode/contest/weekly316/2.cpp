#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans=0;
        for(int st=0;st<nums.size();st++){
            int tmp=nums[st];
            if(tmp%k){
                continue;
            }
            bool flag=true;
            for(int j=st+1;j<nums.size();j++){
                if(tmp==k){
                    ans++;
                }
                tmp=gcd<int,int>(tmp,nums[j]);
                if(tmp%k){
                    flag=false;
                    break;
                }
            }
            if(flag&&tmp==k){
                ans++;
            }
        }
        return ans;
    }
};