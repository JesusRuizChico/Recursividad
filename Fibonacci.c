#include <stdio.h>
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Imprimir valores
void imprimirFibonacciEnRango(int inicio, int fin) {
    if (inicio > fin) {
        return; 
    }
    
    // Imprimir
    printf("Fibonacci(%d) = %d\n", inicio, fibonacci(inicio));
    
    // Llamar a la funcion 
    imprimirFibonacciEnRango(inicio + 1, fin);
}

int main() {
    int inicio, fin;
    
    // Pedir al usuario el rango de posiciones
    printf("Introduce la posicion inicial de la serie: ");
    scanf("%d", &inicio);
    
    printf("Introduce la posicion final de la serie: ");
    scanf("%d", &fin);
    
    // Validar que el rango sea correcto
    if (inicio < 0 || fin < 0 || inicio > fin) {
        printf("Error: El rango es invalido.\n");
        return 1;
    }
    
    // Llamar a la función para imprimir la serie
    printf("La serie Fibonacci desde la posicion %d hasta %d es:\n", inicio, fin);
    imprimirFibonacciEnRango(inicio, fin);
    
    return 0;
}



/*
Introduce el nomuero donde quieres que pare 
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num = 0;
      printf("Introduce el numero : ");
     scanf("%d",&num);
    printf("La serie Fibonacci en la posicion %d es: %d\n", num, fibonacci(num));
    return 0;
}*/