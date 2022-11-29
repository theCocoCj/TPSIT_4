#include <stdio.h>
#include <stdlib.h>

typedef struct  node {
    int  value;
    struct  node* next;
} Node;
void printList(Node* l) {
    printf("%d - %p \n",l->value, l->next);
    if(l->next != NULL)
        printList(l->next);
}
void freeList(Node* l) {
    if(l->next != NULL)
        freeList(l->next);
    free(l);
}
void insertNode(Node** head, Node* el) { // inserisce il nodo in ordine crescente di valori
    Node* prev = NULL; // precedente
    Node* curr = *head; // corrente

    while(curr != NULL) { // se curr esiste
        if(el->value <= curr->value) {// val nuovo <= val corrente
            break;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    if(prev == NULL) // curr sarà la testa, vuol dire che si esce al primo ciclo del while
        *head = el;  // l'elemento diventa la testa
    else
        prev->next = el; // prev->next è curr

    el->next = curr; // si mette perché sennò el sostituisce curr
}

int main() {
    Node* head = (Node*) malloc(sizeof(Node));
    head->next = (Node*) malloc(sizeof(Node));
    head->value = 3;
    head->next->next = NULL;
    head->next->value = 8;

    printList(head);
    printf("\n");

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->value = 1;

    insertNode(&head, newNode);
    printList(head);

    return 0;
}