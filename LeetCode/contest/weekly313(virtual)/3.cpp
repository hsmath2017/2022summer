#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get(int d){
        int ans=0;
        while(d){
            ans+=(d%2);
            d/=2;
        }
        return ans;
    }
    int minimizeXor(int num1, int num2) {
        int x1=get(num1);
        int x2=get(num2);
        if(x1==x2){
            return num1;
        }else if(x1<x2){
            int start=1;
            int ans=0;
            int operatenum=x2-x1;
            int now=0;
            while(now<operatenum){
                if((num1^start)>num1){
                    ans|=start;
                    now++;
                }
                start=start<<1;
            }
            ans=ans|num1;
            return ans;
        }else{
            int start=1;
            while(start<num1){
                start=start<<1;
            }
            int ans=0;
            int now=0;
            while(now<x2){
                if((start^num1)<num1){
                    ans|=start;
                    now++;
                }
                start=start>>1;
            }
            return ans;
        }
    }
};