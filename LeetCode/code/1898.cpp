#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(const string& s,const string& p,const vector<int>& removable,int num){
        map<int,bool> remove;
        for(int i=0;i<=num;i++){
            remove[removable[i]]=true;
        }
        int ptr_of_p=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==p[ptr_of_p]&&remove[i]==false){
                ptr_of_p++;
            }
            if(ptr_of_p==p.length()){
                return true;
            }
        }
        return false;
    }
    int binary_find(const string& s,const string& p,const vector<int>& removable,int fptr,int rptr){
        if(fptr>rptr){
            return rptr;
        }
        int mid=(fptr+rptr)/2;
        bool flag=check(s,p,removable,mid);
        if(flag){
            return binary_find(s,p,removable,mid+1,rptr);
        }else{
            return binary_find(s,p,removable,fptr,mid-1);
        }
    };
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n=removable.size();
        int res=binary_find(s,p,removable,0,n-1)+1;
        return res;
    }
};