#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                int tmp=0;
                tmp=tmp+(grid[i][j]+grid[i-1][j]+grid[i-1][j-1]+grid[i-1][j+1]+grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1]);
                ans=max(ans,tmp);
            }
        }
        return ans;
    }
};