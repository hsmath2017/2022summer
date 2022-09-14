#include<bits/stdc++.h>
using namespace std;
//Method: Bisection Find
class Solution {
public:
    bool check(int guess,const int n,const int index,const int maxSum){
        //First, consider the Left-Hand Part
        int min_sum=0;
        if(index<guess){
            min_sum+=(2*guess-index)*(index+1)/2;
        }else{
            min_sum+=((guess)*(guess+1)/2-guess+index+1);
        }
        //Then, consider the Right-Hand Part
        if(n-index<=guess){
            min_sum+=(2*guess-n+index)*(n-1-index)/2;
        }else{
            min_sum+=((guess)*(guess-1)/2+n-index-guess);
        }
        if(min_sum<=maxSum){
            return true;
        }else{
            return false;
        }
    }
    int bisect_find(int Left,int Right,const int n,const int index,const int maxSum){
        if(Left>Right){
            return Right;
        }
        int Mid=(Left+Right)/2;
        if(check(Mid,n,index,maxSum)){
            return bisect_find(Mid+1,Right,n,index,maxSum);
        }else{
            return bisect_find(Left,Mid-1,n,index,maxSum);
        }
    }
    int maxValue(int n, int index, int maxSum) {
        int res;
        res=bisect_find(1,maxSum,n,index,maxSum);
        return res;
    }
};