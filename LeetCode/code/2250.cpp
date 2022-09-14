#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using pt=vector<int>;
    int binary_find(int target,const vector<pt>& pts,int left,int right){
        if(pts[right][0]<=target){
            return right+1;
        }
        if(left==right){
            return left;
        }
        int mid=(left+right)/2;
        if(pts[mid][0]>target){
            return binary_find(target,pts,left,mid);
        }else{
            return binary_find(target,pts,mid+1,right);
        }
    };
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        auto cmp1=[](const pt& p1,const pt& p2){
            return p1[1]<p2[1];
        };
        auto cmp2=[](const pt& p1,const pt& p2){
            return p1[0]<p2[0];
        };
        sort(rectangles.begin(),rectangles.end(),cmp1);
        map<int,vector<pt>> y2pts;
        vector<pt> nowvec;
        int n=rectangles.size();
        int id=0;
        for(int i=1;i<=100;i++){
            while(id<n&&rectangles[id][1]==i){
                nowvec.push_back(rectangles[id]);
                id++;
            }
            y2pts[i]=nowvec;
        }
        for(int i=1;i<=100;i++){
            sort(y2pts[i].begin(),y2pts[i].end(),cmp1);
        }
        vector<int> ans;
        for(auto p:points){
            int y=p[1];
            auto pts=y2pts[y];
            int x=binary_find(p[0],pts,0,pts.size()-1);
            ans.push_back(x);
        }
        return ans;
    }
};