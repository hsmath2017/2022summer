#include<bits/stdc++.h>
using namespace std;
class RangeModule {
    RangeModule* left=nullptr,*right=nullptr;
    int l,r;
    int cnt=0;
public:
    RangeModule() {
        l=1;
        r=1e9;
    }
    
    RangeModule(int _l,int _r):l(_l),r(_r){}
    
    void add(int L,int R){
        if(r==l){
            cnt=1;
            return;
        }
        if(L<=l&&r<=R){
            cnt=r-l+1;
        }
        int mid=(l+r)/2;
        if(!left){
            left=new RangeModule(l,mid);
        }
        if(!right){
            right=new RangeModule(mid+1,r);
        }
        if(mid>=L){
            left->add(L,R);
        }
        if(mid<R){
            right->add(L,R);
        }
        this->cnt=left->cnt+right->cnt;
        return;
    }

    void addRange(int L, int R) {
        add(L,R-1);
    }
    
    bool query(int L,int R){
        if(L<=l&&r<=R){
            if(cnt==r-l+1){
                return true;
            }else{
                return false;
            }
        }
        int mid=(l+r)/2;
        if(!left){
            left=new RangeModule(l,mid);
        }
        if(!right){
            right=new RangeModule(mid+1,r);
        }
        bool ans=true;
        if(mid>=L){
            ans=ans&left->query(L,R);
        }
        if(mid<R){
            ans=ans&right->query(L,R);
        }
        return ans;
    }
    bool queryRange(int L, int R) {
        return query(L,R-1);
    }
    
    void remove(int L,int R){
        if(l>=L&&r<=R){
            cnt=0;
        }
        if(l==r){
            return;
        }
        int mid=(l+r)/2;
        if(!left){
            left=new RangeModule(l,mid);
        }
        if(!right){
            right=new RangeModule(mid+1,r);
        }
        if(mid>=L){
            left->remove(L,R);
        }
        if(mid<R){
            right->remove(L,R);
        }
        this->cnt=left->cnt+right->cnt;
        return;
    }
    void removeRange(int L, int R) {
        remove(L,R-1);
    }
};


/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */