#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canChange(string start, string target) {
        vector<int> posL_st;
        vector<int> posR_st;
        vector<int> posL_tar;
        vector<int> posR_tar;
        for(int i=0;i<start.size();i++){
            if(start[i]=='L'){
                posL_st.push_back(i);
            }
            if(target[i]=='L'){
                posL_tar.push_back(i);
            }
            if(start[i]=='R'){
                posR_st.push_back(i);
            }
            if(target[i]=='R'){
                posR_tar.push_back(i);
            }
        }
        if(posL_st.size()!=posL_tar.size()||posR_st.size()!=posR_tar.size()){
            return false;
        }
        string tmp1,tmp2;
        for(auto c:start){
            if(c!='_'){
                tmp1.push_back(c);
            }
        }
        for(auto c:target){
            if(c!='_'){
                tmp2.push_back(c);
            }
        }
        if(tmp1!=tmp2){
            return false;
        }
        int tmp=0;
        for(int i=0;i<target.size();i++){
            if(start[i]=='R'){
                tmp++;
            }
            if(target[i]=='R'){
                tmp--;
            }
            if(tmp<0){
                return false;
            }
        }
        tmp=0;
        for(int i=target.size()-1;i>=0;i--){
            if(start[i]=='L'){
                tmp++;
            }
            if(target[i]=='L'){
                tmp--;
            }
            if(tmp<0){
                return false;
            }
        }
        return true;
    }
};