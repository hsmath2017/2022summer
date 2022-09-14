#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canTransform(string start, string end) {
        string start_but_X;
        string end_but_X;
        for(auto c:start){
            if(c!='X'){
                start_but_X.push_back(c);
            }
        }
        for(auto c:end){
            if(c!='X'){
                end_but_X.push_back(c);
            }
        }
        if(start_but_X!=end_but_X){
            return false;
        }
        vector<int> start_L_ind;
        vector<int> start_R_ind;
        vector<int> end_L_ind;
        vector<int> end_R_ind;
        int n=start.size();
        for(int i=0;i<n;i++){
            if(start[i]=='L'){
                start_L_ind.push_back(i);
            }
            if(start[i]=='R'){
                start_R_ind.push_back(i);
            }
            if(end[i]=='L'){
                end_L_ind.push_back(i);
            }
            if(end[i]=='R'){
                end_R_ind.push_back(i);
            }
        }
        for(int i=0;i<start_L_ind.size();i++){
            if(start_L_ind[i]<end_L_ind[i]){
                return false;
            }
        }
        for(int i=0;i<start_R_ind.size();i++){
            if(start_R_ind[i]>end_R_ind[i]){
                return false;
            }
        }
        return true;
    }
};