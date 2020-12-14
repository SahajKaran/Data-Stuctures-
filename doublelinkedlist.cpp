#include<iostream>
#include<string>
using namespace std;
class Node{ //linked list node
    private:
        int elem; //node element
        Node* next;
        Node* prev;
        friend class Linkedlist; //allowing Linked list access
}*start;
class Linkedlist{//doubly linked list
    private:
    Node* header;
    Node* trailer;
    public:
    Linkedlist();//constructor    
    void create(int val){
        Node* node,*temp;
        temp=new Node;
        temp->elem=val;
        temp->next=NULL;
        if(start==NULL){
            temp->prev=NULL;
            start=temp;
        }
        else{
            node=start;
            while(node->next!=NULL)
                node=node->next;
            node->next=temp;
            temp->prev=node;
        }
    }
    bool empty(){return header->next==trailer;}
    const int front(){return header->next->elem;}//returns element at the start 
    const int back(){return trailer->next->elem;}//returns element at the end

    void add(int element);//insert new node
    void remove(int val);
    int count(){
        Node* node=start;
        int count=0;
        while(node!=NULL){
            node=node->next;
            count++;
        }
    return count;
    }
    void print(){
        Node* node;
        if(start==NULL){
            cout<<"List is empty";
            return;
        }
        node=start;
        cout<<"List is:"<<endl;
        while(node!=NULL){
            cout<<node->elem<<" ";
            node=node->next;
        }

    }

};
Linkedlist::Linkedlist(){   //constructor
    header=new Node;
    trailer=new Node;//create sentinals and point them to each other
    header->next=trailer;
    trailer->prev=header;
}

void Linkedlist::add(int val){
    Node* node;
    node=new Node;
    node->prev=NULL;
    node->elem=val;
    node->next=start;
    start->prev=node;
    start=node;
}
void Linkedlist::remove(int val){
    Node* node, *temp;
    if(start->elem==val){
        node=start;
        start=start->next;
        start->prev=NULL;
        free(node);
        return;
    }
    temp=start;
    while(temp->next->next!=NULL){
        if(temp->next->elem==val){
            node=temp->next;
            temp->next=node->next;
            node->next->prev=temp;
            free(node);
            return;
        }
    temp=temp->next;
    if(temp->next->elem==val){
        node=temp->next;
        free(node);
        temp->next=NULL;
    }   
    }
}  
int main(){
    Linkedlist dlist;
    cout<<"List is:"<<endl;
    dlist.create(1);
    dlist.add(2);
    dlist.add(3);
    dlist.add(4);
    dlist.print();
    cout<<endl;
    cout<<"removing 3 from the list"<<endl;
    dlist.remove(3);
    dlist.print();
    cout<<"Total elements in the list"<<endl;
    cout<<dlist.count()<<endl;

    return 0;
}