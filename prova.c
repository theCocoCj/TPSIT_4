#include  <stdio.h>
#include  <stdlib.h>
typedef struct  node 
{
    int  valore;
    struct  node* next;
}Node;

void stampaNum(Node *lista){
    Node* l;
    l = lista;

    l=lista; // l punta all'inizio della lista
    printf("numeri inseriti: ");
    while (l!=NULL){
        printf("\n%d - %p \n",l->valore, l->next); //la seconda stampa è il puntatore, l'ultimo ha tutti 0 perchè
                                                   //non viene assegnata una posizione
        l=l->next; //si assegna ad l il nome successivo
    }
}

void contaNum(Node *lista){
    int k = 0;
    Node* l;
    l = lista;

    l=lista; // l punta all'inizio della lista
    printf("numeri inseriti: ");
    while (l!=NULL){
        k++;
        l=l->next; //si assegna ad l il nome successivo
    }
    printf("Ci sono %d numeri\n", k);
}

void insertHead(Node **lista, int new_valore){//si passa come **lista per assegnare dopo la nuova testa
    Node* new_head;
    new_head = (Node*)malloc(sizeof(Node));

    new_head->valore = new_valore; //carico il nuovo valore nel node temporaneo/nuovo
    new_head->next = (*lista); //assegno al next la testa precedente
    (*lista) = new_head; //assegno la nuova testa
}

void insertHeadByNum(Node **head, Node *elemento){
    Node *curr = *head, *prev = NULL;
    while(curr != NULL){
        if(elemento->valore <= curr->valore)
            break;
        prev = curr;
        curr = curr->next;
        
    }

    if(prev == NULL){
        *head = elemento;
    }else{
        elemento->next = curr;
    }
}

int  main(){
    int n;
    Node* lista;
    Node* l;
    lista=NULL;
    Node* new_element;

    do{
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d",&n);
        new_element = (Node*)malloc(sizeof(Node));
        new_element->valore = n;
        new_element->next= NULL;
        insertHeadByNum(&lista, new_element);
            
    }while (n!=0);

    stampaNum(lista);
    contaNum(lista);
    //insertHead(&lista, 10);
    //stampaNum(lista);


}