#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int gcd(int a,int b){
        if(a<b){
            swap(a,b);
        }
        if(b==0){
            return a;
        }
        else{
            return gcd(b,a%b);
        }
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        s.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            int tmp=nums[i];
            while(1){
                if(s.empty()){
                    s.push(tmp);
                    break;
                }
                int d=s.top();
                int x=gcd(d,tmp);
                if(x==1){
                    s.push(tmp);
                    break;
                }else{
                    s.pop();
                    tmp=d*tmp/x;
                }
            }
        }
        vector<int> ans;
        while(s.empty()==false){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};