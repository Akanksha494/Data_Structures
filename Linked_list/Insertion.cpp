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



void insertAtPos(Node **head, int data, int pos) {
    
    Node *node = new Node();
    
    node -> data = data;
    node -> next = NULL;
    
    Node *temp = *head;
    Node *prev = NULL;
    
    int i = 0; // pos = 0
    
    while(temp != NULL && i < pos) {
        prev = temp;
        temp = temp -> next;
        i++;
    }
    
    if(temp == NULL) {
        cout << "Invalid Position";
        
    } else if(pos == 0) {
        node -> next = temp;
        *head = node;
        
    } else {
        node -> next = temp;
        prev -> next = node;
    }
}

void nthLastNode(Node *head, int pos) {
    Node *fast = head;
    Node *slow = head;
    
    int count = 0;
    
    while(count < pos) {
        count++;
        fast = fast -> next;
    }
    
    
    while(fast != NULL) {
        slow = slow -> next;
        fast = fast -> next;
    }
    
    cout << slow -> data << endl;
}

void printList(Node *head) {
    Node *temp = head;
    
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
    cout << endl;
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

    insertAtPos(&head, 7, 2);
    
    printList(head);
    
    nthLastNode(head, 2);
}
    