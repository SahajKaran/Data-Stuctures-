#include<iostream>
using namespace std;
template<typename t>
class Array{
    private:
        t*array; //vectors are the same as dynamic arrays
        int len;
        int capacity;
    public:
        Array(int size=4)
        :array(new t[size]), capacity(size)
        {len=-1;}

        int size(){return len+1;}
        int cap(){return capacity;}
    
        void add(t& element){
            if(size()==cap()){
                capacity=2*capacity;
                t* newarr=new t[capacity];
                
                for(int i = 0; i < size(); i++) {
			    newarr[i] = array[i];
                }
                delete[]array;
                array=new t[capacity];
                	for(int i = 0; i< size(); i++){
		    	array[i] = newarr[i];
                }
	        	delete[]newarr;  
            }
            len++;
            array[len]=element;
        }

        void print(){
            for(int i=0;i<size();i++){
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }     
};
int main(){
    Array<int> arr;
    for(int i=1;i<10;i++){
        arr.add(i);
    }
    arr.print();
    cout<<endl;
     for(int i=10;i<14;i++){
        arr.add(i);
    }
    arr.print();
}