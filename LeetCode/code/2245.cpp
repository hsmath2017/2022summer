#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
pii operator+(const pii& p1,const pii& p2){
    pii p{p1.first+p2.first,p1.second+p2.second};
    return p;
}
class Solution {
public:
    using pii=pair<int,int>;
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        auto format=[](int d)->pii{
            int two=0;
            int five=0;
            while(d){
                if(d%2){
                    break;
                }
                two++;
                d/=2;
            }
            while(d){
                if(d%5){
                    break;
                }
                five++;
                d/=5;
            }
            pii p{two,five};
            return p;
        };
        vector<vector<pii>> grid_two_or_five(m,vector<pii>(n));
        vector<vector<pii>> up_down(m,vector<pii>(n));
        vector<vector<pii>> down_up(m,vector<pii>(n));
        vector<vector<pii>> left_right(m,vector<pii>(n));
        vector<vector<pii>> right_left(m,vector<pii>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid_two_or_five[i][j]=format(grid[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    up_down[i][j]=grid_two_or_five[i][j];
                }else{
                    up_down[i][j]=up_down[i-1][j]+grid_two_or_five[i][j];
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i==m-1){
                    down_up[i][j]=grid_two_or_five[i][j];
                }else{
                    down_up[i][j]=down_up[i+1][j]+grid_two_or_five[i][j];
                }
            }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(j==0){
                    left_right[i][j]=grid_two_or_five[i][j];
                }else{
                    left_right[i][j]=left_right[i][j-1]+grid_two_or_five[i][j];
                }
            }
        }
        for(int j=n-1;j>=0;j--){
            for(int i=0;i<m;i++){
                if(j==n-1){
                    right_left[i][j]=grid_two_or_five[i][j];
                }else{
                    right_left[i][j]=right_left[i][j+1]+grid_two_or_five[i][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int tmp=0;
                if(j+1<n){
                    auto p1=up_down[i][j]+right_left[i][j+1];
                    auto p2=down_up[i][j]+right_left[i][j+1];
                    tmp=max(tmp,max(p1.first,p1.second));
                    tmp=max(tmp,max(p2.first,p2.second));
                }
                if(j>0){
                    auto p1=up_down[i][j]+left_right[i][j-1];
                    auto p2=down_up[i][j]+left_right[i][j-1];
                    tmp=max(tmp,max(p1.first,p1.second));
                    tmp=max(tmp,max(p2.first,p2.second));
                }
                if(tmp>ans){
                    ans=tmp;
                }
            }
        }
        return ans;
    }
};