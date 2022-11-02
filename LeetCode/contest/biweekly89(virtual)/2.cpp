#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power2(500);
        int ans=1;
        for(int i=0;i<power2.size();i++){
            power2[i]=ans;
            ans=ans*2;
            ans%=MOD;
        }
        vector<int> binaryrep;
        int shuwei=0;
        while(n){
            if(n&1){
                binaryrep.push_back(shuwei*(n&1));
            }
            n=n>>1;
            shuwei++;
        }
        vector<int> presum;
        presum.push_back(0);
        int s=0;
        for(auto c:binaryrep){
            s+=c;
            presum.push_back(s);
        }
        vector<int> res;
        for(auto it:queries){
            int rptr=presum[it[1]+1]-presum[it[0]];
            res.push_back(power2[rptr]);
        }
        return res;
    }
};