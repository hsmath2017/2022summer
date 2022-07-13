#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fillCups(vector<int>& amount) {
        auto cmp=[](int a,int b){return a>b;};
        sort(amount.begin(),amount.end(),cmp);
        int res=0;
        while(amount[1]!=0){
            res++;
            amount[0]--;
            amount[1]--;
            sort(amount.begin(),amount.end(),cmp);
        }
        res+=amount[0];
        return res;
    }
};