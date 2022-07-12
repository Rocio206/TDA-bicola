#include <stdio.h>
#include <stdlib.h>
#include "bicola.h"

typedef struct Bicola Bicola;

Bicola* crearBicola(int talla){
  Bicola* new = (Bicola*)malloc(sizeof(Bicola));
  new->array = (void**)malloc(sizeof(void*) * talla);
  new->head = 0;
  new->tail = 0;
  new->size = talla;
  return new;
}

void pushBack (void* dato, Bicola* bicola){
  if(EsVacia(bicola) == 1){
    bicola->array[bicola->head] = dato;
  }
  else{
    if(bicola->tail == bicola->size -1){
      bicola->array[bicola->tail] = dato;
      bicola->tail = 0;
    }
    else{
      bicola->array[bicola->tail +1] = dato;
      bicola->tail += 1;
    }
  }
  // comprobar si esta llena 
  if (bicola->head == 0){
    if (bicola->tail +1  == bicola->size) aumentar(bicola);
  }
  else{
    if (bicola->tail +1 == bicola->head) aumentar(bicola);
  }
  
}

void pushFront(void* dato, Bicola* bicola){
  if(EsVacia(bicola) == 1){
    bicola->array[bicola->head] = dato;
  }
  else{
    if (bicola->head == 0){
      bicola->head = bicola->size -1;
      bicola->array[bicola->head] = dato;
    }
    else{
      bicola->array[bicola->head -1] = dato;
      bicola->head -= 1;
    }
  }
  if ((bicola->tail +1 == bicola->head) || (bicola->tail +1 == bicola->size && bicola->head == 0) ) aumentar(bicola);
}

void* popFront(Bicola* bicola){
  if (EsVacia(bicola) == 1) return NULL;
  
  void* dato = bicola->array[bicola->head];
  bicola->array[bicola->head] = NULL;
  
  if (bicola->head == bicola->size -1 || bicola->array[bicola->head + 1] == NULL) bicola->head = 0;
  else bicola->head += 1;
  
  return dato;
}

void* popBack(Bicola* bicola){
  if (EsVacia(bicola) == 1) return NULL;
  
  void* dato = bicola->array[bicola->tail];
  bicola->array[bicola->tail] = NULL;

  if(bicola->tail == 0) bicola->tail = bicola->size -1;
  else bicola->tail -= 1;
  return dato;
}

void aumentar(Bicola* bicola){
  bicola->size *= 2;
  bicola->array = (void**)realloc(bicola->array ,bicola->size * sizeof(void*));
  //ordenar
  if (bicola->tail < bicola->head){
    void** auxArray = (void**)malloc(sizeof(void*) * (bicola->size /2 - bicola->head));
    int pos = 0;
    while(pos < bicola->size /2 - bicola->head){
      auxArray[pos] = bicola->array[bicola->head + pos];
      bicola->array[bicola->head + pos] = NULL;
      pos++;
    }

    bicola->head = bicola->size - (bicola->size /2 - bicola->head);
    pos = 0;
    while(pos < bicola->size - bicola->head){
      bicola->array[bicola->head + pos] = auxArray[pos];
      pos++;
    }
    free(auxArray);
  }
}

void* get_i (int pos, Bicola* bicola){
  
  if(bicola->head + pos -1 < bicola->size ){
    return bicola->array[bicola->head + pos -1];
  }
  else{
    return bicola->array[bicola->head + pos -1 - bicola->size]  ;
  }
}

void mostrar(Bicola* bicola){
  int pos = 0;
  
  while (pos < bicola->size){
    if (bicola->array[pos] != NULL){
      int* dato = bicola->array[pos];
      printf("/%d", *dato);
    }
    else{
      printf("/#");
    }
    pos++;
  }
  printf("/");
}

int EsVacia(Bicola* bicola){
  if (bicola->array[bicola->head] == NULL && bicola->array[bicola->tail] == NULL) {
    return 1;
    }
  else return 0;
    
}