#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int,int> diff;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int M=0;
        for(auto I:intervals){
            diff[I[0]]++;
            diff[I[1]+1]--;
            M=max(M,I[1]+1);
        }
        int sum=0;
        int flag=false;
        vector<vector<int>> ans;
        vector<int> tmp;
        for(int i=0;i<=M;i++){
            sum+=diff[i];
            if(sum>0&&flag==false){
                tmp.push_back(i);
                flag=true;
            }
            else if(sum==0&&flag==true){
                tmp.push_back(i-1);
                ans.push_back(tmp);
                tmp.clear();
                flag=false;
            }
        }
        return ans;
    }
};