#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void delete_at_begin(Node* head)
{
    Node* temp=head;
    head=head->next;
    free(temp);
}

void delete_at_end(Node* head)
{
    if(head!=NULL)
    {
        if(head->next==NULL)
        {
         free(head);
        }
        else{
            Node* temp=head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            Node* lastnode=temp->next;
            temp->next=NULL;
            free(lastnode);

        }
    }
}
void deletion(Node** head,int key)
{
    Node* temp=*head;
    Node* prev=NULL;
    
    while(temp!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        cout<<"key is not present";
    }
    prev->next=temp->next;
    free(temp);
}

void push(Node** head,int val)
{
   Node* newnode=new Node();
   newnode->data=val;
   newnode->next=*head;
   *head=newnode;
}

void printlist(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next; 
    }

}
int main()
{
    Node* head=NULL;
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    delete_at_begin(head);
    delete_at_end(head);
    deletion(&head,4);
    cout<<"the linkedlist is=";
    printlist(head);
    return 0;
}