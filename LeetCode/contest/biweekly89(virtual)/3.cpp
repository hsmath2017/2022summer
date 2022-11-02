#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int nowmax=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(long long)nums[i];
            int d=sum/(i+1);
            if(sum%(i+1)){
                d++;
            }
            nowmax=max(d,nowmax);
        }        
        return nowmax;
    }
};