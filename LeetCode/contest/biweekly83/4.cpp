#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void fillset(set<int>& s,int k){
        for(int i=1;i<=k;i++){
            s.insert(i);
        }
    }
    int shortestSequence(vector<int>& rolls, int k) {
        int res=0;
        set<int> eles;
        fillset(eles,k);
        for(auto c:rolls){
            eles.erase(c);
            if(eles.size()==0){
                res++;
                fillset(eles,k);
            }
        }
        res++;
        return res;
    }
};