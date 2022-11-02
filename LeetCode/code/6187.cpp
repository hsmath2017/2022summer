#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumMoney(vector<vector<int>> &transactions) {
        long total_lose = 0L;
        int mx = 0;
        for (auto &t : transactions) {
            total_lose += max(t[0] - t[1], 0);
            mx = max(mx, min(t[0], t[1]));
        }
        return total_lose + mx;
    }
};