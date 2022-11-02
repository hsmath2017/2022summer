#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    std::vector<int> ufs;
    bool similar(const string& s1,const string& s2){
        int diff=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                diff++;
            }
        }
        return diff==2;
    }
    int find(int x){
        if(x==ufs[x]){
            return x;
        }
        ufs[x]=find(x);
        return ufs[x];
    }
    void Union(int a,int b){
        int ra=find(a);
        int rb=find(b);
        ufs[ra]=rb;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        ufs.resize(n);
        vector<vector<int>> relations;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(similar(strs[i],strs[j])){
                    vector<int> v{i,j};
                    relations.push_back(v);
                }
            }
        }
        for(auto rel:relations){
            Union(rel[0],rel[1]);
        }
        set<int> vals;
        for(int i=0;i<n;i++){
            vals.insert(find(i));
        }
        return vals.size();
    }
};