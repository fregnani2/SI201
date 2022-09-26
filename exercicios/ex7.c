#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* head = NULL;

void insertAtBegin(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = x;
    newNode->next = head;
    head = newNode;
}

void insertAtFinal(int x){
    Node* node = (Node*)malloc(sizeof(Node));

    Node* temp = head;
    node->value = x;
    node->next = NULL;

    if(head == NULL){
        head = node;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    return;
}


void print(Node* node){
    while(node != NULL){
        printf("[%d]->", node->value);
        node = node->next;
    }
    printf("\n");
}

int main(){
    
    insertAtBegin(2);
    insertAtBegin(5);

    print(head);


}