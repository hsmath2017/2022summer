#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSpecialNumbers(int n) {
        //if (n == 0) return 1;
        vector<int> dp;
        dp.resize(10);
        dp[0] = 1;
        dp[1] = 10;
        for (int i = 2; i <= 9; i++){
            dp[i] = dp[i-1] + (dp[i-1] - dp[i-2])*(10-(i-1));
        }
        int wei=0;
        int tmp=n;
        while(tmp){
            tmp/=10;
            wei++;
        }
        
        //return dp[n];
    }
};
