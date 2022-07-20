#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    map<int,int> times;
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        for(auto c:nums){
            times[c]++;
        }
        int group,single;
        group=0;
        single=0;
        for(auto it:times){
            group+=it.second/2;
            single+=it.second%2;
        }
        vector<int> res{group,single};
        return res;
    }
};
