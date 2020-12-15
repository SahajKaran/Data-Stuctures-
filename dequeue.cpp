#include<iostream>
using namespace std;
class Deque{
    private:
    int dq[1000];
    int size;
    int capacity,front,rear;
    public:
    Deque(int cap){ //constructor;
        capacity=cap;
        rear=0;
        front=-1;
    }
    bool isfull(){
        return ((front == 0 && rear == size-1)||front == rear+1);
    }
    bool empty(){return (front==-1);}

    void insertFront(int data){
       if(isfull()){
           cout<<"overflow"<<endl;
       }
        if(front==-1){
            front=0;
            rear=0;
        }
        else if(front==0)
            front=capacity-1;
        else
            front=front-1;     
        dq[front]=data;
    }
    void insertBack(int data){
        if(isfull()){
           cout<<"overflow"<<endl;
       }
        if(front==-1){
            front=0;
            rear=0;
        }
        else if(rear==size-1)
            rear=0;
        else 
            rear=rear+1;
        dq[rear]=data;
    }

    void deleteFront(){
        if(empty()){
            cout<<"Empty"<<endl;
        }
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else    
            if(front==capacity-1)
                front=0;
            else 
                front=front+1;
    }
   void deleteBack(){
        if(empty()){
            cout<<"Empty"<<endl;
        }
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(rear==0)
            rear=capacity-1;
        else 
            rear=rear-1;
    }
    void fronte(){
        cout<<"front is:"<<dq[front]<<endl;
    }
    void reare(){
        cout<<"rear is:"<<dq[rear]<<endl;
    }
    
    void print(){   
        for(int i=0;i<capacity;i++){
            cout<<dq[i]<<" ";
        } 
    }
};
int main(){
    Deque q(6);
    cout<<"inserting elements :"<<endl;
    q.insertBack(2);
    q.insertBack(3);
    q.insertFront(1);
    q.insertFront(0);
    q.insertBack(4);
    cout<<"deque is :"<<endl;
    q.print();
    cout<<endl;
    q.fronte();
    q.reare();
    cout<<"deleting front and rear and reprinting"<<endl;
    q.deleteBack();
    q.deleteFront();
    q.fronte();
    q.reare();
  
    return 0;
}