#include <iostream>

class Node;
class Tree; 

class Node {
private:
    int value;
    Node *left;
    Node *right;
    void nullalized() { 
        this->left = nullptr;
        this->right = nullptr;
    }
public:
    Node(int value);

    friend class Tree;
};

Node::Node(int element){
    this->value = element;
    this->right = nullptr;
    this->left = nullptr;
}

// Tree Class

class Tree {
private:
    Node *ROOT;

    void __insert(Node*&, int);
    void __preOrder(Node*);
    void __inOrder(Node*);
    void __posOrder(Node*);
    Node* &__search(Node*&, int);
    Node* &__parent(Node*&, int);
    void __remove(Node*&, int);
    bool isLeaf(Node*&);
    
    Node* &minOf(Node*&);
    Node* &maxOf(Node*&);
    void __nullAll(Node*&);

public:
    Tree();
    bool empty();
    void insert(int);
    Node* search(int);
    void remove(int);
    // Tree Traversals
    void preOrder();
    void inOrder();
    void posOrder();
    void nullAll() { this->__nullAll(this->ROOT); this->ROOT = nullptr;} 
};

// Private Methods

void Tree::__insert(Node* &root, int value){
    if ( !root ) root = new Node(value);
    else {
        if(value > root->value) this->__insert(root->right, value);
        else this->__insert(root->left, value);
    }
}

void Tree::__preOrder(Node *root) {
    if ( root ) {
        std::cout << root->value << " ";
        this->__preOrder(root->left);
        this->__preOrder(root->right);
    }
}

void Tree::__inOrder(Node *root) {
    if ( root ) {
        this->__inOrder(root->left);
        std::cout << root->value << " ";
        this->__inOrder(root->right);
    }
}

void Tree::__posOrder(Node *root) {
    if ( root ) {
        this->__posOrder(root->left);
        this->__posOrder(root->right);
        std::cout << root->value << " ";
    }
}

Node* &Tree::__search(Node* &root, int value) {
    if ( !root ) return root;
    else {
        if ( root->value == value ) return root;
        else if ( value > root->value ) return this->__search(root->right, value);
        else return this->__search(root->left, value);
    }
}

Node* &Tree::__parent(Node* &root,int value){
    if ( !root ) return root;
    else {
        Node *temp;
        if ( value > root->value  ){
            temp = root->right;
            if( temp->value == value ){return root;}else{return this->__parent(temp, value);}
        }else{
            temp = root->left;
            if ( temp->value == value ){return root;}else{return this->__parent(temp, value);}
        }
    }
}

Node* &Tree::minOf(Node* &root) {
    if ( root ) {
        if ( root->left ) return this->minOf(root->left);
        return root;
    }
    return root;
}

Node* &Tree::maxOf(Node* &root) {
    if ( root ) {
        if ( root->right ) return this->maxOf(root->right);
        return root;
    }
    return root;
}

void Tree::__remove(Node* &root, int value) {
    if ( this->isLeaf(root) ) {
        Node *temp = this->__parent(this->ROOT,value);
        if ( temp->left == root ) temp->left = nullptr;
        else temp->right = nullptr;
        delete root;
    }
    else {
        Node* temp = nullptr;
        if ( root->left ) temp = maxOf(root->left); 
        else temp = minOf(root->right);
        
        Node *prev = this->__parent(this->ROOT,temp->value);

        if ( prev->left == temp ) prev->left = nullptr;
        else prev->right = nullptr;

        root->value = temp->value;

        delete temp;
    }
}

// Public Methods (Callers)

void Tree::insert(int value) { this->__insert(this->ROOT, value); }
Node* Tree::search(int value){ return this->__search(this->ROOT,value);}
void Tree::preOrder(){ this->__preOrder(this->ROOT); }
void Tree::inOrder(){ this->__inOrder(this->ROOT); }
void Tree::posOrder(){ this->__posOrder(this->ROOT); }

void Tree::remove(int value) {
    Node* temp = this->search(value);
    if ( temp ) this->__remove(temp, value);
}

Tree::Tree(): ROOT(nullptr) {}

bool Tree::empty(){ if(!this->ROOT){
    std::cout << "\n\t¡El Árbol está Vacio!" << std::endl;
    return false;
}else{
    std::cout << "\n\t¡El Árbol NO está Vacio!" << std::endl;
    return true;
    }
}

bool Tree::isLeaf(Node* &root){ return (!root->left and !root->right); }

void Tree::__nullAll( Node* &root ) {
    if( !root ) return;
    else {
        if ( isLeaf(root) ) delete root;
        else {
            __nullAll(root->left);
            __nullAll(root->right);
        }
    }
}

int main(){

    Tree a;

    bool transversal = false;
    int opc,data;

     do{
        system ("clear");

        if (transversal){std::cout << "<- Recorrido del Árbol" << std::endl << std::endl; transversal=false;}

        std::cout<<"\t\tMenú de Árbol Binario\n"<<'\n'
            <<"\t1.- Vacio"<<std::endl
            <<"\t2.- Insertar"<<std::endl
            <<"\t3.- Eliminar"<<std::endl
            <<"\t4.- Localizar"<<std::endl
            <<"\t5.- Recorre Pre-Order"<<std::endl
            <<"\t6.- Recorre In-Order"<<std::endl
            <<"\t7.- Recorre Post-Order"<<std::endl
            <<"\t8.- Anular"<<std::endl
            <<"\t9.- Salir"<<std::endl
            <<"\n\tSeleccione la opcion deseada -> ";
        std::cin >> opc;
        switch (opc){
        case 1:
            a.empty();
            system ("read -p '' var");
            break;
        case 2:
            std::cout << "\n\tDime un dato para insertar: ";
            std::cin >> data;
            a.insert(data);
            break;
        case 3:
            std::cout << "\n\tDime un dato para eliminar: ";
            std::cin >> data;
            a.remove(data);
            break;
        case 4:
            std::cout << "\n\tDime un dato para localizar: ";
            std::cin >> data;
            if(a.search(data)){
            std::cout << "\n\tEl valor " << data << " esta en el espacio de memoria: " << a.search(data) << std::endl;
            system("read -p '' var");
            }else{
            std::cout << "\n\tEl valor " << data << " NO esta en ningún espacio de memoria!" << std::endl;
            system("read -p '' var");
            }
            break;
        case 5:
            transversal = true;
            a.preOrder();
            break;
        case 6:
            transversal = true;
            a.inOrder();
            break;
        case 7:
            transversal = true;
            a.posOrder();
            break;
        case 8:
            a.nullAll();
            break;
            }
        }while(opc!=9);

    return 0;
}