#include<bits/stdc++.h>
using namespace std;
class Solutions {
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
        dp.resize(m);
        for(int i=0;i<m;i++){
            dp[i].resize(n);
        }
        for(int j=0;j<n;j++){
            dp[m-1][j]=1;
        }
        for(int i=0;i<m;i++){
            dp[i][n-1]=1;
        }
        function<int(int,int)> dfs=[&](int row,int column)->int{
            if(row>=m||column>=n){
                return 0;
            }
            if(dp[row][column]){
                return dp[row][column];
            }else{
                int x=dfs(row+1,column)+dfs(row,column+1);
                dp[row][column]=x;
                return x;
            }
        };
        return dfs(0,0);
    }
};