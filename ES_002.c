#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define NMAX 5

int main() {
    int vett[5]= {9, 43, 67, 2, 0};
    int *p=vett;
    int temp; //variabile temporanea
    int k, sup; //indici
    int *a=p; 
    for (sup = NMAX-1; sup > 0; sup--) { // una volta che il primo numero è in ordine passa al successivo
            p=a;
        for (k = 0; k < sup ; k++) { //tiene conto dei numeri da confrontare
            if (*p > *(p+1)) { //verifica se la coppia di numeri è in ordine 
                temp = *p;
                *p = *(p+1);
                *(p+1) = temp;
            }
            p+=1; //salta il numero gia' verificato e passa gli altri in modo da non verificare di nuovo la coppia
        }
    }
for (p = vett; p < vett+NMAX ; p++) {
    printf("%d ",*p);
}
}

