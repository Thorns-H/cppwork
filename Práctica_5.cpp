#include <iostream>

#define TIPO_DATO int

using namespace std;

struct Nodo{
  TIPO_DATO dato;
  struct Nodo *siguiente;
};

void inicializa (struct Nodo *&);
bool vacia (struct Nodo *l);
void anula (struct Nodo *&l);
void insertar_i(struct Nodo *&l, TIPO_DATO d);
void insertar_p(struct Nodo *&l, TIPO_DATO d, int posicion, int elementos);
void eliminar(struct Nodo *&l,int pos, int elementos);
void imprimir (struct Nodo *l);
void localiza(struct Nodo *&l, TIPO_DATO d, int elementos);
void primero(struct Nodo *&l);
void ultimo(struct Nodo *&l,int elementos);
Nodo *anterior(Nodo *lista, unsigned int pos);


int main ()
{
  struct Nodo *ancla;
  inicializa(ancla);

  int opcion = 0;
  int elementos = 0;
  int posicion = 0;
  TIPO_DATO valor;

  do
    { 
      system("clear");
      cout<<"\t\t--- Menú de Operaciones ---\n"<<'\n'
            <<"\t1.- Vacia"<<'\n'
            <<"\t2.- Insertar elemento"<<'\n'
            <<"\t3.- Insertar elemento por posición"<<'\n'
            <<"\t4.- Eliminar"<<'\n'
            <<"\t5.- Anular"<<'\n'
            <<"\t6.- Localizar"<<'\n'
            <<"\t7.- Primero"<<'\n'
            <<"\t8.- Último"<<'\n'
            <<"\t0.- Salir"<<'\n';

            if(vacia (ancla)){
              cout << "" << '\n';
            }
            else{
              imprimir(ancla);
            }

            cout<<"\tSeleccione una opcion ~ ";
            cin >> opcion;

      switch (opcion)
	{
	case 0:
	  cout << "Saliendo..." << '\n';
	  break;
	case 1:
	  if (vacia (ancla)){
	    cout << "\n\t¡La Lista esta vacia!" << '\n';
      system("read -p '' var");
    }
	  else{
	    cout << "\n\t¡La Lista no esta vacia!" << '\n';
      system("read -p '' var");
    }
	  break;
	case 2:
	  cout << "\n\tDigita algún valor: ";
	  cin >> valor;
    elementos++;
	  insertar_i (ancla, valor);
	  break;
	case 3:
	  cout << "\n\tDame el valor a insertar: ";
	  cin >> valor;
    cout << "\n\tDame la posición: ";
	  cin >> posicion;
    if(posicion == 0){
      elementos++;
      insertar_i (ancla, valor);
    }else{
      elementos++;
      insertar_p(ancla, valor, posicion, elementos);
    }
	  break;
	case 4:
    cout << "\n\tDame la posición a eliminar: ";
	  cin >> posicion;
    eliminar(ancla,posicion,elementos);
    elementos--;
	  break;
	case 5:
	  anula(ancla);
    elementos = 0;
	  break;
  case 6:
    cout << "\n\tDime el valor a localizar: ";
	  cin >> valor;
    localiza(ancla,valor,elementos);
    break;
  case 7:
    primero(ancla);
    break;
  case 8:
    ultimo(ancla,elementos);
    break;
	default:
	  cout << "\n\t¡No existe esa opción!" << '\n';
	  break;
	}
    }
  while (opcion != 0);

  return 0;
}

void inicializa(struct Nodo *&l)
{
  l = nullptr;
}

bool vacia(struct Nodo *l)
{
  return l == nullptr;
}

void primero(struct Nodo *&l){
  
  struct Nodo *temp = l;

  if(vacia(temp)){
    cout << "\n\t¡La Lista esta vacia!" << '\n';
    system("read -p '' var");
  }else{
    cout << "\n\t\t¡El Primer Nodo contiene el Dato : " << temp->dato << "!" <<'\n';
    system("read -p '' var");
  }
}

void ultimo(struct Nodo *&l,int elementos){
  
  struct Nodo *temp = l;

  if(vacia(temp)){
    cout << "\n\t¡La Lista esta vacia!" << '\n';
    system("read -p '' var");
  }else{
    for(int i = 0; i<elementos-1; i++){
        temp = temp->siguiente;
  }
  cout << "\n\t\t¡El Último Nodo contiene el Dato : " << temp->dato << "!" <<'\n';
  system("read -p '' var");
  }
}

void insertar_i(struct Nodo *&l, TIPO_DATO d){
  struct Nodo *aux = nullptr;

  aux = new struct Nodo;

  if (aux != nullptr) 
    {
      aux->dato = d;
      aux->siguiente = l;
      l = aux;
    }
  else
    {
      cout<<"\n\t¡La Lista esta Llena!"<<'\n';
    }
}

void insertar_p(struct Nodo *&l, TIPO_DATO d, int pos,int elementos){

    struct Nodo *temp = l;
    struct Nodo *aux = new struct Nodo;

    if (pos > elementos or pos < 0){
      cout << "¡Posición inválida!";
    }else{
      for(int i = 0; i<pos-1; i++){
        temp = temp->siguiente;  
    }
    aux->dato = d;
    aux->siguiente = temp->siguiente;
    temp->siguiente = aux;
  }
}

void localiza(struct Nodo *&l, TIPO_DATO d, int elementos){

    struct Nodo *temp = l;
    bool finded = false;

    for(int i = 0; i<elementos; i++){
        if (temp->dato == d){
            cout << "\n\t\tEl valor " << d << " se localiza en el Nodo [" << i << "]" << "\n";
            finded = true;
            system("read -p '' var");
        }
        temp = temp->siguiente;
      }
    if(finded == false){
      cout<<"\n\t¡No existe ese dato en ningún Nodo!"<<'\n';
      system("read -p '' var");
    }
  }

void imprimir(struct Nodo *l)
{ 
  cout << "\n\t\t\tOrden de la Lista" << "\n";
  cout << "\t\tAncla -> ";
  while (l != nullptr)
    {
      cout << l->dato << " -> ";
      l = l->siguiente;
    }
  cout << "NULL" << '\n' << '\n';
}

void anula (struct Nodo *&l)
{
  if (vacia (l))
    {
      cout << "\n\t¡La Lista esta vacia!" << '\n';
      system("read -p '' var");
    }
  else
    {
      anula (l->siguiente);
      delete l;
      l = nullptr;
    }
}

void eliminar(Nodo *&lista, int pos , int elementos) {

    if(lista and pos<elementos){

        Nodo *aux = lista;
        
        if(!pos){
          lista = lista->siguiente;
        }else{
            Nodo *anterior;
            for(int i = 0; i < pos-1; i++) {
                aux = aux->siguiente;
            }
            anterior = aux;
            aux = aux->siguiente;
            anterior->siguiente = aux->siguiente;
        }
        delete aux;
    }else{
      cout << "¡Posición Invalida!";
    } 
}

Nodo *anterior(Nodo *lista, unsigned int pos){
    if (pos == 0){
        return nullptr;
    }
    while(lista != nullptr and pos > 1){
        lista = lista->siguiente;
        pos--;
    }
    return lista;
}