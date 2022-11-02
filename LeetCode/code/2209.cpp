#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        vector<vector<int>> dp(numCarpets+1,vector<int>(floor.length()));
        dp[0][0]=(floor[0]=='1');
        for(int j=1;j<floor.length();j++){
            dp[0][j]=dp[0][j-1]+(floor[j]=='1');
        }
        for (int i = 1; i <= numCarpets; ++i)
            // j < carpetLen * i 的 f[i][j] 均为 0
            for (int j = carpetLen * i; j < floor.length(); ++j)
                dp[i][j] = min(dp[i][j - 1] + (floor[j] == '1'), dp[i - 1][j - carpetLen]);
        return dp[numCarpets][floor.length() - 1];
    }
};