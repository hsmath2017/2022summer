#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int nowtime=0;
        int maxduring=0;
        int ans=-1;
        for(auto c:logs){
            int during=c[1]-nowtime;
            if(during>maxduring){
                maxduring=during;
                ans=c[0];
            }else if(during==maxduring){
                ans=min(ans,c[0]);
            }
            nowtime=c[1];
        }
        return ans;
    }
};