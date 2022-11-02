#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>> graph(n);
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }        
        int target;
        function<int(int,int)> dfs=[&](int x,int fa)->int{
            int sum=nums[x];
            for(auto p:graph[x]){
                if(p!=fa){
                    int res=dfs(p,x);
                    if(res<0){
                        return -1;
                    }
                    sum+=res;
                }
                if(sum==target){
                    return 0;
                }else if(sum>target){
                    return -1;
                }else{
                    return sum;
                }
            }
        };
        int total = accumulate(nums.begin(), nums.end(), 0);
        int mx = *max_element(nums.begin(), nums.end());
        for(int i=total/mx;i>0;i--){
            if(total%i==0){
                target=total/i;
                if(dfs(0,-1)==0){
                    return i-1;
                }
            }
        }
        return 0;
    }
};