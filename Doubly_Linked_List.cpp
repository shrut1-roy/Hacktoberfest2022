#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
        this->prev = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        if(this-> next != NULL){
            // delete next;
            this->next = NULL;
        }
        cout << "Memory is free for Node with data: " << value << endl;
    }
};


void printList(Node* &head)
{
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* &head){
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head ,Node* &tail ,int data)
{
    Node *newNode = new Node(data);
    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
        return; 
    }
    newNode->next = head;
    head -> prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &head ,Node* & tail ,int data)
{
    Node *newNode = new Node(data);
    if(tail==NULL)
    {
        tail = newNode;
        head = newNode;
        return; 
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPosition(Node* &head , Node* &tail, int position, int data)
{
    // insert at start
    if (position == 1)
    {
        insertAtHead(head, tail ,data);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // insert at last
    if (temp->next == NULL)
    {
        insertAtTail(head ,tail ,data);
        return;
    }

    // creating node for data
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node* &head ,int position)
{
    if (head == NULL)
    {
        cout << "List empty." << endl;
        return;
    }

    //start delete
    if(position == 1)
    {
        Node *temp = head;
        temp -> next -> prev = NULL;
        head = temp->next;
        temp -> next = NULL;
        delete temp;
    }

    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        curr -> prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

}

Node* reverseList(Node* head)
{
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* previous = NULL;
    Node* current = head;
    Node* forward = NULL;
    while(current != NULL)
    {
        forward = current -> next;
        current -> next = previous;
        previous = current;
        current = forward;
    }
    return previous;
}

int main()
{
    //created a new node
    Node* node1 = new Node(10);

    Node* head = node1; 
    Node* tail = node1;
    linsertAtHead(4);
    isertAtTail(5);
    printList();
    insertAtPosition(head , tail , 1 , 8);
    printList(head);
    insertAtPosition(head , tail , 2 , 90);
    insertAtPosition(head , tail , 3 , 67);
    insertAtPosition(head , tail , 4 , 7);
    printList(head);
    insertAtTail(7);
    insertAtTail(9);
    deleteNode(head ,4);
    insertAtPosition(head , tail , 4 , 6);
    insertAtPosition(head , tail , 1 , 1);
    printList(head);
    insertAtHead(80);
    deleteNode(head ,6);
    printList(head);
    printList(head);
    Node* checkReverse = reverseList(head);
    printList(checkReverse);
    return 0;
}
