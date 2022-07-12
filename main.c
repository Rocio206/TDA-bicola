#include <stdio.h>
#include <stdlib.h>
#include "bicola.h"

int main(void) {
  int op;
  
  printf("Se creara una Bicola de n elementos\n");
  printf("Introduce n :  -> ");
  int n ;
  scanf("%d", &n);
  getchar();
  Bicola* test = crearBicola(n);

  do{
    printf("\n\n");
    printf("¿Que desea hace con la Bicola?\n");
    printf("1. Agregar elemento a la izquierda\n");
    printf("2. Agregar elemento a la derecha\n");
    printf("3. Eliminar elemento a la izquierda\n");
    printf("4. Eliminar elemento a la derecha \n");
    printf("5. Mostrar i-esimo elemento\n"); // 
    printf("0. Terminar\n");

    do{
      printf("Introducir opcion -> ");
      scanf("%d", &op);
    }while(op < 0 || op > 65);
    
    int* elem = (int*) malloc(sizeof(int)); // Para el ejemplo se usan datos tipo int 
    switch(op){
      
      case 1:
        printf("Introducir el numero entero que desea ingresar -> ");
        getchar();
        scanf("%d", elem);
        pushFront(elem, test);
        printf("\n");
        mostrar(test);
        break;
      
      case 2:
        printf("Introducir el numero entero que desea ingresar -> ");
        getchar();
        scanf("%d", elem);
        pushBack(elem, test);
        printf("\n");
        mostrar(test);
        break;
      
      case 3:
        elem = popFront(test);
        if (elem == NULL) printf("No se puede eliminar nada de una bicola vacia");
        else{
          printf("\n");
          printf("Elemento eliminado -> %d", *elem);
          printf("\n");
        }
        mostrar(test);
        break;
      
      case 4:
        elem = popBack(test);
        if (elem == NULL) printf("No se puede eliminar nada de una bicola vacia");
        else{
          printf("\n");
          printf("Elemento eliminado -> %d", *elem);
          printf("\n");
        }
        mostrar(test);
        break;
      
      case 5:
        printf("Introduzca la posicion del numero al que desea acceder -> ");
        int pos;
        scanf("%d", &pos);
        if (pos > test->size){
          printf("-> La bicola NO es tan grande ");
        }
        else{
          int* dato = get_i(pos, test);
          if (dato == NULL){
            printf("-> No se encuentra ningun dato en esa posicion ");
          }
          else {
          printf("\n -> %d", *dato);
          }
        }
        printf("\n");
        mostrar(test);
        break;
    }

  } while (op != 0);
  return 0;
}
