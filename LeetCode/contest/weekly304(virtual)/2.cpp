#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int t = 2 * grades.size(), g = sqrt(t);
        return g * (g + 1) > t ? g - 1 : g;
    }
};