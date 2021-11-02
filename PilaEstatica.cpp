#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAMMAX 50

using namespace std;

struct pila{
  char dato[TAMMAX];
  pila *previous;
}*top=NULL, *elemento=NULL;

void push();
void pop();
void show();

int main() {

    int opc;

    do{
      system("clear");
      
      cout<<"\t--- Menú de Operaciones ---\n"<<'\n'
          <<"\t      1.- Push"<<'\n'
          <<"\t      2.- Pop"<<'\n'
          <<"\t      3.- Show"<<'\n'
          <<"\t      4.- Salir "<<'\n'
          <<"\n\t      Selecciona ~"; cin>>opc;

      switch (opc) {
        case 1:
          push();
          break;
        case 2:
          pop();
          break;
        case 3:
          show();
          break;
        }

    }while(opc!=4);

    return 0;
}

void push(){
    if(!top){
      top = new(pila);

      cout << "\n\t   Ingrese un valor : ";
      cin >> top -> dato;
      top -> previous = NULL;

      return;
    }

    elemento = new(pila);
    cout << "\n\t   Ingrese un valor : ";
    cin >> elemento -> dato;
    elemento -> previous = top;

    top = elemento;
}

void pop(){
    system("read -p '' var");
    if(!top){
        cout << "\n\t¡No hay elementos en la pila!" << '\n';
        return;
    }

    elemento = new(pila);
    elemento = top;

    cout << "\n\t¡Se ha eliminado un elemento!" << '\n';
    elemento -> dato;
    top = elemento -> previous;

    delete(elemento);
    system("read -p '' var");
}

void show(){
    system("clear");
    elemento = top;

    if(top != NULL){
        while (elemento != NULL){
            cout << "\n\t" << elemento -> dato <<'\n';
            elemento = elemento -> previous;
        }
    }else{
        cout << "\t¡La Pila NO contiene elementos!" << '\n';
    }
    system("read -p '' var");
}
