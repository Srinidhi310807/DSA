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

Node* InsertTail(Node* head,int val){
    Node* newNode=new Node(val);
    if(!head){
        head=newNode;
        return head;
    }
    Node* temp=head;
    while(temp->next) temp=temp->next;
    temp->next=newNode;
    return head;
}
void Display(Node* head){
    if(!head){
        cout<<"Linked List is empty!!"<<endl;
        return;
    }
    Node* temp=head;
    cout<<"Linked List: ";
    while(temp->next){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    return;
}
Node* Reverse(Node* head){
    if(!head){
        cout<<"Linked List is empty!";
        return head;
    }
    if(!head->next) return head;
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int main(){
    Node* head=NULL;
    int n,val;
    cout<<"Enter number of nodes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter node value: ";
        cin>>val;
        head=InsertTail(head,val);
    }
    Display(head);
    head=Reverse(head);
    cout<<"Reversed ";
    Display(head);
    return 0;
}