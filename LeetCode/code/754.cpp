#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int ans=0;
        int s=0;
        int i=0;
        while(s<target){
            i++;
            s+=i;
        }
        if(s==target){
            return i;
        }else if((s-target)%2==0){
            return i;
        }else{
            s=s+i+1;
            if((s-target)%2==0){
                return i+1;
            }else{
                return i+2;
            }
        }
    }
};