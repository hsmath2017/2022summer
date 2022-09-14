#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int need_energy=0;
        for(auto c:energy){
            need_energy+=c;
        }
        need_energy++;
        int hours=0;
        hours=hours+max(0,need_energy-initialEnergy);
        vector<int> formal_exp;
        int now=0;
        for(auto c:experience){
            now+=c;
            formal_exp.push_back(now);
        }
        int need_exp=formal_exp[0]+1;
        for(int i=1;i<experience.size();i++){
            if(experience[i]>=formal_exp[i-1]){
                need_exp=max(need_exp,experience[i]+1-formal_exp[i-1]);
            }
        }
        hours=hours+max(0,need_exp-initialExperience);
        return hours;
    }
};