#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
int main(){
    // codigo a completar
    srand(time(NULL)); // Es para la generación de números aleatorios
    int i;
    double vt[N];
    for(i = 0;i<N; i++){
        vt[i]= 1 + rand() % 100;
        printf("%.2f ", vt[i]); //utilizo el .2 para que los ceros sean solo dos
        printf("\n");
    }
    
    return 0;
}