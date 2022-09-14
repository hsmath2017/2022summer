#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //bisection find
    bool check(const vector<int>& position,int guess,int m){
        int mark=position[0];
        int nums=1;
        for(auto c:position){
            if(c-mark>=guess){
                mark=c;
                nums++;
            }
        }
        if(nums<m){
            return false;
        }else{
            return true;
        }
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int left=1;
        int right=*(position.end()-1)-*position.begin();
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(check(position,mid,m)){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};