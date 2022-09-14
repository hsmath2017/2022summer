#include<bits/stdc++.h>
using namespace std;
class Food{
public:
    string name;
    int score;
    Food(string s,int c){
        name=s;
        score=c;
    }
};
bool operator<(const Food& F1,const Food& F2){
    if(F1.score==F2.score){
        return F1.name<F2.name;
    }
    return F1.score>F2.score;
}
class FoodRatings {
private:
    map<string,set<Food>> M;
    map<string,Food> food2Food;
    map<string,string> food2type;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            Food f(foods[i],ratings[i]);
            food2Food[foods[i]]=f;
            food2type[foods[i]]=cuisines[i];
            M[cuisines[i]].insert(f);
        }
    }
    
    void changeRating(string food, int newRating) {
        Food f=food2Food[food];
        string cuisine=food2type[food];
        M[cuisine].erase(f);
        f.score=newRating;
        food2Food[food]=f;
        M[cuisine].insert(f);
    }
    
    string highestRated(string cuisine) {
        Food f=*M[cuisine].begin();
        return f.name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */