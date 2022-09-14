#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestPalindromic(string num) {
        map<char,int> times;
        for(auto c:num){
            times[c]++;
        }
        string palindrom_root;
        for(char i='9';i>='1';i--){
            int d=times[i]/2;
            for(int j=0;j<d;j++){
                palindrom_root.push_back(i);
            }
        }
        if(palindrom_root.empty()){
            for(char i='9';i>='0';i--){
                if(times[i]){
                    string str;
                    str.push_back(i);
                    return str;
                }
            }
        }else{
            int d=times['0']/2;
            for(int j=0;j<d;j++){
                palindrom_root.push_back('0');
            }
        }
        string front=palindrom_root;
        reverse(palindrom_root.begin(),palindrom_root.end());
        string end(palindrom_root);
        string mid;
        for(char i='9';i>='0';i--){
            if(times[i]%2){
                mid.push_back(i);
                break;
            }
        }
        string ans=front+mid+end;
        return ans;
    }
};