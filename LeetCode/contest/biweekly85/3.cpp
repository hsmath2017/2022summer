#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff;
        int n=s.length();
        diff.resize(s.length());
        for(auto v:shifts){
            if(v[2]==0){
                diff[v[0]]--;
                if(v[1]+1<n){
                    diff[v[1]+1]++;
                }
            }else{
                diff[v[0]]++;
                if(v[1]+1<n){
                    diff[v[1]+1]--;
                }
            }
        }        
        vector<int> arr(n);
        arr[0]=diff[0];
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1]+diff[i];
        }
        vector<int> narray;
        for(auto c:s){
            narray.push_back(c-'0');
        }
        for(int i=0;i<narray.size();i++){
            narray[i]+=arr[i];
            narray[i]%=26;
            if(narray[i]<0){
                narray[i]+=26;
            }
        }
        for(int i=0;i<s.length();i++){
            s[i]=('a'+narray[i]);
        }
        return s;
    }
};
