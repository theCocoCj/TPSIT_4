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

    Dati Games[NRIGHE];
    Dati* puntatore = Games;
    char riga[BUFFER_SIZE];

    int k=0;

    fp = fopen("vgsales.csv","r");
    fgets(riga,BUFFER_SIZE, fp);

    if(fp==NULL) {

        printf("Errore nell'apertura del file");
        return 0;

    } else {

        printf("Sono dentro\n");
        while(fgets(riga,BUFFER_SIZE, fp)) {

            (puntatore+k)->rank=atoi(strtok(riga,","));
            printf("%d ", (puntatore+k)->rank);
            (puntatore+k)->name=strtok(NULL,",");
            printf("% s ", (puntatore+k)->name);
            (puntatore+k)->platform=strtok(NULL,",");
            printf("% s ", (puntatore+k)->platform);
            (puntatore+k)->year=atoi(strtok(NULL,","));
            printf("% d ", (puntatore+k)->year);
            (puntatore+k)->genre=strtok(NULL,",");
            printf("% s ", (puntatore+k)->genre);
            (puntatore+k)->publisher=strtok(NULL,",");
            printf("% s ", (puntatore+k)->publisher);
            (puntatore+k)->NA_Sales=atof(strtok(NULL,","));
            printf("% .2f ", (puntatore+k)->NA_Sales);
            (puntatore+k)->EU_Sales=atof(strtok(NULL,","));
            printf("% .2f ", (puntatore+k)->EU_Sales);
            (puntatore+k)->JP_Sales=atof(strtok(NULL,","));
            printf("% .2f ", (puntatore+k)->JP_Sales);
            (puntatore+k)->Other_Sales=atof(strtok(NULL,","));
            printf("% .2f ", (puntatore+k)->Other_Sales);
            (puntatore+k)->Global_Sales=atof(strtok(NULL,","));
            printf("% .2f\n", (puntatore+k)->Global_Sales);
            k++;
        }
    }

    fclose(fp);
    return 1;
}
