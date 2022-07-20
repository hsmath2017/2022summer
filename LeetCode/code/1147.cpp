#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDecompos(const string& text,int fptr,int rptr){
        if(fptr>rptr){
            return 0;
        }
        if(fptr==rptr){
            return 1;
        }
        int elements=rptr-fptr+1;
        for(int i=1;i<=elements/2;i++){
            if(text.substr(fptr,i)==text.substr(rptr-i+1,i)){
                return 2+findDecompos(text,fptr+i,rptr-i);
            }
        }
        return 1;
    }
    int longestDecomposition(string text) {
        int s=text.length();
        int res=findDecompos(text,0,s-1);
        return res;
    }
};