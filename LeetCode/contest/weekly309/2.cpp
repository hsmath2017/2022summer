#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD=1e9+7;
    int comb(int a,int b){
        int c[1001][1001];
	    for(int i=1;i<=b;i++)
	    {
		    c[i][0]=1;
		    c[i][i]=1;
	    }
	    for(int i=1;i<=a;i++)
		    for(int j=1;j<i;j++)
			    c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
        return c[a][b];
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int dist=abs(endPos-startPos);
        if(dist>k){
            return 0;
        }
        int mid=k-dist;
        if(mid%2){
            return false;
        }
        int right=dist+mid/2;
        int left=k-right;
        int ans=comb(left,left+right);
        return ans;
    }
};