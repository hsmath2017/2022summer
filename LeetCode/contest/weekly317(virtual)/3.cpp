#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    long long makeIntegerBeautiful(long n, int target) {
        
        // 注意越界
        long tail = 1;
        
        while(true) {
            
            long m = n + (tail - n % tail) % tail, x = m;
            int t = 0;

            while(x != 0) {
                t += x % 10;
                x /= 10;
            }
            if(t <= target) return m - n;
            tail *= 10;
        }
    }
};
