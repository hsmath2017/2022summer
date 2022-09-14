#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int gcd(int a,int b){
        if(a<b){
            swap(a,b);
        }
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    bool isGoodArray(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans=gcd(ans,nums[i]);
        }
        if(ans==1){
            return true;
        }else{
            return false;
        }
    }
};