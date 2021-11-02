#include <iostream>
#include <unistd.h>

using namespace std;

int main(){

  string rerun;
  int pass=1;
  int nota[5],suma=0,nota_max=0,nota_min=0;
  float nota_media=0;

  do{
    do {
      cout << "Dime una nota comprendida del 0-10 : "; cin >> nota[pass];
      if (nota[pass]<0){
        cout << "No puedes tener una nota menor a 0..." << '\n';
      }else if (nota[pass]>10){
        cout << "No puedes tener una nota mayor a 10..." << '\n';
      }else if (nota_max==0){
        nota_max=nota[pass];
        nota_min=nota[pass];
      }

        if (nota[pass]>nota_max){
          nota_max=nota[pass];
        }
        if (nota[pass]<nota_min){
          nota_min=nota[pass];
        }
        suma+=nota[pass];
        nota_media=suma/5;
        pass++;

    }while(pass<=5);
    cout << "\nLa nota mas alta fue : " << nota_max << '\n';
    cout << "La nota media fue : " << nota_media << '\n';
    cout << "La nota más baja fue : " << nota_min << '\n';

    cout << "\n¿Desea intentar de nuevo? : "; cin >> rerun;
    for (int i=0; i<rerun.length(); i++){
      rerun[i]=tolower(rerun[i]);
    }
  }while(rerun=="si");
  return 0;
}
