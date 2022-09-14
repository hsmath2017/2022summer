#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> max;
public:
    void modify(int o,int l,int r,int index,int val){
        if(l==r){
            max[o]=val;
            return;
        }
        int mid=(l+r)/2;
        if(index<=mid){
            modify(o*2,l,mid,index,val);
        }else{
            modify(o*2+1,mid+1,r,index,val);
        }
        max[o]=std::max(max[o*2],max[o*2+1]);
    }
    int query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return max[o];
        }
        int res=0;
        int mid=(l+r)/2;
        if(L<=mid){
            res=query(o*2,l,mid,L,R);
        }
        if(mid<R){
            res=std::max(res,query(o*2+1,mid+1,r,L,R));
        }
        return res;
    }
    int lengthOfLIS(vector<int> &nums, int k) {
        int m=0;
        for(auto c:nums){
            if(c>m){
                m=c;
            }
        }
        max.resize(4*m);
        for(auto x:nums){
            if(x==1){
                modify(1,1,m,1,1);
            }else{
                int res=1+query(1,1,m,std::max(x-k,1),x-1);
                modify(1,1,m,x,res);
            }
        }
        return max[1];
    }
};
