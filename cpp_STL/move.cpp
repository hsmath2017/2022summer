/**
 * @file move.cpp
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief test move constructor
 * @version 0.1
 * @date 2022-08-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
template<class T,int Dim>
class Vec{
private:
    T v[Dim];
public:
    Vec()=default;
    T& operator[](int index){
        return v[index];
    }
    const T& operator[](int index) const{
        return v[index];
    }
    Vec(const initializer_list<T>& list){
        int i=0;
        for(auto it=list.begin();it!=list.end();it++){
            v[i++]=*it;
        }
    }
    Vec(T d){
        for(int i=0;i<Dim;i++){
            v[i]=d;
        }
    }
    Vec(const Vec& v)=default;
    Vec& operator=(const Vec& v1){
        for(int i=0;i<Dim;i++){
            v[i]=v1[i];
        }
        return *this;
    }
    //Vec& operator=(Vec&& v2)=delete;
    Vec& operator+(T a){
        for(int i=0;i<Dim;i++){
            v[i]+=a;
        }
        cout<<"Member Function"<<endl;
        return *this;
    }
    //friend operator
    friend Vec<T,Dim> operator+(T a,const Vec<T,Dim>& input){
        Vec<T,Dim> ans;
        for(int i=0;i<Dim;i++){
            ans[i]=input[i]+a;
        }
        cout<<"Not Member Function"<<endl;
        return ans;
    }
    Vec& operator=(Vec&& v2){
        for(int i=0;i<Dim;i++){
            v[i]=v2[i];
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os,Vec<T,Dim>& v){
        for(int i=0;i<Dim;i++){
            os<<v[i]<<" ";
        }
        os<<endl;
        return os;
    }
};
int main(){
    Vec<int,2> init{2,3};
    Vec<int,2> arr1,arr2;
    Vec<int,2> test=100;
    arr1=init;
    cout<<init;
    arr2=move(init);
    cout<<init;
    cout<<arr1;
    cout<<arr2;
    arr1=arr1+2;
    arr2=2+arr1;
    cout<<arr1;
    cout<<arr2;
    cout<<test;
}