#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        vector<int> passengersnum;
        map<int,bool> available;
        int num=0;
        passengersnum.resize(buses.size());
        int i=0;
        for(auto c:passengers){
            available[c]=true;
            bool flag=false;
            while (c>buses[i])
            {
                passengersnum[i]=num;
                num=0;
                i++;
                if(i==buses.size()){
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
            num++;
        }
        if(i<buses.size()){
            passengersnum[i]=num;
        }
        for(int j=i+1;j<passengersnum.size();j++){
            passengersnum[j]=0;
        }
        int max_passenger=0;
        bool flag1=false;
        for(auto c:passengersnum){
            if(c<capacity){
                flag1=true;
            }else{
                flag1==false;
            }
            max_passenger+=min(c,capacity);
        }
        if(max_passenger>=passengers.size()||flag1==true){
            return buses[buses.size()-1];
        }
        int d=passengers[max_passenger-1];
        if(available[d]==false){
            return d;
        }else{
            for(;;d--){
                if(available[d]==false){
                    return d;
                }
            }
        }
        return d;
    }
};