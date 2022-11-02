#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> ufs;
    int Find(int x){
        if(x==ufs[x]){
            return x;
        }
        ufs[x]=Find(ufs[x]);
        return ufs[x];
    }
    void Union(int x,int y){
        int dx=Find(x);
        int dy=Find(y);
        ufs[dx]=dy;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=row*col;
        ufs.resize(n+2);
        for(int i=0;i<=n+1;i++){
            ufs[i]=i;
        }
        int day;
        vector<vector<bool>> visited(row,vector<bool>(col));
        for(int i=n-1;i>=0;i--){
            auto c=cells[i];
            int pos=c[0]*col+c[1];
            if(c[0]==0){
                Union(i,n);
            }
            if(c[0]==row-1){
                Union(i,n+1);
            }
            visited[c[0]][c[1]]=true;
            if(c[0]>0){
                if(visited[c[0]-1][c[1]]==true){
                    Union(pos,pos-col);
                }
            }
            if(c[0]<row-1){
                if(visited[c[0]+1][c[1]]==true){
                    Union(pos,pos+col);
                }
            }
            if(c[1]>0){
                if(visited[c[0]][c[1]-1]==true){
                    Union(pos,pos-1);
                }
            }
            if(c[1]<col-1){
                if(visited[c[0]][c[1]+1]==true){
                    Union(pos,pos+1);
                }
            }
            if(Find(n)==Find(n+1)){
                day=i;
                break;
            }
        }
        return day;
    }
};