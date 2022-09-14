#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,bool> M;
        for(auto c:s){
            if(M[c]==false){
                M[c]=true;
            }
            else{
                return c;
            }
        }
        return '0';
    }
};