#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(vector<int>& ufs,int x){
        if(ufs[x]==x){
            return x;
        }
        int newf=find(ufs,ufs[x]);
        ufs[x]=newf;
        return newf;
    }
    void cup(vector<int>& ufs,int x,int y){
        int fx=find(ufs,x);
        int fy=find(ufs,y);
        ufs[fx]=fy;
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        int tot=n/2;
        vector<int> ufs(tot,0);
        for(int i=0;i<tot;i++){
            ufs[i]=i;
        }
        for(int i=0;i<n;i=i+2){
            int x=row[i]/2;
            int y=row[i+1]/2;
            cup(ufs,x,y);
        }
        map<int,int> appear_times;
        for(auto c:ufs){
            int f=find(ufs,c);
            appear_times[f]++;
        }
        int ans=0;
        for(auto it:appear_times){
            ans+=(it.second-1);
        }
        return ans;
    }
};