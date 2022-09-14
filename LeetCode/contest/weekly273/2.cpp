#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool indomain(int n,vector<int>& pos){
        if(pos[0]<0||pos[0]>=n||pos[1]<0||pos[1]>=n){
            return false;
        }else{
            return true;
        }
    }
    int execute(vector<int>& startPos,string now,int n){
        int stepnum=0;
        vector<int> nowPos=startPos;
        for(auto c:now){
            switch(c){
                case 'L':
                    nowPos[1]--;
                    break;
                case 'R':
                    nowPos[1]++;
                    break;
                case 'U':
                    nowPos[0]--;
                    break;
                case 'D':
                    nowPos[0]++;
                    break;
            }
            if(!indomain(n,nowPos)){
                break;
            }
            stepnum++;
        }
        return stepnum;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        for(int i=0;i<s.length();i++){
            string now=s.substr(i);
            int d=execute(startPos,now,n);
            res.push_back(d);
        }
        return res;
    }
};
