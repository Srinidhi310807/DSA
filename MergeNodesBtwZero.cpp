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

Node* mergeNodes(Node* head) {
    Node* dummy=new Node(0);
    Node* temp=dummy;
    Node* ptr=head;
    int cnt=0;
    while(ptr){
        if(ptr->data==0&&cnt!=0){
            temp->next=new Node(cnt);
            temp=temp->next;
            cnt=0;
        }
        else if(ptr->data!=0){
            cnt+=ptr->data;
        }
        ptr=ptr->next;
    }
    return dummy->next;
}

Node* Insert(Node* head, int val){
    Node* newNode=new Node(val);
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
        cout<<"Linked List is empty!!"<<endl;
        return;
    }
    cout<<"Linked List: "<<endl;
    Node* temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    return;
}
int main(){
    int n,val;
    cout<<"Enter no. of nodes for Linked List with zeros: ";
    cin>>n;
    Node* head=NULL;
    for(int i=0;i<n;i++){
        cout<<"Enter node value: ";
        cin>>val;
        head=Insert(head,val);
    }
    cout<<"Before merging nodes between zeros ";
    Display(head);
    head=mergeNodes(head);
    cout<<"After merging nodes between zeros ";
    Display(head);
    return 0;
}