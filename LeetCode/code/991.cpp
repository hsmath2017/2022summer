#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue>=target){
            return startValue-target;
        }else{
            if(target%2==0){
                return 1+brokenCalc(startValue,target/2);
            }else{
                return 2+brokenCalc(startValue,(target+1)/2);
            }
        }
    }
};