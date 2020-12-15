#include<iostream>
#include<string>
using namespace std;

class Queue{
    private:
    int* queue;
    int size;
    int capacity,front,rear;
    public:
    Queue(int c){//constructor
        front=rear=0;
        capacity=c;
        queue= new int;
    }
    ~Queue(){delete[] queue;}//destructor

    bool empty(){return size==0;}
    
    void displayfront(){
        if(front==rear){
            cout<<"Queue is empty";
        }
        cout<<"Front element is :"<<queue[front]<<endl;
    }
   
    void enqueue(int data){//add element to the end
        if(capacity==rear){
            cout<<"Queue is full"<<endl;
        }
        else{
            queue[rear]=data;
            rear++;
        }
    }
    void dequeue(){//remove element at the front
        if(front==rear){
            cout<<"Queue is empty"<<endl;
        }
        else{
            for(int i=0;i<rear-1;i++){
                queue[i]=queue[i+1];
            }
            rear--;
        }
    }
    void print(){ //print queue

        if(front==rear){
            cout<<"Queue is empty"<<endl;
        }
        for(int i=front;i<rear;i++){
            cout<<queue[i]<<" ";
        }
    }
};
int main(){
    Queue q(5);
    cout<<"printing without enqueing anything"<<endl;
    q.print();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.print();
    cout<<endl;
    q.enqueue(5);
    q.print();
    cout<<endl;
    cout<<"going over set size of the queque"<<endl;
    q.enqueue(6);
    q.print();
    cout<<endl<<"dequeing twice and printing"<<endl;
    q.dequeue();
    q.dequeue();
    q.print();
    cout<<endl<<"printing element at the front of queue"<<endl;
    q.displayfront();
}
