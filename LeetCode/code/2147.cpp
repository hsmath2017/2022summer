#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD=1e9+7;
    using ll=long long;
    int numberOfWays(string corridor) {
        int seatnum=0;
        for(auto c:corridor){
            if(c=='S'){
                seatnum++;
            }
        }
        if(seatnum%2||seatnum==0){
            return 0;
        }
        int res=1;
        int nowseat=0;
        int nowchoice=0;
        bool flag=false;
        for(auto c:corridor){
            if(c=='S'){
                nowseat++;
            }
            if(nowseat%2==0&&nowseat>0&&nowseat<seatnum){
                nowchoice++;
                flag=true;
            }
            if(nowseat%2&&nowseat>1&&flag){
                res=(ll)res*(ll)nowchoice%MOD;
                nowchoice=0;
                flag=false;
            }
        }
        return res;
    }
};