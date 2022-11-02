#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int,int> dp;
    int minDays(int n) {
        if(n==0){
            return 0;
        }
        if(dp[n]){
            return dp[n];
        }
        int ans1;
        int ans2;
        ans1=(n%2+1)+minDays(n/2);
        ans2=(n%3+1)+minDays(n/3);
        dp[n]=max(ans1,ans2);
        return dp[n];
    }
};