#include <iostream>

using namespace std;

class nodo
{
    nodo *sig;
    int dato;
    friend class Lista;
};

class Lista
{
    nodo *h;
    public:
        void Inicializa();
        bool Vacia();
        int Tamano();
        void InsertaInicio(int dato);
        void InsertarFinal(int dato);
        void InsertarPosicion(int dato, int pos);
        int Recupera(int pos);
        int Localiza(int dato);
        void Imprimir();
        void Eliminar(int pos);
        void Anular();
        void Primero();
        void Ultimo();

};

void Lista::Inicializa()
{
    h = nullptr;
}

bool Lista::Vacia()
{
    if(h == nullptr)
    {
        return true;
    }
    else{
        return false;
    }
}

int Lista::Tamano()
{
    int cont = 0;
    nodo *aux;
    aux = h;
    while(aux == nullptr)
    {
        cont++;
        aux = aux->sig;
    }
    return cont;
}

void Lista::InsertaInicio(int dato)
{
    nodo *tmp = new nodo;
    tmp->dato = dato;
    tmp->sig =nullptr;
    if(Vacia()){
        h = tmp;
    }else{
        tmp->sig = h;
        h = tmp;
    }
}

void Lista::InsertarFinal(int dato)
{
    nodo *tmp = new nodo;
    tmp->dato = dato;
    tmp->sig =nullptr;
    if(Vacia()){
        h = tmp;
    }else{
        nodo *aux;
        aux = h;
        while(aux->sig != nullptr)
        {
            aux = aux->sig;
        }
        aux->sig = tmp;
    }
}

void Lista::InsertarPosicion(int dato, int pos)
{
    nodo *tmp = new nodo;
    tmp->dato = dato;
    tmp->sig = nullptr;
    if(Vacia()){
        h = tmp;
    }else{
        if(pos == 0)
        {
            InsertaInicio(dato);
        }else{
            if(pos == Tamano())
        {
            InsertarFinal(dato);
        }
            else{
            nodo *aux, *aux2;
            aux = h;
            for(int i=0; i<pos; i++)
            {
                aux2 = aux;
                aux= aux->sig;
            }
            aux2->sig = tmp;
            tmp->sig = aux;
        }   
        }
        
    }
}

int Lista::Recupera(int pos)
{
    nodo *aux;
    aux = h;
        for(int i = 0; i<=pos-1; i++)
        {
            aux = aux->sig;
        }
        cout << "\n\tEl dato "<< aux->dato <<" esta en la posición " << pos << '\n';
        system("read -p '' var");
    return -1;
}

int Lista::Localiza(int dato)
{
    int cont = 0;
    bool find = false;
    nodo *aux;
    aux = h;
    while(aux != nullptr)
    {
        if(aux->dato == dato)
        {
            cout << "\n\tEl dato esta en la posición : " << cont << '\n';
            find = true;
            system("read -p '' var");
            break;
        }
        cont++;
        aux = aux->sig;
    }
    if(find == false){
        cout << "\n\tEl dato " << dato << " no esta en la lista!"<<'\n';
        system("read -p '' var");
    }
    return -1;
}

void Lista::Imprimir()
{
    nodo *aux;
    aux = h;
    cout << '\n';

    while(aux != nullptr)
    {
        cout<<"\t"<<aux->dato<<'\n';
        aux = aux->sig;
    }
    system("read -p '' var");
}

void Lista::Anular()
{
    nodo *aux;

    while(aux != nullptr)
    {
        aux = h;
        h = nullptr;
        delete(aux);
    }
}

void Lista::Eliminar(int pos)
{
    nodo *aux, *behind;
    aux = h;

    if(pos == 0){
        h = h->sig;
    }else{
    for(int i = 0; i < pos-1; i++){
        aux = aux->sig;
    }
    behind = aux;
    aux = aux->sig;
    behind->sig = aux->sig;
    }
    delete aux;
}

void Lista::Primero()
{
    nodo *aux;
    aux = h;
    cout<<"\n\tEl primer dato de la lista es: "<<aux->dato<<'\n';
    system("read -p '' var");
}

void Lista::Ultimo()
{
    nodo *aux;
    aux = h;
    while(aux->sig != nullptr)
        {
            aux = aux->sig;
        }
    cout<<"\n\tEl ultimo valor de la lista es: "<< aux->dato <<'\n';
    system("read -p '' var");
}

int main()
{
    int opc;
    Lista l;
    l.Inicializa();
    int num, pos;
    do
    {
        system("clear");
        cout <<"\t--- Menú Principal de Operaciones ---" <<'\n' <<'\n'
          <<"\t1.- Vacia" <<'\n'
          <<"\t2.- Insertar"<<'\n'
          <<"\t3.- Eliminar" <<'\n'
          <<"\t4.- Anular" <<'\n'
          <<"\t5.- Primero" <<'\n'
          <<"\t6.- Ultimo" <<'\n'
          <<"\t7.- Localiza" <<'\n'
          <<"\t8.- Recupera" <<'\n'
          <<"\t9.- Imprimir" <<'\n'
          <<"\t0.- Salir" <<'\n'
          <<"\n\tSelecciona una operación ~ ";
        cin >>opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
            if(l.Vacia())
            {
                cout<<"\n\t¡La Lista esta Vacia!"<<'\n';
                system("read -p '' var");
            }else{
                cout<<"\n\t¡La Lista NO esta Vacia!"<<'\n';
                system("read -p '' var");
            }

            break;
        case 2:

            cout<<"\n\tIngresa un numero: ";
            cin>>num;
            cout<<"\tIngresar la posicion: ";
            cin>>pos;
            l.InsertarPosicion(num, pos);
            cin.get();

            break;
        case 3:
            if(l.Vacia())
            {
                cout<<"\n\t¡La Lista esta Vacia!"<<'\n';
            }else{
                cout<<"\n\tIngrese la posicion a eliminar: ";
                cin>>pos;
                l.Eliminar(pos);
                cout<<"\n\t¡Elemento eliminado!"<<'\n';
                system("read -p '' var");
            }
            cin.get();

            break;
        case 4:
            cout<<"\n\t¡Lista Anulada!"<<'\n';
            l.Anular();
            system("read -p '' var");
            break;
        case 5:
            l.Primero();
            break;
        case 6:
            l.Ultimo();
            break;
        case 7:
            cout<<"\n\tInserte dato a localizar: ";
            cin>>num;
            l.Localiza(num);
            break;
        case 8:
            cout<<"\n\tInserte un index a recuperar: ";
            cin>>pos;
            l.Recupera(pos);
            break;
        case 9:
            l.Imprimir();
            break;
        case 0:
            break;
        default:
            cout <<"Opción no válida" <<'\n' <<'\n';
        }
    }
    while(opc != 0);
    return 0;
}
