#include<bits/stdc++.h>
using namespace std;
template<class T>
class Ptr{
private:
    T* ptr;
    T* array;
    int sz;
public:
    template<int N>
        Ptr(T* p,T(&a)[N]);
    Ptr(T* p,T* a,int s);
    Ptr(T* p);

    Ptr& operator++();//++a
    Ptr operator++(int);//a++

    Ptr& operator--();
    Ptr operator--(int);

    T& operator*();
};