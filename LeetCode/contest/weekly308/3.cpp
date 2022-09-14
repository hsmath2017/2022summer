#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int housenum=garbage.size();
        vector<map<char,int>> GarbageNum;
        GarbageNum.resize(housenum);
        for(int i=0;i<housenum;i++){
            for(auto c:garbage[i]){
                GarbageNum[i][c]++;
            }
        }
        vector<char> car={'M','P','G'};
        vector<int> presum(housenum);
        presum[0]=0;
        int s=0;
        int index=0;
        for(auto t:travel){
            s+=t;
            presum[++index]=s;
        }
        int ans=0;
        for(auto c:car){
            int lasthouse=-1;
            for(int i=0;i<housenum;i++){
                if(GarbageNum[i][c]){
                    ans+=GarbageNum[i][c];
                    lasthouse=i;
                }
            }
            if(lasthouse!=-1){
                ans+=presum[lasthouse];
            }
        }
        return ans;
    }
};