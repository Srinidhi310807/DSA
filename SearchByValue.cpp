#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
}Node;
Node* InsertTail(Node* head, int val){
    Node* newNode= new Node(val);
    if(!head){
        head=newNode;
        return head;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newNode;
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
void Search(Node* head,int val){
    int pos=0;
    Node* temp=head;
    while(temp){
        if(temp->data==val){
            cout<<val<<" found at position "<<pos;
            return;
        }
        else{
            pos++;
            temp=temp->next;
        }
    }
    cout<<val<<" not found in the linked list"<<endl;
    return;
}
int main(){
    Node* head=NULL;
    int val,n;
    cout<<"Enter number of data to insert: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter data: ";
        cin>>val;
        head=InsertTail(head,val);
    }
    Display(head);
    cout<<"Enter value to search: ";
    cin>>val;
    Search(head,val);
    return 0;
}