#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCycle(vector<int> &edges) {
        int n = edges.size(), time[n], ans = -1;
        memset(time, 0, sizeof(time));
        for (int i = 0, clock = 1; i < n; ++i) {
            if (time[i]) continue;
            for (int x = i, start_time = clock; x >= 0; x = edges[x]) {
                if (time[x]) { // 重复访问
                    if (time[x] >= start_time) // 找到了一个新的环
                        ans = max(ans, clock - time[x]);
                    break;
                }
                time[x] = clock++;
            }
        }
        return ans;
    }
};
