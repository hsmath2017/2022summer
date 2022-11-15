#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    const ll inf=1e16;
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        ll m=robot.size();
        ll n=factory.size();
        vector<vector<ll>> dp(n,vector<ll>(m,inf));
        function<ll(int,int)> f=[&](int i,int j)->ll{
            if(j==m){
                return (ll)0;
            }
            if(i==n){
                return inf;
            }
            if(dp[i][j]!=inf){
                return dp[i][j];
            }
            ll res=f(i+1,j);
            ll sum=0;
            for(int k=1;k<=factory[i][1]&&j+k-1<m;k++){
                sum=sum+(ll)(abs(factory[i][0]-robot[j+k-1]));
                res=min(res,sum+f(i+1,j+k));
            }
            dp[i][j]=min(dp[i][j],res);
            return res;
        };
        return f(0,0);
    }
};