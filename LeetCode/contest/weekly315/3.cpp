#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reversenum(int d){
        string s=to_string(d);
        reverse(s.begin(),s.end());
        int x=stoi(s);
        return x;
    }
    bool sumOfNumberAndReverse(int num) {
        bool ans=false;
        for(int i=0;i<=num;i++){
            int t=reversenum(i);
            if(i+t==num){
                return true;
            }
        }
        return false;
    }
};