#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        vector<int> ones;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                ones.push_back(i);
            }
        }        
        int len=ones.size();
        if(ones[len-1]==len-1){
            return 0;
        }
        int second=0;
        while(ones[len-1]!=len-1){
            vector<int> newvec;
            if(ones[0]>0){
                newvec.push_back(ones[0]-1);
            }else{
                newvec.push_back(ones[0]);
            }
            for(int i=1;i<len;i++){
                if(ones[i]-ones[i-1]==1){
                    newvec.push_back(ones[i]);
                }else{
                    newvec.push_back(ones[i]-1);
                }
            }
            ones=newvec;
            second++;
        }
        return second;
    }
};