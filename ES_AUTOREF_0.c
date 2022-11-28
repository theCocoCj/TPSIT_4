#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    char* nome;
    struct node *next;
}Node;

int main(){
    Node* lista=(Node*)malloc(sizeof(Node*));
    Node* temp=(Node*)malloc(sizeof(Node*));
    lista->next=NULL;
    temp->next=NULL;
    //-----------------------------
    printf("nome: ");
    scanf("%s", lista->nome);
    printf("%s", lista->nome);
    //----------------------------
    printf("\nnome: ");
    scanf("%s", temp->nome);
    printf("%s\n", temp->nome);

    lista->next=temp;
    printf("%s", lista->next->nome);
    //------------------------------
    printf("\nnome: ");
    scanf("%s", temp->nome);
    printf("%s\n", temp->nome);
    temp->next=NULL;

    lista->next->next=temp;
    printf("%s\n", lista->next->next->nome);


    free(lista);
    free(temp);
    return 0; 
}