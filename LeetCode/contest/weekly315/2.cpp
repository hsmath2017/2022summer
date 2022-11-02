#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reversenum(int d){
        string s=to_string(d);
        reverse(s.begin(),s.end());
        int x=stoi(s);
        return x;
    }
    int countDistinctIntegers(vector<int>& nums) {
        set<int> ans;
        for(auto c:nums){
            ans.insert(c);
            int t=reversenum(c);
            ans.insert(t);
        }
        return ans.size();
    }
};