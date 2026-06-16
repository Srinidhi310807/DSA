#include<iostream>
using namespace std;
 typedef struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
}Node;
Node* Undo(Node* head){
    if(!head){
        cout<<"Linked list is empty so undo operation cannot be performed!"<<endl;
        return head;
    }
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
    return head;
}
Node* InsertFront(Node* head, int val){
    Node* newNode= new Node(val);
    if(!head){
        head=newNode;
        return head;
    }
    newNode->next=head;
    head=newNode;
    return head;
}
void Display(Node* head){
    if(!head){
        cout<<"Linked List is empty!";
        return;
    }
    Node* temp=head;
    cout<<"Linked List: "<<endl;
    while(temp->next){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    return;
}
int main(){
    Node* head=NULL;
    int val,ch;
    do{
        cout<<"1. Insert at Front"<<endl;
        cout<<"2. Undo operation"<<endl;
        cout<<"3. Display Linked List"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        switch(ch){
            case 1: {
                cout<<"Enter node value to insert: ";
                cin>>val;
                head=InsertFront(head,val);
                cout<<"Inserted successfully!!"<<endl;
                break;
            }
            case 2:{
                head=Undo(head);
                cout<<"Undo operation performed successfully"<<endl;
                break;
            }
            case 3:{
                Display(head);
                break;
            }
            case 4:{
                cout<<"Exiting..."<<endl;
                break;
            }
            default:{
                cout<<"Invalid choice!!"<<endl;
                break;
            }
        }
    }
    while(ch!=4);
    return 0;
}