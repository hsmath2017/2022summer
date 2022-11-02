#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> mintrials;
    vector<int> travel;
    int n;
    void dfs(int start,int nowtemp){
        if(start>=n*n){
            return;
        }
        if(nowtemp>=mintrials[start]){
            return;
        }else{
            mintrials[start]=nowtemp;
        }
        for(int i=1;i<=6;i++){
            int now=start+i;
            if(now<n*n&&travel[now]!=-1){
                now=travel[now]-1;
            }
            dfs(now,nowtemp+1);
        }
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        mintrials.resize(n*n);
        for(auto& c:mintrials){
            c=n*n;
        }
        travel.resize(n*n);
        for(int i=0;i<n*n;i++){
            int level=n-1-i/n;
            int mod=i%n;
            if((n-level)%2==0){
                travel[i]=board[level][n-mod-1];
            }else{
                travel[i]=board[level][mod];
            }
        }
        dfs(0,0);
        return mintrials[n*n-1];
    }
};