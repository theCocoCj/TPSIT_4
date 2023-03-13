#include  <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>

#define CAR_MAX 1000

typedef struct  node {
    char parentesi;
    struct  node* next;
}Node;

int is_empty(Node *head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Node **head, Node *elemento){
    if(is_empty(*head)){
        *head = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *head;
        *head = elemento;
    }
}

Node* pop(Node **head){
    Node *ret = *head;

    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    return ret;
}


int  main(){
    char stringa[CAR_MAX] = "{[3+(a+b)+]+8}";
    char car;
    int cont = 0;
    bool booleana = true;
    Node *pila;
    pila = NULL;
    Node *elemento;
    Node *temp;

    while(car != '\n' && booleana == true){
        car = stringa[cont];
        if(car == '(' || car == '[' || car == '{' ){
            elemento = (Node*)malloc(sizeof(Node));
            elemento->parentesi = car;
            printf("push posizione %d\n", cont);
            push(&pila, elemento);
        }else if(car == ')' || car == ']' || car == '}' ){
            elemento = (Node*)malloc(sizeof(Node));
            printf("pop posizione %d\n", cont);
            temp = pop(&pila);

            if((temp->parentesi == '(' && car == ')') || (temp->parentesi == '[' && car == ']') || (temp->parentesi == '{' && car == '}') ){
                printf("parentesi chiusa\n");
                booleana = true;

            }else{
                printf("ERRORE NELLA POSIZIONE %d\n", cont);
                booleana = false;
            }
        }
        cont++;
    }

    if (booleana == true){
        printf("tutte le parentesi sono state chiuse\n");
    }else{
        printf("NON tutte le parentesi sono state chiuse\n");
    }
    
    return  0;
}