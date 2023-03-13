#include <stdio.h>
#include <stdlib.h>

typedef struct  node {
    int  valore;
    struct  node* next;
}Node;

void insertTail(Node **coda, int new_valore){
    Node* new_tail;
    new_tail = (Node*)malloc(sizeof(Node));

    new_tail->valore = new_valore;
    new_tail->next = (*coda); 
    (*coda) = new_tail; 
}

void stampaCoda(Node *coda){
    Node *c; //variabile di appoggio
    c = coda;
    while(c != NULL){
        printf("%d" coda->valore);
        c = c->next;
    }
}

int main(){
    int n;
    Node* coda;

    printf("Inserisci un numero:\n");
    scanf("%d",&n);

    coda = (Node*)malloc(sizeof(Node));
    coda->valore = n;

    insertTail(&lista, 10);
    return 0;

}

