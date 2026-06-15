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

Node* Insert(Node* head,int val){
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
Node* deleteMiddle(Node* head){
    if(!head||!head->next) return NULL;
    Node* prev=NULL;
    Node* slow=head;
    Node* fast=head;
    while(fast&&fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=slow->next;
    delete slow;
    return head;
}
int main(){
    Node* head=NULL;
    int val,n;
    cout<<"Enter number of data to insert: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter data: ";
        cin>>val;
        head=Insert(head,val);
    }
    cout<<"Before deleting: ";
    Display(head);
    head=deleteMiddle(head);
    cout<<"After deleting: ";
    Display(head);
    return 0;
}