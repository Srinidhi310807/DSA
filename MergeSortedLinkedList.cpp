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

Node* Insert(Node* head,int val){
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
    while(temp->next){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    return;
}
Node* merge(Node* head1,Node* head2){
    if(!head1&&!head2) return NULL;
    if(!head1) return head2;
    if(!head2) return head1;
    Node* ptr1=head1;
    Node* ptr2=head2;
    Node* dummy=new Node(0);
    Node* temp=dummy;
    while(ptr1&&ptr2){
        if(ptr1->data<ptr2->data){
            temp->next=ptr1;
            ptr1=ptr1->next;
            temp=temp->next;
        }
        else if(ptr2->data<ptr1->data){
            temp->next=ptr2;
            ptr2=ptr2->next;
            temp=temp->next;
        }
        else{
            temp->next=ptr1;
            temp=temp->next;
            temp->next=ptr2;
            temp=temp->next;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    while(ptr1){
        temp->next=ptr1;
        temp=temp->next;
        ptr1=ptr1->next;
    }
    while(ptr2){
        temp->next=ptr2;
        temp=temp->next;
        ptr2=ptr2->next;
    }
    return dummy->next;
}
int main(){
    int n1,n2,val;
    Node* head1=NULL;
    Node* head2=NULL;
    Node* head=NULL;
    cout<<"Enter number of nodes for Sorted Linked List 1: ";
    cin>>n1;
    for(int i=0;i<n1;i++){
        cout<<"Enter node value: ";
        cin>>val;
        head1=Insert(head1,val);
    }
    cout<<"Enter number of nodes for Sorted Linked List 2: ";
    cin>>n2;
    for(int i=0;i<n2;i++){
        cout<<"Enter node value: ";
        cin>>val;
        head2=Insert(head2,val);
    }
    cout<<"Linked List 1:"<<endl;
    Display(head1);
    cout<<"Linked List 2:"<<endl;
    Display(head2);
    head=merge(head1,head2);
    cout<<"Merged Sorted Linked List: "<<endl;
    Display(head);
    return 0;
}