#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 20
#define BUFFER_SIZE 1024

typedef char stringa[LUNG];

typedef struct dati {
    int rank;
    stringa name;
    stringa platform;
    int year;
    stringa genre;
    stringa publisher;
    float NA_Sales;
    float EU_Sales;
    float Other_Sales;
    float Global_Sales;
} Dati;

int main() {

    FILE *fp;

    char riga[BUFFER_SIZE];

    fp = fopen("vgsales.csv","r");

    if(fp==NULL){

        printf("Errore nell'apertura del file");
        return 0;
    }else{
        printf("Sono dentro");
        while(!feof(fp)){
            fgets(riga,BUFFER_SIZE, fp);
            printf("%s", riga);
            scanf(riga,"%s", )
        }
    }

    fclose(fp);
    return 1;
}
