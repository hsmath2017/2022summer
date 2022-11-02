#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string oddString(vector<string>& words) {
        vector<vector<int>> diffarr;
        int n=words.size();
        diffarr.resize(n);
        int m=words[0].length();
        for(int i=0;i<n;i++){
            for(int j=0;j<m-1;j++){
                diffarr[i].push_back(words[i][j+1]-words[i][j]);
            }
        }
        int ans;
        for(int i=0;i<m-1;i++){
            map<int,int> appeartimes;
            for(int j=0;j<n;j++){
                appeartimes[diffarr[j][i]]++;
            }
            int target;
            bool flag=false;
            for(auto it:appeartimes){
                if(it.second==1){
                    flag=true;
                    target=it.first;
                }
            }
            if(flag){
                for(int j=0;j<n;j++){
                    if(diffarr[j][i]==target){
                        ans=j;
                        break;
                    }
                }
                break;
            }
        }
        return words[ans];
    }
};