#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftgreater(n,-1);
        vector<int> rightgreater(n,n);
        stack<int> monostack;
        for(int i=n-1;i>=0;i--){
            while(!monostack.empty()&&heights[i]>heights[monostack.top()]){
                int d=monostack.top();
                leftgreater[d]=i;
                monostack.pop();
            }
            monostack.push(i);
        }
        while(!monostack.empty()){
            monostack.pop();
        }
        for(int i=0;i<n;i++){
            while(!monostack.empty()&&heights[i]>heights[monostack.top()]){
                int d=monostack.top();
                rightgreater[d]=i;
                monostack.pop();
            }
            monostack.push(i);
        }
        for(int i=0;i<n;i++){
            cout<<leftgreater[i]<<" "<<rightgreater[i]<<endl;
        }
        return 0;
    }
};