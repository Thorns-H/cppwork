#include <iostream>
#define TIPO_DATO int

using namespace std;

class Nodo{
    private:
        TIPO_DATO elem;
        Nodo *hijo_izq;
        Nodo *hijo_der;
    public:
        Nodo(TIPO_DATO elem);
        void insertar(TIPO_DATO dato);
        void rec_preorden(int nivel);
};

Nodo::Nodo(TIPO_DATO elem)
{
    this -> elem = elem;
    hijo_der = nullptr;
    hijo_izq = nullptr;
}


void Nodo::insertar(TIPO_DATO dato)
{
    if( dato < elem){
        if(hijo_izq == nullptr){
            hijo_izq = new Nodo(dato);
        } else {
            hijo_izq->insertar(dato);
        }
    } else {
        if(hijo_der == nullptr){
            hijo_der = new Nodo(dato);
        } else {
            hijo_der->insertar(dato);
        }
    }
}


void Nodo::rec_preorden(int nivel)
{
    for (int i = 0 ; i < nivel ; i++) {
        std::cout << "  ";
    }
    std::cout << elem << std::endl;
    if(hijo_izq !=nullptr){
        hijo_izq->rec_preorden(nivel+1);
    }
    
    if(hijo_der !=nullptr){
        hijo_der->rec_preorden(nivel+1);
    }
}


class Arbol{
    private:
    Nodo * raiz; //ancla
    public:
    Arbol();
    bool vacia();
    void insertar(TIPO_DATO dato);
    
    void rec_preorden();
    
};


Arbol::Arbol()
{
    raiz = nullptr;
}


bool Arbol::vacia()
{
    return raiz == nullptr;
}


void Arbol::insertar(TIPO_DATO dato)
{
    if(this->vacia()){
        raiz = new Nodo(dato);
    } else {
        raiz->insertar(dato);
    }
}

void Arbol::rec_preorden()
{
    if(not this->vacia()){
        raiz->rec_preorden(0);
    }
}

int main()
{
    Arbol miArbolito;
    
    miArbolito.insertar(4);
    miArbolito.insertar(2);
    miArbolito.insertar(6);
    miArbolito.insertar(3);
    miArbolito.insertar(5);
    miArbolito.insertar(7);
    miArbolito.insertar(1);
    
    miArbolito.rec_preorden();


    return 0;
}