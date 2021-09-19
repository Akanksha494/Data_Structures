#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

void insertatend(Node **head, int data) {
    
    Node *node = new Node();
    
    node -> data = data;
    node -> next = NULL;
    
    if(*head == NULL) {
        *head = node;
        
    } else {
        Node *temp = *head;
        
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        
        temp -> next = node;
    }
}
void printList(Node *head) {
    Node *temp = head;
    
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
    cout << endl;
}

void insertAtBegin(Node **head, int data) {
    Node *node = new Node();
    
    node -> data = data;
    node -> next = NULL;
    
    if(*head == NULL) {
        *head = node;
    } else {
        node -> next = *head;
        *head = node;
    }
}

int main()
{
    Node *head = NULL; 
    
    int a;
    
    for(int i = 0; i < 5; i++) {
        cin >> a;
        
        insertatend(&head, a);
    }
    
    printList(head);
    insertAtBegin(&head, 6);
    
    printList(head);
}
    