#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Binary_Search(const vector<int>& d,int dat,int Left,int Right){
        if(Left==Right){
            return Left;
        }
        int mid=(Left+Right)/2;
        if(d[mid]<=dat){
            return Binary_Search(d,dat,mid+1,Right);
        }else{
            return Binary_Search(d,dat,Left,mid);
        }
    };
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int> d;
        for(auto dat:obstacles){
            if(d.empty()==true||dat>=*(d.end()-1)){
                d.push_back(dat);
                ans.push_back(d.size());
            }else{
                int index=Binary_Search(d,dat,0,d.size()-1);
                d[index]=dat;
                ans.push_back(index+1);
            }
        }
        return ans;
    }
};