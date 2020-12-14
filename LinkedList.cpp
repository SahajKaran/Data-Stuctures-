#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
friend class Slinkedlist;
};
class Slinkedlist{
    public:
    Slinkedlist()
    : head(NULL){}//constructor
    Node*head;//pointer to the head of the node
    
    bool empty(){
        return head==NULL;
    }
    const int front(){
        return head->data;
    }
    void addfront(int ndata){
        Node* nnode=new Node();
        nnode->data=ndata;
        nnode->next=head;
        head=nnode;
    }
    void addback(int ndata){
        Node* nnode=new Node();
        Node* last=head;
        nnode->data=ndata;
        nnode->next=NULL;
        if(head==NULL){
            head=nnode;
        return;
        }
        while(last->next!=NULL){
           last=last->next;
        }
        last->next=nnode;
    }

    void removefront(){
        Node* old=head;
        head=old->next;
        delete old;   
    }
    void print(){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
};

int main(){
    Slinkedlist list;
    list.addfront(3);
    list.addfront(2);
    list.addfront(1);
    list.removefront();
    list.addfront(2);
    list.addback(5);
    list.addback(6);
    list.addback(50);
    list.addback(60);
    list.print();
    cout<<"printing front element of the list"<<endl;
    cout<<list.front();
 return 0;   
}