#include<bits/stdc++.h>
using namespace std;
bool operator<(const vector<int>& v1,const vector<int>& v2){
    return v1[0]<v2[0];
}
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,int> rownum;
        map<vector<int>,int> columnnum;
        for(int i=0;i<n;i++){
            vector<int> tmp;
            for(int j=0;j<n;j++){
                tmp.push_back(grid[i][j]);
            }
            rownum[tmp]++;
        }
        for(int i=0;i<n;i++){
            vector<int> tmp;
            for(int j=0;j<n;j++){
                tmp.push_back(grid[j][i]);
            }
            columnnum[tmp]++;
        }
        int res=0;
        for(auto it:rownum){
            res=res+it.second*columnnum[it.first];
        }
        return res;
    }
};