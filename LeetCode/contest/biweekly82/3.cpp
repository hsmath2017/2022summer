#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff;
        for(int i=0;i<nums1.size();i++){
            diff.push_back(abs(nums1[i]-nums2[i]));
        }
        int total_times=k1+k2;
        auto cmp=[](int a,int b){return a>b;};
        sort(diff.begin(),diff.end(),cmp);
        diff.push_back(0);
        map<int,int> appear_times;
        for(auto c:diff){
            appear_times[c]++;
        }
        vector<int> need_operat_times;
        need_operat_times.push_back(0);
        for(int i=0;i<diff.size()-1;i++){
            int d=need_operat_times[i]+(diff[i]-diff[i+1])*(i+1);
            need_operat_times.push_back(d);
        }
        int flag=0;
        for(flag;flag<need_operat_times.size();flag++){
            if(need_operat_times[flag]>total_times){
                break;
            }
        }
        if(flag==need_operat_times.size()){
            return 0;
        }
        flag--;
        long long res=0;
        using ll=long long;
        for(int i=flag+1;i<diff.size();i++){
            res=res+(ll)pow(diff[i],2);
        }
        total_times-=need_operat_times[flag];
        int minus=total_times/(flag+1);
        int resid=total_times-minus*(flag+1);
        res=res+(ll)pow(diff[flag]-minus,2)*(flag-resid)+(ll)pow(diff[flag]-minus-1,2)*resid;
        return res;
    }
};