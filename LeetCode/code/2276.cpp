#include<bits/stdc++.h>
using namespace std;
class CountIntervals {
    CountIntervals* left=nullptr,*right=nullptr;
    int l,r;
    int cnt=0;
public:
    CountIntervals() {
        l=1;
        r=1e9;
    }
    CountIntervals(int _l,int _r):l(_l),r(_r){}
    
    void add(int L, int R) {
        if(cnt==r-l+1){
            return;
        }
        if(l>=L&&r<=R){
            cnt=r-l+1;
            return;
        }
        int mid=(l+r)/2;
        if(!left){
            left=new CountIntervals(l,mid);
        }
        if(!right){
            right=new CountIntervals(mid+1,r);
        }
        if(L<=mid){
            left->add(L,R);
        }
        if(R>mid){
            right->add(L,R);
        }
        this->cnt=left->cnt+right->cnt;
        return;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */