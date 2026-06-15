#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
}Node;
void Insert(Node** head,Node** tail,int val){
    Node* newNode=new Node(val);
    if(!*head&&!*tail){
        *head=newNode;
        *tail=newNode;
        return;
    }
    (*tail)->next=newNode;
    *tail=newNode;
    return;
}
void Display(Node* head){
    if(!head){
        cout<<"Linked List is empty!!"<<endl;
        return;
    }
    cout<<"Linked List: "<<endl;
    Node* temp=head;
    while(temp->next){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    return;
}
int main(){
    int n,val;
    cout<<"Enter number of nodes: ";
    cin>>n;
    Node* head=NULL;
    Node* tail=NULL;
    for(int i=0;i<n;i++){
        cout<<"Enter node value: ";
        cin>>val;
        Insert(&head,&tail,val);
    }
    Display(head);
    cout<<"All elements are inserted in O(1) time"<<endl;
    return 0;
}