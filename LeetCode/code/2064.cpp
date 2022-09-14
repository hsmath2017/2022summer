#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int mid,const vector<int>& quantities){
        int x=0;
        for(auto c:quantities){
            if(c%mid==0){
                x+=(c/mid);
            }else{
                x+=(c/mid+1);
            }
        }
        return x;
    }
    int binary_find(int left,int right,int n,const vector<int>& quantities){
        if(left==right){
            return left;
        }
        if(left==right-1){
            return left;
        }
        int mid=(left+right)/2;
        int x=check(mid,quantities);
        if(x<=n){
            return binary_find(mid,right,n,quantities);
        }else{
            return binary_find(left,mid-1,n,quantities);
        }
    }   
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=0;
        for(auto c:quantities){
            if(c>m){
                m=c;
            }
        }
        int left=1;
        int ans=binary_find(left,m,n,quantities);
        return ans;
    }
};