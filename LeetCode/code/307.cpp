#include<bits/stdc++.h>
using namespace std;
class NumArray {
public:
    vector<int> sum;
    int n;
    void modify(int o,int l,int r,int index,int val){
        if(l==r){
            sum[o]=val;
            return;
        }
        int mid=(l+r)/2;
        if(index>mid){
            modify(o*2+1,mid+1,r,index,val);
        }else{
            modify(o*2,l,mid,index,val);
        }
        sum[o]=sum[o*2]+sum[o*2+1];
        return;
    }
    
    int query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return sum[o];
        }
        int ans=0;
        int mid=(l+r)/2;
        if(mid>=L){
            ans+=query(o*2,l,mid,L,R);
        }
        if(mid<R){
            ans+=query(o*2+1,mid+1,r,L,R);
        }
        return ans;
    }
    
    NumArray(vector<int>& nums) {
        n=nums.size();
        sum.resize(4*n);
        for(int i=0;i<n;i++){
            modify(1,0,n-1,i,nums[i]);
        }
    }
    
    void update(int index, int val) {
        modify(1,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */