#include <stdio.h>
#include <windows.h>  // Para la función Sleep()

#define MAX_DISCOS 20

// Función para dibujar las torres en consola
void dibujar_torres(int torres[3][MAX_DISCOS], int discos_por_torre[3], int num_discos) {
    int max_altura = num_discos;
    
    for (int nivel = max_altura - 1; nivel >= 0; nivel--) {
        for (int t = 0; t < 3; t++) {
            if (nivel < discos_por_torre[t]) {
                int disco = torres[t][nivel];
                printf("%*s", num_discos - disco + 1, "");  // Espacio antes del disco
                for (int i = 0; i < 2 * disco - 1; i++) {
                    printf("=");  // Representación del disco con "="
                }
                printf("%*s", num_discos - disco + 1, "");  // Espacio después del disco
            } else {
                printf("%*s|%*s", num_discos, "", num_discos, "");  // Torre vacía
            }
        }
        printf("\n");
    }

    // Base de las torres
    printf("%*sA%*sB%*sC\n\n", num_discos + 1, "", num_discos * 2, "", num_discos * 2, "");
}

// Mover disco entre torres
void mover_disco(int torres[3][MAX_DISCOS], int discos_por_torre[3], int origen, int destino) {
    int disco = torres[origen][discos_por_torre[origen] - 1];  // El disco que está en la parte superior de la torre origen
    discos_por_torre[origen]--;  // Quitar el disco de la torre origen

    torres[destino][discos_por_torre[destino]] = disco;  // Añadir el disco a la torre destino
    discos_por_torre[destino]++;  // Incrementar el número de discos en la torre destino

    // Dibujar la representación gráfica en consola
    dibujar_torres(torres, discos_por_torre, MAX_DISCOS);
    Sleep(500);  // Pausa para observar el movimiento (en milisegundos) en Windows
}

// Función recursiva para resolver Torres de Hanoi
void hanoi(int n, int origen, int destino, int auxiliar, int torres[3][MAX_DISCOS], int discos_por_torre) {
    if (n == 1) {
        mover_disco(torres, discos_por_torre, origen, destino);
        return;
    }
    hanoi(n - 1, origen, auxiliar, destino, torres, discos_por_torre);
    mover_disco(torres, discos_por_torre, origen, destino);
    hanoi(n - 1, auxiliar, destino, origen, torres, discos_por_torre);
}

int main() {
    int num_discos;

    // Solicitar el número de discos
    printf("Introduce el número de discos (máximo %d): ", MAX_DISCOS);
    scanf("%d", &num_discos);

    if (num_discos > MAX_DISCOS) {
        printf("El número máximo de discos es %d.\n", MAX_DISCOS);
        return 1;
    }

    // Inicializar las torres
    int torres[3][MAX_DISCOS] = {0};  // Tres torres, cada una puede tener hasta MAX_DISCOS discos
    int discos_por_torre[3] = {num_discos, 0, 0};  // La primera torre empieza con todos los discos

    // Llenar la primera torre con discos del 1 al num_discos
    for (int i = 0; i < num_discos; i++) {
        torres[0][i] = num_discos - i;
    }

    // Dibujar el estado inicial
    dibujar_torres(torres, discos_por_torre, num_discos);

    // Resolver Torres de Hanoi
    hanoi(num_discos, 0, 2, 1, torres, discos_por_torre);

    return 0;
}
