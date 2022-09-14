#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int,int> times;
        bool flag1=true;
        for(int i=0;i<5;i++){
            if(suits[i]!=suits[0]){
                flag1=false;
                break;
            }
        }
        if(flag1){
            return "Flush";
        }
        for(auto d:ranks){
            times[d]++;
        }
        int maxtime=0;
        for(auto it:times){
            if(it.second>maxtime){
                maxtime=it.second;
            }
        }
        if(maxtime>=3){
            return "Three of a Kind";
        }else if(maxtime==2){
            return "Pair";
        }else{
            return "High Card";
        }
    }
};