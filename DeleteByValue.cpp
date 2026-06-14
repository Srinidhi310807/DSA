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
Node* Delete(Node* head,int val){
    if(!head){
        cout<<"Linked List is empty!!";
        return head;
    }
    if(head->data==val){
        Node* temp=head->next;
        head->next=NULL;
        head=temp;
        return head;
    }
    Node* prev=head;
    Node* temp=head->next;
    while(temp){
        if(temp->data==val){
            prev->next=temp->next;
            temp->next=NULL;
            cout<<"first occurence of "<<val<<" has been deleted"<<endl;
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    cout<<val<<" not found in the linked list";
    return head;
}
int main(){
    Node* head=NULL;
    int val,n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter node value: ";
        cin>>val;
        head=InsertTail(head,val);
    }
    Display(head);
    cout<<"Enter value to delete: ";
    cin>>val;
    head=Delete(head,val);
    cout<<"After deleting ";
    Display(head);
    return 0;
}