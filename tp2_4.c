#include <stdio.h>
#include<stdlib.h>
#include<time.h>

struct compu{
    int velocidad;
    int anio;
    int cantidad_nucleos;
    char *tipo_cpu; //apunta a cadena de caracteres
}typedef compu;

//PCs
void listarPcs (struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);

int main(){
    srand(time(NULL)); //para generar las caracteristicas de 5 PCs
    int cantidad=5;
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core","Pentium"};
    compu pc[5]; //arreglo de 5 PCs
    for (int i = 0; i < cantidad; i++){
        pc[i].velocidad = 1 + rand() % 3;
        pc[i].anio = 2015 + rand() % 10;
        pc[i].cantidad_nucleos = 1  + rand() % 8;
        pc[i].tipo_cpu = tipos[rand()%6]; //tipo_cpu al ser puntero solo tengo que dirigirla a una de los strings de tipos con su direccion de memoria 
    }
    
    //mostrar las funciones 
    listarPcs(pc, cantidad);
    mostrarMasVieja(pc, cantidad);
    return 0;
}

void listarPcs (struct compu pcs[], int cantidad){
    for (int i = 0; i < cantidad; i++){
        printf("PC %d\n", i+1);
        printf("Velocidad de la PC: %d\n", pcs[i].velocidad);
        printf("Anio de la PC: %d\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("Tipo de CPU: %s\n", pcs[i].tipo_cpu);
    }   
}

void mostrarMasVieja(struct compu pcs[], int cantidad){
    int aux = 0;    //para poder identificar el año mas viejo de los num generados
    for (int i = 0; i < cantidad; i++){
        if (pcs[i].anio < pcs[aux].anio){
            aux = i;
        }
    }
    printf("\nPC MAS VIEJA\n");
    printf("\nPC mas vieja (PC %d):\n", aux + 1);
    printf("Velocidad: %d GHz\n", pcs[aux].velocidad);
    printf("Anio: %d\n", pcs[aux].anio);
    printf("Nucleos: %d\n", pcs[aux].cantidad_nucleos);
    printf("Tipo de CPU: %s\n\n", pcs[aux].tipo_cpu);
}