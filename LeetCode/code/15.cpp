#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        if(n<3){
            return ans;
        }
        map<int,int> avail_times;
        for(auto c:nums){
            avail_times[c]++;
        }
        set<int> numset;
        for(auto v:nums){
            numset.insert(v);
        }
        vector<int> except_compete;
        for(auto c:numset){
            except_compete.push_back(c);
        }
        int m=except_compete.size();
        for(int i=0;i<m;i++){
            int j;
            if(avail_times[except_compete[i]]>1){
                j=i;
            }else{
                j=i+1;
            }
            for(j;j<m;j++){
                int target=-(except_compete[i]+except_compete[j]);
                if(target<except_compete[j]){
                    break;
                }else if(target>except_compete[j]){
                    if(avail_times[target]){
                        ans.push_back({except_compete[i],except_compete[j],target});
                        continue;
                    }
                }else{
                    if(except_compete[i]==except_compete[j]){
                        if(avail_times[target]>=3){
                            ans.push_back({except_compete[i],except_compete[j],target});
                        }
                    }else{
                        if(avail_times[target]>=2){
                            ans.push_back({except_compete[i],except_compete[j],target});
                        }
                    }
                }
            }
        }
        return ans;
    }
};