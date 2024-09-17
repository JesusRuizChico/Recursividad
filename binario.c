#include <stdio.h>

void decimalBinario(int n){
    if(n == 0){
        return;
    }
    decimalBinario(n/2);// llamada recursiva didiviendo 
    printf("%d",n % 2);//Imprimir el residuo 
}

int main(){
    int num = 0;
     printf("Introduce el numero : ");
     scanf("%d",&num);
    if( num==0){
         printf("El numero que ingresaste es 0");
    }else{
        if(num>0){
                printf("La reresentacion binaria de %d es: ", num);
                decimalBinario(num);
                printf("\n");
        }else{
            printf("El numero es negativo y no hay representacion ");
        }   
    }
    return 0;
}