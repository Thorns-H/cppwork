#include <iostream>
#include <stdlib.h>

using namespace std;

typedef string tipo_dato;

struct Nodo{
  tipo_dato dato;
  Nodo *next;
};

void push(Nodo *&, int);

int main() {
    Nodo *pila = NULL;



    return 0;
}

void push(Nodo *&pila, int n){
    Nodo *new_node = new Nodo();

    new_node -> dato = n;
    new_node -> next = pila;

    pila = new_node;
}
