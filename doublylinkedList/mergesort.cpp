#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        this->data=d;
        next=NULL;
    }
};
Node *merge(Node *a,Node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    Node *c;
    if(a->data<b->data){
        c=a;
        merge(a->next,b);
    }else{
        c=b;
        merge(a,b->next);
    }
    return c;

}

Node *midpoint(Node *head){
    if(head==NULL || head->next ==NULL){
        return head;
    }
    Node *fast=head;
    Node *slow=head;
    while(fast !=NULL && fast->next != NULL){
        fast=fast->next;
        if(fast->next==NULL){
            break;
        }
        fast=fast->next;
        slow=slow->next;
    }
}

Node *merge_sort(Node *head){
    if(head==NULL || head->next ==NULL){
        return head;
    }
    Node *mid=midpoint(head);
    Node *a=head;
    Node *b=mid->next;
    mid->next=NULL;
    a=merge_sort(a);
    b=merge_sort(b);
    Node *c=merge(a,b);
    return c;
}