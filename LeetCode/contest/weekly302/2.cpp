#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getpsum(int p){
        int psum=0;
        while(p){
            psum+=p%10;
            p/=10;
        }
        return psum;
    }
    int maximumSum(vector<int>& nums) {
        auto cmp=[](int a,int b){return a>b;};
        sort(nums.begin(),nums.end(),cmp);
        int sz=nums.size();
        vector<int> psum;
        for(int i=0;i<sz;i++){
            psum.push_back(getpsum(nums[i]));
        }
        map<int,vector<int>> table;
        for(int i=0;i<sz;i++){
            table[psum[i]].push_back(i);
        }
        int res=-1;
        for(auto it:table){
            if(it.second.size()<2){
                continue;
            }else{
                int i=it.second[0];
                int j=it.second[1];
                int s=nums[i]+nums[j];
                if(s>res){
                    res=s;
                }
            }
        }
        return res;
    }
};