#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<int,ll> next_time;
        ll ans=0;
        for(auto c:tasks){
            if(!next_time[c]){
                ans++;
                next_time[c]=ans+(space+1);
            }else {
                if (ans >= next_time[c]) {
                    ++ans;
                } else {
                    ans=next_time[c];
                }
                next_time[c] = ans + space + 1; // 更新时间
            }
        }
        return ans;
    }
};