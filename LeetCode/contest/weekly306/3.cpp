#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestNumber(string pattern) {
        vector<int> res;
        int n=pattern.size();
        for(int i=1;i<=n+1;i++){
            res.push_back(i);
        }        
        for(int i=0;i<n;i++){
            int tmp=i;
            while(tmp>=0&&pattern[tmp]=='D'){
                swap(res[tmp],res[tmp+1]);
                tmp--;
            }
        }
        string ans;
        for(auto c:res){
            ans.push_back('0'+c);
        }
        return ans;
    }
};