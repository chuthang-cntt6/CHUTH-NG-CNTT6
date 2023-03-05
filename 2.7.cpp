#include<stdio.h>
#include<stdlib.h>
 
struct Node  {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
struct Node *head, *tail; 
 

struct Node* GetNewNode(int x) {
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
 

void InsertAtHead(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
 

void InsertAtTail(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
 
 
void DeleteAtHead() {
    if(head == NULL) {
        return;
    }
    head = head->next;
    head->prev = NULL;
}
 

void DeleteAtTail() {
    if(head == NULL) {
        return;
    }
    tail = tail->prev;
    tail->next = NULL;
}
 

void Print() {
    struct Node* temp = head;
    printf("\nForward: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
 

void ReversePrint() {
    struct Node* temp = tail;
    if(temp == NULL) return; 
 
    printf("\nReverse: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
 
int main() {
 
   
    head = NULL;
    
    InsertAtTail(2);
    Print(); ReversePrint();
    InsertAtTail(4);
    Print(); ReversePrint();
    InsertAtHead(6);
    Print(); ReversePrint();
    InsertAtTail(8);
    Print(); ReversePrint();
    DeleteAtHead();
    Print(); ReversePrint();
    DeleteAtTail();
    Print(); ReversePrint();
}