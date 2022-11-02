#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(const string& s1,const string& s2){
        int diff=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                diff++;
            }
        }
        if(diff<=2){
            return true;
        }else{
            return false;
        }
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n=queries.size();
        int m=dictionary.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(queries[i],dictionary[j])){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};