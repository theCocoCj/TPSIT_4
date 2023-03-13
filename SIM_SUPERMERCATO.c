#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 4 //minuti max per cliente
#define MINN 1 //minuti min per cliente
#define GLAVORATIVA 720 // minuti

typedef struct cliente{
    int nCliente;
    int tempo;
    struct cliente *next;
}Cliente;

int is_empty(Cliente* head){
    if(head == NULL) return 1;
    else return 0;
}

void enqueue(Cliente** head, Cliente** tail, Cliente* element){
    if(is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;
}

Cliente* dequeue(Cliente** head, Cliente** tail){
    Cliente* ret = *head;

    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;
    
    return ret;
}

int Casuale(){
    int casuale;

    casuale = rand()%MAXN+MINN;
    
    return casuale;
}


int main(){
    srand(time(NULL)); 
    //coda dei clienti da servire
    Cliente* current_head = NULL;       
    Cliente* current_tail = NULL; 

    int tempoTraClienti = 4; //tempo tra i clienti
    int numCliente = 0; //tiene conto dei clienti
    
    Cliente* cliente;
    Cliente* clienteUscito;

    //per 720 minuti
    for(int k = GLAVORATIVA; k >= 0; k--){
        tempoTraClienti--;

        if(tempoTraClienti == 0){
            cliente = (Cliente*)malloc(sizeof(Cliente));
            numCliente++;
            cliente->nCliente = numCliente;
            cliente->tempo = Casuale();
            cliente->next = NULL;
            printf("al minuto %d e' entrato %d\n", k, numCliente);
            enqueue(&current_head, &current_tail, cliente);
            tempoTraClienti = Casuale();
        }

        if(!is_empty(current_head)) {
            current_head->tempo--;
            if( current_head->tempo == 0){
                clienteUscito = dequeue(&current_head, &current_tail);
                printf("Il cliente %d e' uscito al minuto %d\n", clienteUscito->nCliente, k); 
                free(clienteUscito);
            }
        }

        

    }


}