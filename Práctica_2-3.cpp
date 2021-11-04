#include <iostream>
#define TAMMAX 500

using namespace std;

typedef string tipo_dato;

typedef struct {
    tipo_dato
    datos[TAMMAX];
    int ultimo;
}tipo_lista;

typedef int tipo_pos;

tipo_lista *inicializa() { tipo_lista *temp = new tipo_lista; temp->ultimo = 0; return temp;}
int vacia (tipo_lista *L);
int llena (tipo_lista *L);
void burbuja(tipo_lista *L);
void insersion(tipo_lista *L);
void seleccion(tipo_lista *L);
void quicksort(tipo_lista *L, int first, int last);
void mergesort(tipo_lista *L, int first, int last);
void lineal(tipo_lista *L, tipo_dato pos);
void binaria(tipo_lista *L, tipo_dato pos);
void insertar (tipo_lista *L, tipo_dato elemento, tipo_pos pos);
void elimina (tipo_pos,tipo_lista *L);
int recupera(tipo_pos,tipo_lista *L);
tipo_pos primero (tipo_lista *L);
tipo_pos ultimo (tipo_lista *L);
void imprime(tipo_lista *L);
void anula(tipo_lista *L);

int main(){
    int opc = 0,pos=0,i=0,metodo=0;
    bool ini=false;
    string elemento;
    tipo_dato valor;
    tipo_lista *L = inicializa();
        do{
        system ("clear");
        cout<<"\t--- Menú de Operaciones ---\n"<<'\n'
            <<"\t      0.- Inicializar"<<'\n'
            <<"\t      1.- Vacia"<<'\n'
            <<"\t      2.- Llena"<<'\n'
            <<"\t      3.- Insertar"<<'\n'
            <<"\t      4.- Eliminar"<<'\n'
            <<"\t      5.- Primero"<<'\n'
            <<"\t      6.- Ultimo"<<'\n'
            <<"\t      7.- Recupera"<<'\n'
            <<"\t      8.- Imprimir "<<'\n'
            <<"\t      9.- Anular "<<'\n'
            <<"\t      10.- Ordenar "<<'\n'
            <<"\t      11.- Busqueda "<<'\n'
            <<"\t      12.- Salir "<<'\n'
            <<"\n\t      Selecciona ~"; cin>>opc;
        switch (opc){
        case 0:
            system("clear");
            ini=true;
            cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
            cout<<"\t¡Se ha inicializado la Lista!"<<'\n';
            system("read -p '' var");
            break;
        case 1:
            system("clear");
            if(ini==false){
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"     ¡La Lista NO ha sido Inicializada!"<<'\n';
                system("read -p '' var");
            }else{
            int vacia(tipo_lista *L);
            if(vacia(L)){
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"\t    ¡La Lista esta Vacia!"<<'\n';
                system("read -p '' var");
            }
            else{
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"\t   ¡La Lista contiene elementos!"<<'\n';
                system("read -p '' var");
            }
          }
            break;
        case 2:
            system("clear");
            if(ini==false){
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"     ¡La Lista NO ha sido Inicializada!"<<'\n';
                system("read -p '' var");
            }else{
            if(llena(L)){
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"\t   ¡La Lista esta Llena!"<<'\n';
                system("read -p '' var");
            }
            else{
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"\t   ¡La Lista NO esta Llena!"<<'\n';
                system("read -p '' var");
            }
          }
            break;
        case 3:
            system("clear");
            if(ini==false){
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"     ¡La Lista NO ha sido Inicializada!"<<'\n';
                system("read -p '' var");
            }else{
            cout<<"\t--- Insertar un Elemento en la Lista ---"<<'\n';
            cout<<"\t Inserte un valor ~"; cin>>elemento;
            cout<<"\t Posición donde guardar ~"; cin>>pos;
            insertar(L, elemento, pos);
            cout<<"\n\t¡Se ha ingresado el valor con exito!"<<'\n';
            system("read -p '' var");
          }
            break;
        case 4:
            system("clear");
            if(ini==false){
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"     ¡La Lista NO ha sido Inicializada!"<<'\n';
                system("read -p '' var");
            }else{
            cout<<"\t--- Eliminar un Elemento en la Lista ---"<<'\n';
            cout<<"\t Digite un valor ~"; cin>>pos;
            elimina(pos,L);
            cout<<"\n\t¡Valor eliminado de la lista con exito!"<<'\n';
            system("read -p '' var");
          }
            break;
        case 5:
            system("clear");
            if(ini==false){
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"     ¡La Lista NO ha sido Inicializada!"<<'\n';
                system("read -p '' var");
            }else{
            tipo_pos primero(tipo_lista *L);
            cout<<"\t--- Verificación de Primer Elemento de la Lista ---"<<'\n';
            cout<<"\n\tEl Primer Elemento esta en el Index : "<< 0 <<'\n';
            system("read -p '' var");
          }
            break;
        case 6:
            system("clear");
            if(ini==false){
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"     ¡La Lista NO ha sido Inicializada!"<<'\n';
                system("read -p '' var");
            }else{
            cout<<"\t--- Verificación del Ultimo Elemento de la Lista ---"<<'\n';
            tipo_pos ultimo(tipo_lista *L);
            cout<<"\n\tEl Ultimo Elemento esta en el Index : "<< (L->ultimo)-1 <<'\n';
            system("read -p '' var");
          }
            break;
        case 7:
            system("clear");
            if(ini==false){
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"     ¡La Lista NO ha sido Inicializada!"<<'\n';
                system("read -p '' var");
            }else{
            cout<<"\t--- Recuperar un Elemento de la Lista---"<<'\n';
            cout<<"\n\tDigite una posición del elemento ~";
            cin>>pos;
            recupera(pos,L);
            if(true){
                cout<<L->datos[pos]<< '\n';
            }
            system("read -p '' var");
          }
            break;
        case 8:
            system("clear");
            if(ini==false){
                cout<<"\t--- Menú de Operaciones ---\n"<<'\n';
                cout<<"     ¡La Lista NO ha sido Inicializada!"<<'\n';
                system("read -p '' var");
            }else{
            cout<<"\t--- Imprimir los datos de la Lista---"<<'\n';
            imprime(L);
            cout<<"\n";
            system("read -p '' var");
          }
            break;
        case 9:
            system("clear");
            cout<<"\t--- Anular la lista Existente ---"<<'\n';
            anula(L);
            cout<<"\t¡La Lista fue vaciada con exito!"<<'\n';
            system("read -p '' var");
            break;
        case 10:
            system("clear");
            cout<<"\t--- Métodos de Ordenamiento ---"<<'\n'
            <<"\n\t      1.- Búrbuja"<<'\n'
            <<"\t      2.- Insersión"<<'\n'
            <<"\t      3.- Selección"<<'\n'
            <<"\t      4.- QuickSort"<<'\n'
            <<"\t      5.- MergeSort"<<'\n'
            <<"\n\t      Selecciona ~"; cin>>metodo;
            switch (metodo) {
              case 1:
                  burbuja(L);
                  system("read -p '' var");
                  break;
              case 2:
                  insersion(L);
                  system("read -p '' var");
                  break;
              case 3:
                  seleccion(L);
                  system("read -p '' var");
                  break;
              case 4:
                  quicksort(L,0,(L->ultimo)-1);
                  system("read -p '' var");
                  break;
              case 5:
                  mergesort(L,0,(L->ultimo)-1);
                  system("read -p '' var");
                  break;
            }
            break;
        case 11:
            system("clear");
            cout<<"\t--- Métodos de Busqueda ---"<<'\n'
            <<"\n\t      1.- Lineal"<<'\n'
            <<"\t      2.- Binaria"<<'\n'
            <<"\n\t      Selecciona ~"; cin>>metodo;
            switch (metodo) {
              case 1:
                  cout<<"\n\tIngrese un valor ~"; cin>>valor;
                  lineal(L,valor);
                  break;
              case 2:
                  cout<<"\n\tIngrese un valor ~"; cin>>valor;
                  binaria(L,valor);
                  break;
            }
            system("read -p '' var");
            break;
        case 12:
            system("clear");
            cout<<"Presione una tecla para salir..."<<'\n';
            system("read -p '' var");
            break;
        default:
            system("clear");
            cout<<"\t¡Esa no es una opción disponible!"<<'\n';
            system("read -p '' var");
            break;
        }
      }while(opc!=12);

    return 0;
}

int vacia (tipo_lista *L){

    if( L->ultimo ) return false;
    return true;
}

int llena (tipo_lista *L) {

    if( L->ultimo == TAMMAX-1) return true;
    return false;
}

void insertar( tipo_lista *L, tipo_dato elemento, tipo_pos pos ) {

    if( llena(L) or pos < 0 or pos > L->ultimo+1){
        cout<<"¡La Lista esta Llena!"<<'\n';
        return;
    }

    for( int i = L->ultimo ; i > pos; i--){
        L->datos[i] = L->datos[i-1];
    }

    L->datos[pos] = elemento;
    L->ultimo++;
}

void elimina(tipo_pos pos,tipo_lista *L){

    if(vacia(L) or pos < 0 or pos >= L->ultimo ){
        cout<<"¡Hay un error!"<<'\n';
        return;
    }

    for(int i(pos); i < L->ultimo; i++)
        L->datos[i-1] = L->datos[i];
    L->ultimo--;
}

void burbuja(tipo_lista *L){
    int len = (L->ultimo)-1;
    int j,i;
    tipo_dato aux;
    for(int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        if(L->datos[j] > L->datos[j+1]){
          aux = L->datos[j];
          L->datos[j] = L->datos[j+1];
          L->datos[j+1] = aux;
            }
        }
    }
}

void insersion(tipo_lista *L){
  int i=1,j;
  tipo_dato aux;
  while (i <= (L->ultimo)-1){
      aux = L->datos[i];
      j = i;
      while (j > 0 && aux < L->datos[j-1]) {
          L->datos[j] = L->datos[j-1];
          j--;
      }
      if (i!=j) {
          L->datos[j] = aux;
          i++;
      }
    }
}

void seleccion(tipo_lista *L){
    int i=0,j=0,menor;
    tipo_dato aux;
    while(i < L->ultimo){
        menor = i;
        j = i + 1;
        while(j <= (L->ultimo)-1){
            if (L->datos[j] < L->datos[menor]){
                menor = j;
            }
            j++;
        }
        if (menor != i){
            aux = L->datos[i];
            L->datos[i] = L->datos[menor];
            L->datos[menor] = aux;
        }
        i++;
    }
}

void quicksort(tipo_lista *L, int first, int last){
    int i,j;
    tipo_dato x,aux;

    x = L->datos[(first+last) / 2];
    i = first;
    j = last;

    do {
        while (L->datos[i] < x) {
            i++;
        }
        while (L->datos[j] > x) {
            j--;
        }
        if (i<=j) {
            aux = L->datos[i];
            L->datos[i] = L->datos[j];
            L->datos[j] = aux;

            i++;
            j--;
        }
    } while(i<=j);
    if (first < j) {
        quicksort(L,first,j);
    }
    if (i < last) {
        quicksort(L,i,last);
    }
}

void mergesort(tipo_lista *L, int first, int last){
    int i,k,z,half;
    tipo_dato* aux;

    if (first < last) {
        half = (first+last) / 2;
        mergesort(L,0,half);
        mergesort(L,half+1,last);

        aux = new tipo_dato[last - first + 1];
        i = z = first;
        k = half + 1;

        while (i<=half && k<=last) {
            if (L->datos[i] < L->datos[k]) {
                aux[z++] = L->datos[i++];
            }else{
                aux[z++] = L->datos[k++];
            }
        }
        while (i<=half) {
            aux[z++] = L->datos[i++];
        }
        while (k<=last) {
            aux[z++] = L->datos[k++];
        }
        for (int i = first; i < last; i++) {
            L->datos[i] = aux[i];
        }
        delete aux;
    }
}

void lineal(tipo_lista *L, tipo_dato pos){
    int i;
    for(int i = 0;i <= L->ultimo - 1; i++){
        if(pos == L->datos[i]){
          cout<<"El número se encuentra en : "<< i <<'\n';
        }
    }
}

void binaria(tipo_lista *L, tipo_dato pos){
    int first, last, half;

    first = 0;
    last = (L->ultimo) - 1;
    while(first <= last){
        half = (first + last) / 2;
        if (L->datos[half] == pos){
            cout<<"El elemento se encuenta en: "<< half <<'\n';
        }
        if(pos < L->datos[half]){
            last = half - 1;
        }
        else{
            first = half + 1;
        }
    }
}

tipo_pos primero(tipo_lista *L){
    if(vacia(L)) return -1;
    else return 0;
}

tipo_pos ultimo(tipo_lista *L){
    if ( vacia(L) ) return -1;
    return (L->ultimo)-1;
}

int recupera(tipo_pos pos,tipo_lista *L){
    if( vacia(L) or pos < 0 or pos >= L->ultimo){
      cout<<"¡No existe ese valor en la lista!"<<'\n';
    }else{
      return true;
    }
}

void imprime(tipo_lista *L){
    int i=0;
    while(i < L->ultimo){
        cout<<L->datos[i]<<'\n';
        i++;
    }
    L->datos[i++];
}

void anula(tipo_lista *L){ L->ultimo = 0; }
