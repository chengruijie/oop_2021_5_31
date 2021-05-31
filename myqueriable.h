#pragma once
#include<vector>
#include<list>
#include<functional>
using namespace std;

template<class T>
class MyQueriable{
public:
    T* data;
    int len;

    MyQueriable(int a, int b):len(b){data= new T[a];}
    void pushback(T a){
        data[len] =a;
        len++;
    }
    int size(){return len;}
    T & operator[](int index){return data[index];}
    MyQueriable<T> where(function<T(bool)> fn){
        MyQueriable<T> other(len ,0);
        for(int i=0; i<len ;++i){
            if(fn(data[i])==true)other.pushback(data[i]);
        }
        return other;
    }
    MyQueriable<T> apply(function<T(T)> fn){
        MyQueriable<T> other(len ,len);
        for(int i=0; i<len ;++i){
            other.data[i]=fn(data[i]);
        }
        return other;
    }
    T sum(){
        T a=data[0];
        for(int i=1; i<len ;++i)a+=data[i];
        return a;
    }
    ~MyQueriable(){delete[] data;}
};


template<class T>
MyQueriable<T> from(vector<T> a){
    MyQueriable<T> other(a.size() ,a.size());
    int i=0;
    for(auto it=a.begin(); it!=a.end() ;++it){
        other.data[i]=*it;
        i++;
    }
    return other;
}
template<class T>
MyQueriable<T> from(list<T> a){
    MyQueriable<T> other(a.size() ,a.size());
    int i=0;
    for(auto it=a.begin(); it!=a.end() ;++it){
        other.data[i]=*it;
        i++;
    }
    return other;
}