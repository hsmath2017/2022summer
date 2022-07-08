#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> psum;
        psum.push_back(0);
        int s=0;
        for(auto v:hours){
            if(v>8){
                s++;
            }else{
                s--;
            }
            psum.push_back(s);
        }
        map<int,int> mono_stack;
        int nowmin=0;
        mono_stack[nowmin]=0;
        for(int i=0;i<psum.size();i++){
            if(psum[i]<nowmin){
                nowmin=psum[i];
                mono_stack[nowmin]=i;
            }
        }
        int res=0;
        for(int i=0;i<psum.size();i++){
            if(psum[i]>0){
                res=max(res,i);
            }else{
                int ind=mono_stack[psum[i]-1];
                if(ind==0){
                    continue;
                }else{
                    res=max(res,i-ind);
                }
            }
        }
        return res;
    }
};