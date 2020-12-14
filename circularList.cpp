#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    friend class circleList;
};
class circleList{
    private:
    Node* cursor;
    public:
    circleList(){cursor=0;}//constructor
    bool empty(){return cursor==NULL;}
    int front(){return cursor->next->data;}
    int back(){return cursor->data;}
    void add(int val);
    void advance(){cursor=cursor->next;}
    void remove();
    void print(){
        Node* temp=cursor;
        if(cursor!=NULL){
            do{
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            while(temp!=cursor);
        }
    }
};
void circleList::add(int val){
    Node* node=new Node;
    node->data=val;
    if(cursor==NULL){
        node->next=node;
        cursor=node;
    }
    else{
        node->next=cursor->next;
        cursor->next=node;
    }
}
void circleList::remove(){
    Node* node=cursor->next;
    if(node==cursor)
        cursor=NULL;
    else
        cursor->next=node->next;
    delete node;
}
int main(){
    circleList list;
    list.add(1);
    list.add(2);
    list.add(3);
    cout<<"Printing cicular list"<<endl;
    list.print();
    cout<<"Advancing the list"<<endl;
    list.advance();
    list.print();
    cout<<"Advancing again"<<endl;
    list.advance();
    list.print();
    cout<<"Removing element from the list"<<endl;
    list.remove();
    list.print();
    

return 0;    
}