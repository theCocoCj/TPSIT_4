#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200
#define MIN 50
#define T 30


typedef struct processo{

    int pid;
    char stato[MAX];
    int time;
    struct processo *next;

}Processo;


void stampaCoda(Processo *p){
    while(p != NULL){
        printf("%d, %s, %d\n", p->pid, p->stato, p->time);
        p = p->next;
    }
}

int is_empty(Processo* head){
    if(head == NULL) return 1;
    else return 0;
}

void enqueue(Processo** head, Processo** tail, Processo* element){
    if(is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;
}

Processo* dequeue(Processo** head, Processo** tail){
    Processo* ret = *head;

    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;
    
    return ret;
}

int main(){

    Processo* nl_head = NULL;       
    Processo* nl_tail = NULL; 

    Processo* rl_head = NULL;       
    Processo* rl_tail = NULL; 

    Processo* tl_head = NULL;       
    Processo* tl_tail = NULL;

    int num;
    Processo* processo;

    do{
        printf("inserisci il numero di processi: ");
        scanf("%d", &num);
    }while (num <= 0);
    
    for(int k = 0; k < num; k++){
        processo = (Processo*)malloc(sizeof(Processo));
        processo->pid = k;
        strcpy(processo->stato, "nuovo");

        do{
            printf("tempo %d", k);
            scanf("%d", &processo->time);
        }while(processo->time < MIN || processo->time > MAX);
        
        enqueue(&nl_head, &nl_tail,processo);


    }    

    for(int k = 0; k < num; k++){
        Processo* processo = dequeue(&nl_head, &nl_tail);
        strcpy(processo->stato, "pronto");
        enqueue(&rl_head, &rl_tail, processo);
    }

    while (!is_empty(rl_head)){
        processo = dequeue(&rl_head, &rl_tail);
        strcpy(processo->stato, "esegui");
        processo->time -= T;
        if(processo->time > 0){
            enqueue(&rl_head, &rl_tail, processo);}
            else{
            enqueue(&tl_head, &tl_tail, processo);
            strcpy(processo->stato, "fine");
            }

    }

    stampaCoda(tl_head);

    return 0;
}