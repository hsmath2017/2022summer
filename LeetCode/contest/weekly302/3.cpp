#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    class T{
    public:
        string str;
        int index;
        T(string s,int i):str(s),index(i){}
    };
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int len=nums[0].length();
        auto cmp=[](const T& T1,const T& T2){
            if(T1.str==T2.str){
                return T1.index<T2.index;
            }
            return T1.str<T2.str;
        };
        map<int,vector<T>> M;
        set<int> weis;
        for(auto it:queries){
            int wei=it[1];
            weis.insert(wei);
        }
        for(auto it:weis){
            int now=it;
            for(int i=0;i<nums.size();i++){
                string str=nums[i].substr(len-now,now);
                T tmp(str,i);
                M[now].push_back(tmp);
            }
            sort(M[now].begin(),M[now].end(),cmp);
        }
        for(auto it:queries){
            int wei=it[1];
            int order=it[0]-1;
            res.push_back(M[wei][order].index);
        }
        return res;
    }
};