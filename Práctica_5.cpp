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
void eliminar(struct Nodo *&l, int posicion);
void imprimir (struct Nodo *l);


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
      imprimir (ancla);
      cout<<"                      Menu\n"<<'\n'
            <<"1.- Vacia"<<'\n'
            <<"2.- Insertar elemento al inicio"<<'\n'
            <<"3.- Insertar elemento por posicion"<<'\n'
            <<"4.- Eliminar"<<'\n'
            <<"5.- Anular"<<'\n'
            <<"0.- Salir"<<'\n'
            <<"\nSeleccione la opcion deseada -> ";
      cin >> opcion;

      switch (opcion)
	{
	case 0:
	  cout << "Nos vemos pronto..." << '\n';
	  break;

	case 1:
	  if (vacia (ancla))
	    cout << "Lista Vacia" << '\n';
	  else
	    cout << "Lista No Vacia" << '\n';
	  break;
	case 2:
	  cout << "Dame el valor a insertar al inicio: ";
	  cin >> valor;
    elementos++;
	  insertar_i (ancla, valor);
	  break;
	case 3:
	  cout << "Dame el valor a insertar: ";
	  cin >> valor;
    cout << "Dame la posición: ";
	  cin >> posicion;
    elementos++;
	  insertar_p(ancla, valor, posicion, elementos);
	  break;
	case 4:
	  /*
	      Implementar codigo para eliminar por posicion
	  */
	  break;

	case 5:
	  anula(ancla);
	  break;

	default:
	  cout << "Opcion Incorrecta!!!" << '\n';
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
      cout<<"La lista esta llena..."<<'\n';
    }
}

void insertar_p(struct Nodo *&l, TIPO_DATO d, int pos,int elementos){
    struct Nodo *temp = l;
    struct Nodo *aux = new struct Nodo;

    if (pos > elementos or pos < 0){
      cout << "¡Posición inválida!";
    }

    for(int i = 0; i<pos-1; i++) {
      temp = temp->siguiente;
    }
    aux->dato = d;
    aux->siguiente = temp->siguiente;
    temp->siguiente = aux;
}

void imprimir (struct Nodo *l)
{
  cout << "ancla-> ";
  while (l != nullptr)
    {
      cout << l->dato << "-> ";
      l = l->siguiente;
    }
  cout << "nullptr" << '\n' << '\n';
}


void anula (struct Nodo *&l)
{
  if (vacia (l))
    {
      cout << "¡La Lista esta vacia!" << '\n';
    }
  else
    {
      anula (l->siguiente);
      delete l;
      l = nullptr;
    }

}

