#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        int len=s.length();
        map<int,bool> havestar;
        for(int i=0;i<len;i++){
            if(s[i]=='*'){
                havestar[i]=true;
            }
        }
        stack<int> newstar;
        for(int i=0;i<len;i++){
            if(s[i]!='*'){
                newstar.push(i);
            }
            else{
                if(newstar.empty()==false){
                    int d=newstar.top();
                    havestar[d]=true;
                    newstar.pop();
                }
            }
        }
        string ans;
        for(int i=0;i<len;i++){
            if(havestar[i]){
                continue;
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};