#include <iostream>
#include <unistd.h>

using namespace std;

int b=0;
int c=1;

int sumar(int a){
  if (a<=0){
    cout << "El numero es menor o igual a cero" << '\n';
  }else{
    for (int i = 1; i <= a; i++){
      b+=i;
    }
  }
  return b;
}

int multi(int a){
  if (a<=0){
    cout << "El numero es menor o igual a cero" << '\n';
  }else{
    for (int i = 1; i <= a; i++){
      c*=i;
    }
  }
  return c;
}

int main(){

  string operacion,rerun;
  int n;

  do {
  cout << "¿Que operacion es la que desea realizar?" << '\n';
  cout << "\tSuma / Multiplicacion \n" << '~'; cin >> operacion;

  for (int i=0; i<operacion.length(); i++) {
    operacion[i]=tolower(operacion[i]);
  }

  if(operacion=="suma"){
    cout << "Digita un numero entero : ~"; cin >> n;
    sumar(n);
    cout << "El resultado de la suma es : " << b << '\n';
    cout << "¿Desea volver a usar el programa?" << '\n';
  }else if(operacion=="multiplicacion"){
    cout << "Digita un numero entero : ~"; cin >> n;
    multi(n);
    cout << "El resultado de la multiplicacion es : " << c << '\n';
    cout << "¿Desea volver a usar el programa?" << '\n';
    }
    cout << "\tSi / No \n" << '~'; cin >> rerun;
    for (int i=0; i<rerun.length(); i++) {
      rerun[i]=tolower(rerun[i]);
    }
  }while(rerun=="si");
  return 0;
}
