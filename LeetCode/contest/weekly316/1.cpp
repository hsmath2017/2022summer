#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int state(const string&s){
        string hour=s.substr(0,2);
        string minute=s.substr(3,2);
        int ans=stoi(hour)*60+stoi(minute);
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int st1=state(event1[0]);
        int ed1=state(event1[1]);
        int st2=state(event2[0]);
        int ed2=state(event2[1]);        
        for(int i=0;i<24*60;i++){
            if(i>=st1&&i<=ed1&&i>=st2&&i<=ed2){
                return true;
            }
        }
        return false;
    }
};