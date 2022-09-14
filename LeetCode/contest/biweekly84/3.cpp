#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<int,long long> nexttask;
        long long ans=0;
        if(tasks.size()==1){
            return 1;
        }
        for(auto c:tasks){
            if(ans<nexttask[c]){
                ans=nexttask[c];
                nexttask[c]+=(space+1);
                cout<<ans<<endl;
                continue;
            }
            if(!nexttask[c]){
                nexttask[c]=++ans;            
                nexttask[c]+=(space+1);
            }else{
                ans++;
            }
            cout<<ans<<endl;
            //ans++;
        }
        return ans;
    }
};