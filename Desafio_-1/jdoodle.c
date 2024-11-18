#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

#define N 5 

char *buffer[N]; 
int cuenta = 0; 

void producir_elemento(int numero) {
    printf("Comenzado producción...\n");
    sleep(0.5); // Espera 0.5 segundos
    
    printf("Finalizo la produccion\n");

    // Genera un nombre de elemento
    buffer[cuenta] = (char *)malloc(10 * sizeof(char)); // Reserva memoria para el nombre
    snprintf(buffer[cuenta], 10, "Caja %d", numero); // Crea "Caja x"
}
// Función para simular la inserción de un elemento en el búfer
void insertar_elemento() {
    cuenta++; // Incrementa la cuenta
    printf("Productor: produjo %s (Total en el búfer: %d)\n", buffer[cuenta - 1], cuenta);
}

// Función para simular la extracción de un elemento del búfer
char* quitar_elemento() {
    cuenta--; // Decrementa la cuenta
    return buffer[cuenta]; // Retira del búfer
}

// Función para simular el consumo de un elemento
void consumir_elemento(char* elemento) {
    printf("Consumidor: consumió %s (Total en el búfer: %d)\n", elemento, cuenta);
}

// Función del productor
void productor() {
    for (int i = 1; i <= N; i++) { // Produce 5 elementos
        producir_elemento(i); // Produce un nuevo elemento
        insertar_elemento(); // Inserta el elemento en el búfer
        sleep(0.5); // Simula tiempo de producción
    }
    printf("Productor: búfer lleno, durmiendo...\n");
}

// Función del consumidor
void consumidor() {
    while (cuenta > 0) { // Mientras haya elementos en el búfer
        char* elemento = quitar_elemento(); // Retira un elemento del búfer
        consumir_elemento(elemento); // Consume el elemento
        sleep(1); // Simula tiempo de consumo
    }
    printf("Consumidor: búfer vacío, durmiendo...\n");
    sleep (0.5);
    printf("Se a consumido la totalidad de los bufer\n");
    printf("Fin de la simulacion :D\n");
    
}

// Función principal
int main() {
    productor(); // Llenar el búfer
    consumidor(); // Consumir todos los elementos

    // Liberar memoria
    for (int i = 0; i < N; i++) {
        free(buffer[i]); // Libera la memoria de cada elemento
    }

    return 0; // Finaliza el programa
}