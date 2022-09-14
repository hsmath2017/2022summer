#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using pii=pair<int,int>;//points
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pii> inner_pts;
        for(auto v:circles){
            int x=v[0];
            int y=v[1];
            int r=v[2];
            for(int t=-r;t<=r;t++){
                int d=floor(sqrt(r*r-t*t));
                for(int lambda=x-d;lambda<=x+d;lambda++){
                    pii p(lambda,y+t);
                    inner_pts.insert(p);
                }
            }
        }
        return inner_pts.size();
    }
};