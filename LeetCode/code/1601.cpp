#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m=requests.size();
        int ans=0;
        for(int i=0;i<(1<<m);i++){
            vector<int> req(n);
            int pos=0;
            int tmp=0;
            while(i){
                if(i&1){
                    req[requests[pos][0]]--;
                    req[requests[pos][1]]++;
                    tmp++;
                }
                i=(i>>1);
                pos++;
            }
            bool flag=true;
            for(auto c:req){
                if(c){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                ans=max(ans,tmp);
            }
        }
        return ans;
    }
};