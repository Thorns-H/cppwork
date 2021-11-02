#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

struct domicilio{
  int numeroExt;
  char calle[20];
};

struct empleado{
  char nombre[20];
  int edad;
  int codigo;
  struct domicilio persona;
};

int main() {

  bool rerun;
  rerun=true;
  string opcion;
  int mem,data,memErase,check;
  struct empleado planta[50];
  int registros[50];
  int registro=0;
  int deleted[50];

  do {
    // Menú Principal
    system("clear");
    cout << "\t\t------ Sistema de Registro de Empleados ------" << '\n';
    cout << "\t1.- Alta / 2.- Baja / 3.- Consulta / 4.- Imprimir / 5.- Salir\n\n\t\tSelección:" << '~'; cin >> opcion;
    for(int i=0; i<opcion.length(); i++){
      opcion[i]=tolower(opcion[i]);
    }
    if(opcion=="alta"||opcion=="1"){ // Entrada de Datos de un Empleado
      system("clear");
      cout << "\t\t\t------ Captura de Datos ------" << '\n';
      cout << "\t\tEspacio de Memoria donde almacenar datos : ~"; cin >> mem;
      if(mem>50){
        cout << "El espacio no puede ser mayor a 50!" << '\n';
      }else if(mem<0){
        cout << "El espacio no puede ser menor a 50!" << '\n';
      }else{
        cout << "\n\t-Nombre : ~"; scanf("%*c%[^\n]",planta[mem].nombre);
        cout << "\t-Edad : ~"; cin >> planta[mem].edad;
        cout << "\t-Codigo : ~"; cin >> planta[mem].codigo;
        cout << "\t-Calle : ~"; scanf("%*c%[^\n]",planta[mem].persona.calle);
        cout << "\t-Número de Casa : ~"; cin >> planta[mem].persona.numeroExt;
        registros[registro]=mem;
        registro++;
        system("clear");
      }
    }else if(opcion=="baja"||opcion=="2"){ // Baja de Empleado
      if(registro>0){
        system("clear");
        cout << "\t\t------ Bajas del Sistema ------" << '\n';
        cout << "\t\tEspacio de Memoria donde borrar datos : ~"; cin >> memErase;
        for(int i=0; i < registro; i++){
            if(data!=memErase){
              registros[i]=data;
            }else if(data==memErase){
              registro--;
           }
      }
      }else{
        cout << "\n\t\t\t¡No hay empleados registrados aún!" << '\n';
        system("read -p '' var");
      }
    }else if(opcion=="consulta"||opcion=="3"){ // Consulta de Empleado
      if(registro>0){
      system("clear");
      cout << "\t\t\t------ Consulta de Registros ------" << '\n';
      cout << "\t\tEspacio de Memoria donde comprobar datos : ~"; cin >> check;
      for(int i=0;i<registro;i++){
        if(registros[i]==check){
          cout << "\n\t\t¡Se ha encontrado un empleado con el registro #" << check << "!" << '\n';
          cout << "\n\t\t-Nombre del Empleado : " << planta[check].nombre << '\n';
          cout << "\t\t-Edad del Empleado : " << planta[check].edad << '\n';
          cout << "\t\t-Código del Empleado: " << planta[check].codigo << '\n';
          cout << "\t\t-Domicilio del Empleado: " << planta[check].persona.calle << " #" << planta[check].persona.numeroExt << '\n';
          system("read -p '' var");
        }
      }
    }else{
      cout << "\n\t\t¡No hay empleados registrados para comprobar!" << '\n';
      system("read -p '' var");
    }
  }else if(opcion=="imprimir"||opcion=="4"){ // Imprimir Datos del Empleado
      if(registro>0){
      system("clear");
      cout << "\t\t\t------ Empleados Registrados ------" << '\n';
      cout << '\n';
      for(int i = 0; i < registro; i++){
          data=registros[i];
          cout << "\t\t-Registro #"<< data << ": "<< planta[data].nombre << ", con codigo #" << planta[data].codigo << "\n";
      }
      system("read -p '' var");
    }else{ // Bloqueo si no hay empleados
      cout << "\n\t\t¡No hay empleados registrados para mostrar!" << '\n';
      system("read -p '' var");
    }
    }else if(opcion=="salir"||opcion=="5"){
      rerun=false;
    }
  }while(rerun==true);
  return 0;
}
