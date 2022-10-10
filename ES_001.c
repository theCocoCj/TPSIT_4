#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 20
#define BUFFER_SIZE 1024
#define NRIGHE 16600

typedef char* stringa;

typedef struct dati {
    int rank;
    stringa name;
    stringa platform;
    int year;
    stringa genre;
    stringa publisher;
    float NA_Sales;
    float EU_Sales;
    float JP_Sales;
    float Other_Sales;
    float Global_Sales;
} Dati;

int main() {
    FILE *fp;

    Dati *a;
    a=(Dati*)malloc(16600 * sizeof(Dati)); //creazione grandezza dell' array dinamico
    Dati* puntatore = a; //assegnazione dei vari valori alle celle
    char riga[BUFFER_SIZE];

    int k=0;

    fp = fopen("vgsales.csv","r");
    fgets(riga,BUFFER_SIZE, fp); //toglie la prima riga del file

    if(fp==NULL) {

        printf("Errore nell'apertura del file");
        return 0;

    } else {

        printf("Sono dentro\n");
        while(fgets(riga,BUFFER_SIZE, fp)) {

            (a+k)->rank=atoi(strtok(riga,","));
            printf("%d ", (a+k)->rank);
            (a+k)->name=strtok(NULL,",");
            printf("% s ", (a+k)->name);
            (a+k)->platform=strtok(NULL,",");
            printf("% s ", (a+k)->platform);
            (a+k)->year=atoi(strtok(NULL,","));
            printf("% d ", (a+k)->year);
            (a+k)->genre=strtok(NULL,",");
            printf("% s ", (a+k)->genre);
            (a+k)->publisher=strtok(NULL,",");
            printf("% s ", (a+k)->publisher);
            (a+k)->NA_Sales=atof(strtok(NULL,","));
            printf("% .2f ", (a+k)->NA_Sales);
            (a+k)->EU_Sales=atof(strtok(NULL,","));
            printf("% .2f ", (a+k)->EU_Sales);
            (a+k)->JP_Sales=atof(strtok(NULL,","));
            printf("% .2f ", (a+k)->JP_Sales);
            (a+k)->Other_Sales=atof(strtok(NULL,","));
            printf("% .2f ", (a+k)->Other_Sales);
            (a+k)->Global_Sales=atof(strtok(NULL,","));
            printf("% .2f\n", (a+k)->Global_Sales);
            k++;
        }
    }
    free(*a);
    fclose(fp);
    return 1;
}
