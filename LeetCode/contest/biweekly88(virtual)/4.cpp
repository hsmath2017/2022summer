#include<bits/stdc++.h>
using namespace std;
using ll=long long;
class BIT{
private:
    vector<int> tree;
public:
    BIT(int n){
        tree.resize(n);
    }
    void add(int x){
        while(x<tree.size()){
            tree[x]++;
            x+=(x&(-x));
        }
    }
    int query(int x){
        int ans=0;
        while(x>0){
            ans+=tree[x];
            x&=(x-1);
        }
        return ans;
    }
};
class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& nums2, int diff) {
        int n = a.size();
        for (int i = 0; i < n; ++i)
            a[i] -= nums2[i];
        auto b = a;
        sort(b.begin(), b.end()); // 配合下面的二分，离散化
        long ans=0L;
        BIT t(n+1);
        for(int x:a){
            ans+=t.query(upper_bound(b.begin(),b.end(),x+diff)-b.begin());
            t.add(lower_bound(b.begin(),b.end(),x)-b.begin()+1);
        }
        return ans;
    }
};