#include <stdio.h>

// Función recursiva para resolver Torres de Hanoi
void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
    hanoi(n - 1, origen, auxiliar, destino);  // Mueve los primeros n-1 discos al auxiliar
    printf("Mover disco %d de %c a %c\n", n, origen, destino);  // Mueve el disco n
    hanoi(n - 1, auxiliar, destino, origen);  // Mueve los n-1 discos al destino
}

int main() {
    int num_discos;

    printf("Introduce el numero de discos: ");
    scanf("%d", &num_discos);

    // Llamada a la función Hanoi para mover los discos
    hanoi(num_discos, 'A', 'C', 'B');  // A es la varilla origen, C es la varilla destino, B es la varilla auxiliar

    return 0;
}
