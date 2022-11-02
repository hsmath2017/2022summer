#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool equalFrequency(string word) {
        int cnt[26] = {0};
        for (char c : word) cnt[c - 'a']++;
        // 枚举字母 i 被删除
        for (int i = 0; i < 26; i++) if (cnt[i] > 0) {
            // 删除字母 i
            cnt[i]--;
            // 检查剩余字母的出现次数是否一致
            int t = 0;
            for (int j = 0; j < 26; j++) if (cnt[j] > 0) {
                if (t == 0) t = cnt[j];
                else if (t != cnt[j]) goto FAILED;
            }
            return true;
            // 恢复字母 i
            FAILED:
            cnt[i]++;
        }
        return false;
    }
};
