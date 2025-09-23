#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

struct Node{
   int data;            
   char nombre[20];     
   float promedio;      
   double salario;      
   long id;             
   struct Node* next;
};

struct Node* createNode(int data, char nombre[], float promedio, double salario, long id){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Error: memoria no reservada");
        exit(1);
    }
   
    newNode->data = data;
    strcpy(newNode->nombre, nombre);
    newNode->promedio = promedio;
    newNode->salario = salario;
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d - %s - %.2f - %.2f - %ld -> ",
               temp->data,
               temp->nombre,
               temp->promedio,
               temp->salario,
               temp->id);
        temp = temp->next;
    }                           
    printf("NULL\n");
}

int main(){
    struct Node* head   = createNode(10,"Juan",    4.5, 1200.50, 1001);
    struct Node* first  = createNode(11,"Carlos",  3.8, 950.75,  1002);
    struct Node* second = createNode(12,"Camilo",  4.2, 1300.00, 1003);
    struct Node* third  = createNode(13,"Santiago",4.9, 1500.25, 1004); 
    
    head->next = first;
    first->next = second;
    second->next = third;

    printList(head);

    free(head);
    free(first);
    free(second);
    free(third);

    return 0;
}
