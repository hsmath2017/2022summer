#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char,vector<int>> availpos;
        for(int i=0;i<s.length();i++){
            availpos[s[i]].push_back(i);
        }
        for(char c='a';c<='z';c++){
            int d=c-'a';
            if(availpos[c].size()==0){
                continue;
            }else{
                int x=availpos[c][1]-availpos[c][0]-1;
                if(distance[d]!=x){
                    return false;
                }
            }
        }
        return true;
    }
};