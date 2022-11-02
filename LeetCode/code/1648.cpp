#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    const int MOD=1e9+7;
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(),inventory.end(),std::greater<int>());
        vector<ll> presum;
        ll s=0;
        for(auto c:inventory){
            s=s+(ll)c;
            presum.push_back(s);
        }
        vector<ll> need_orders;
        for(int i=0;i<presum.size();i++){
            ll d=presum[i]-(ll)inventory[i]*(i+1);
            need_orders.push_back(d);
        }
        int index=0;
        for(int i=0;i<need_orders.size();i++){
            if(orders>=need_orders[i]){
                index=i;
            }else{
                break;
            }
        }
        ll ans=0;
        int remain=orders-need_orders[index];
        if(remain==0){
            int target=inventory[index];
            for(int i=0;i<=index;i++){
                ans=ans+(ll)(target+1+inventory[i])*(ll)(inventory[i]-target)/2;
                ans%=MOD;
            }
            return ans;
        }
        int target_1=inventory[index]-remain/(index+1);
        int target_2=target_1-1;
        int num_target_2=remain%(index+1);
        for(int i=0;i<num_target_2;i++){
            ans=ans+(ll)(target_2+1+inventory[i])*(ll)(num_target_2)/2;
            ans%=MOD;
        }
        for(int i=num_target_2;i<=index;i++){
            ans=ans+(ll)(target_1+1+inventory[i])*(ll)(index+1-num_target_2)/2;
            ans%=MOD;
        }
        return ans;
    }
};