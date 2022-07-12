#ifndef bicola_h
#define bicola_h

struct Bicola{
  void** array;
  int head;
  int tail;
  int size;
};

typedef struct Bicola Bicola;

Bicola* crearBicola(int size);

void pushBack (void* data, Bicola* bicola);

void pushFront(void* data, Bicola* bicola);

void* popFront(Bicola* bicola);

void* popBack(Bicola* bicola);

void aumentar(Bicola* bicola); // si el arreglo se llena, se aumenta el tamaño al size*2

void* get_i(int pos, Bicola* bicola);

void mostrar(Bicola* bicola);

int EsVacia(Bicola* bicola);

#endif