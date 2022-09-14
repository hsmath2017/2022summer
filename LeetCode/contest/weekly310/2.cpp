#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        map<char,bool> avail;
        for(auto c:s){
            if(avail[c]==true){
                ans++;
                avail.clear();
                avail[c]=true;
            }else{
                avail[c]=true;
            }
        }
        ans++;
        return ans;
    }
};