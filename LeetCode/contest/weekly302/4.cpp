#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }else{
            return gcd(b,a%b);
        }
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=numsDivide.size();
        int greatest;
        if(n==1){
            greatest=numsDivide[0];    
        }else{
            greatest=gcd(max(numsDivide[0],numsDivide[1]),min(numsDivide[0],numsDivide[1]));
            for(int i=2;i<n;i++){
                greatest=gcd(max(greatest,numsDivide[i]),min(greatest,numsDivide[i]));
            }
        }
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(greatest%nums[i]==0){
                break;
            }
            res++;
        }
        if(res==nums.size()){
            return -1;
        }
        return res;
    }
};