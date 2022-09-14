#include<bits/stdc++.h>
using namespace std;
class StockPrice {
public:
    map<int,int> time2price;
    int nowtimestamp;
    multiset<int> prices;
    StockPrice() {
        nowtimestamp=0;
    }
    
    void update(int timestamp, int price) {
        if(timestamp>nowtimestamp){
            nowtimestamp=timestamp;
        }
        if(time2price[timestamp]){
            auto iter=prices.find(time2price[timestamp]);
            prices.erase(iter);
        }
        time2price[timestamp]=price;
        prices.insert(price);
    }
    
    int current() {
        return time2price[nowtimestamp];
    }
    
    int maximum() {
        auto iter=prices.end();
        iter--;
        return *iter;
    }
    
    int minimum() {
        return *prices.begin();
    }
};
