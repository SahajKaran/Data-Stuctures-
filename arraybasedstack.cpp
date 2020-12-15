#include<iostream>
using namespace std;

template <typename t>
class stack{
    private:
    t* array;//array of elemnts
    int capacity;
    int topp;

    public:
    stack(int cap=10000)
    :array(new t[cap]),capacity(cap),topp(-1){};
    int size(){return topp+1;}
    bool empty(){return topp<0;}
    const t& top(){return array[topp];}
    void push(const t& val){
        array[++topp]=val;
    };
    void pop(){
        --topp;
    }
};

int main(){
    stack<int> arr;
  
    for(int i=0;i<10;i++){
        arr.push(i);
        cout<<"Pushed: "<<i<<" "<<endl;
    }
    cout<<"Printing after poping 3 times we get"<<endl;
    arr.pop();
    arr.pop();
    arr.pop();
    for(int i=0;i<arr.size();i++){
        cout<<i<<" "<<endl;
    }
    return 0;
}