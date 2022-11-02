#include <iostream>
#include "trees/tree.hpp"
#include <cstring>

using namespace std;

int main(){
    //INTRO PROGRAMA
    cout<<"¡Bienvenido a TreeSO!"<<endl;
    cout<<"¡Autores: Andrea Arredondo e Ignacio Bravo!"<<endl;
    cout<<endl;
    //FIN INTRO PROGRAMA

    //INICIO DECLARACION DE VARIABLES PRE-PROGRAMA
    string order;
    string path="/";
    //FIN DE DECLARACION VARIABLES

    //CREACION DE ARBOL S.O

    trees::Tree sistem;
    sistem.setRoot(new trees::TreeNode("/"));

    while(order!="salir"){

        cout<<"Ingrese instruccion"<<endl;
        cout<<path<<"#"; //mostrar el path y el simbolo par input
        cin>>order;//ingresar instruccion
        cout<<"Tu instruccion es: "<<order<<endl;
    }
    
    return 0;
}