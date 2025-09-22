#include <stdio.h>
#include <stdlib.h>

struct Node{
   int data; // 4 bytes
   char nombre[20];
   struct Node* next;
};

struct Node* createNode(int data, char nombre){
    struct Node* newNode = ( struct Node*)malloc (sizeof(struct Node));
    if (newNode == NULL){
        printf("Error: memoria no reservada");
        exit(1);
    }
   
    newNode->data=data;
    newNode-> nombre=nombre;
    newNode-> next= NULL;
    return newNode;
  
}
void printList(struct Node* head){
    struct Node* temp = head;
    while (temp !=NULL){
        printf("%d->", temp->data);
        printf("%c->",temp->nombre);
        temp = temp->next;
    }                           
   printf("Null\n");
    
}
int main(){
    struct Node* head = createNode(10,"Juan");
    struct Node* first = createNode(11,"Carlos");
    struct Node* second = createNode(12,"Camilo");
    struct Node* third = createNode(13,"Santiago"); 
    
    head->next = first;
    first->next = second;
    second->next= third;

    printList(head);

    free(head);
    free(first);
    free(second);
    free(third);

    return 0;
}
