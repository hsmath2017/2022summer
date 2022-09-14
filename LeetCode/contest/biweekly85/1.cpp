#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int blacknum=0;
        int nowblack=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='B'){
                nowblack++;
            }
        }        
        int n=blocks.size();
        for(int i=0;i<n-k;i++){
            if(blocks[i]=='B'){
                nowblack--;
            }
            if(blocks[i+k]=='B'){
                nowblack++;
            }
            if(nowblack>blacknum){
                blacknum=nowblack;
            }
        }
        return k-blacknum;
    }
};