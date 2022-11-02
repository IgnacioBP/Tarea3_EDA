#include <iostream>
#include "trees/tree.hpp"
#include <cstring>
#include <sstream>  
#include <vector>
using namespace std;


//cd        1
//ls        2
//mkdir     3
//mkfile    4
//rm        5
//tree      6
//find      7
//exit


int main(){
    //INTRO PROGRAMA
    cout<<"¡Bienvenido a TreeSO!"<<endl;
    cout<<"¡Autores: Andrea Arredondo e Ignacio Bravo!"<<endl;
    cout<<endl;
    //FIN INTRO PROGRAMA

    //INICIO DECLARACION DE VARIABLES PRE-PROGRAMA
    string order;
    string path="/";
    string segment;
    trees::TreeNode* actual=new trees::TreeNode("/");
    
    int flag=0;
    int mod=0;
    //FIN DE DECLARACION VARIABLES

    //CREACION DE ARBOL S.O
    trees::Tree sistem;
    sistem.setRoot(actual);
    
    //FIN DE CREACION DE ARBOL S.O

    while(order!="exit"){
        
        cout<<"Ingrese instruccion"<<endl;
        cout<<path<<"#"; //mostrar el path y el simbolo par input
        getline(cin, order);//ingresar instruccion

        stringstream X(order);
        while (getline(X, segment, ' ')) { 
            if (mod==0){
                if(segment=="cd" && flag==0 ){
                    flag=1;
                }
                else if(segment=="ls"&& flag==0){
                    flag=2;
                }
                else if(segment=="mkdir"&& flag==0){
                    flag=3;
                }
                else if(segment=="mkfile"&& flag==0){
                    flag=4;
                }
                else if(segment=="rm"&& flag==0){
                    flag=5;
                }
                else if(segment=="tree"&& flag==0){
                    flag=6;
                }
                else if(segment=="find"&& flag==0){
                    flag=7;
                }
                else{
                    cout<<"No se reconoce instruccion: "<<segment<<endl;
                }
            }
            else{
                
            }
            
        }  

        cout<<"Tu instruccion es: "<<order<<endl;
    }
    return 0;
}