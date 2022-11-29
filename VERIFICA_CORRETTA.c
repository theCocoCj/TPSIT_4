#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define COSTOTOT 2200
#define QUOTA 100

typedef char* stringa;

//struct con i dati caricati dal file
typedef struct dati{
    int giorno;
    int mese;
    int anno;
    stringa cognome;
    int quota;
}Dati;

int contaPers(int lung){
    FILE* fp;
    int k = 0;
    char c[lung];
    char* riga = c;

    fp = fopen("4AROB_GITA.csv", "r");

    if(fp != NULL){
        printf("\ncontapers");
        while(fgets(riga, lung, fp)){
            k++;
        }
    }else
        printf("Il file non esiste\n");
    
    fclose(fp);

    return k;
}

//funzione che apre e carica i dati del file nella struct
void caricaDati (int nPers){

    int k = 0;

    FILE *fp;
    fp = fopen("4AROB_GITA.csv", "r");

    stringa riga;
    Dati *a;
    a = (Dati *)malloc(nPers * sizeof(Dati));   //puntatore a struttura con locazione dinamica

    //controllo apertura del file
    if (fp == NULL) {

        printf("\nerrore nell'apertura del file");

    } else {

        printf("\nsono dentro");
        riga = (stringa)malloc(BUFFER_SIZE * sizeof(char)); //allocazione dello spazio in memoria riga(stringa)

        int Incasso = 0;
        int sommaCoj = 0;

        while(fgets(riga, BUFFER_SIZE, fp)) {
            
            (a+k)->giorno = atoi(strtok(riga,"/")); //strtok funzione che divide la stringa in più parti con il carattere separatore
            (a+k)->mese = atoi(strtok(NULL,"/")); //atoi per interi e float
            (a+k)->anno = atoi(strtok(NULL,";"));
            (a+k)->cognome = strdup(strtok(NULL, ";")); //strdup per stringhe
            (a+k)->quota = atoi(strtok(NULL, ";"));

            Incasso = Incasso + ((a+k)->quota);

            printf("\n%d/%d/%d, %s, %d",(a+k)->giorno,(a+k)->mese,(a+k)->anno,(a+k)->cognome,(a+k)->quota);
            /*
            if(strcmp("Cojan",(a+k)->cognome)==1){
            sommaCoj += (a+k)->quota;
            }
            */

            riga = (stringa)malloc(BUFFER_SIZE * sizeof(char)); // spazio di nuovo a 1024 per la nuova iterazione del ciclo
            k++;
        }
        printf("\nL'incasso totale e' di: %d euro", Incasso);
        if(Incasso > COSTOTOT){
            printf("\nCi sono %d euro in piu'",(Incasso-COSTOTOT));
        }else{
            printf("\nCi sono %d euro in meno", (COSTOTOT-Incasso));
        }
        /*
        if(sommaCoj >= QUOTA){        
            printf("Cojan ha pagato tutta la somma");
        }else{
            printf("Cojan non ha pagato tutta la somma");
        }
        */
    }
    fclose(fp); //chiusura del file
    free(riga); //disallocazione dello spazio per riga
}

int main() {
    int npers=0;
    int SommaTot=0;

    //funzione per calcolare il numero delle righe
    npers=contaPers(BUFFER_SIZE);
    printf("Npers: %d", npers);//stampa numero delle persone

    caricaDati(npers); //procedura per caricare i dati nella struttura
}