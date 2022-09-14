#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int dat){
        dat/=5;
        int s=0;
        while(dat){
            s+=dat;
            dat/=5;
        }
        return s;
    }
    bool binary_find(int left,int right,const int& k){
        if(left>right){
            return false;
        }
        int mid=(left+right)/2;
        int s=check(mid);
        if(s==k){
            return true;
        }else if(s<k){
            return binary_find(mid+1,right,k);
        }else{
            return binary_find(left,mid-1,k);
        }
    }
    int preimageSizeFZF(int k) {
        int left=0;
        int right=5*k;
        bool res=binary_find(left,right,k);
        if(res){
            return 5;
        }else{
            return 0;
        }
    }
};