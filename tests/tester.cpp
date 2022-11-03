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

trees::TreeNode* dentro_path(trees::TreeNode* actual, string name){
    string nueva_direccion;
    trees::TreeNode* node = new trees::TreeNode;
    //lo que haremos aca sera recorrer los nodos buscando de a poco el path
    //en el cual queremos entrar, por lo que buscaremos de a poco dentro de este
    node = actual;
    //armamos de apoco la direccion
    for(int i=1;i<name.length();i++){
        if(name[i]!='/'){
            nueva_direccion += name[i];
        }
        else{
            //revisamos que el children no sea nodo terminal y que ademas se encunetre la direccion en
            //la altura(recordar que getCildren de este nodo me retorna una LinkedList que es TreeList)
            if(node->getChildren()!=nullptr && node->getChildren()->find(nueva_direccion)!=nullptr){
                cout<<node->getData()<<endl;
                node = node->getChildren()->find(nueva_direccion);
                nueva_direccion="";
                //Si cumple lo ponemos
            }
            else{
                node = nullptr;
                break;
                //si no, break
            }
        }

    }
    // cout<<nueva_direccion<<endl;
    // cout<<node->getData()<<endl;
    return node;
}

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

    //DESPUES RENOMBRALAS GRACIAS
    string name ="";
    string instruction="";
    string file="";

    trees::TreeNode* actual=new trees::TreeNode("/",0); //0 es carpeta y 1 es archivo
    
    int flag=0;
    int mod=0;
    //FIN DE DECLARACION VARIABLES

    //CREACION DE ARBOL S.O
    trees::Tree sistem;
    sistem.setRoot(actual);
    // sistem.insert("archivo1","/",1);
    // sistem.insert("carpeta1","/",0);
    // sistem.insert("carpeta3","/",0);
    // sistem.insert("archivo2","carpeta1",1);
    // sistem.insert("carpeta2","archivo2",0);
    // sistem.insert("archivo5","carpeta3",1);
    // sistem.insert("archivo3","carpeta2",1);
    // sistem.insert("archivo4","carpeta2",1);
    // sistem.traverse();
    //FIN DE CREACION DE ARBOL S.O

    
    

    while(order!="exit"){
        
        cout<<"Ingrese instruccion"<<endl;
        cout<<path<<"#"; //mostrar el path y el simbolo par input
        instruction="";
        name="";
        file="";
        getline(cin, order);//ingresar instruccion

        istringstream X(order);
            if(X)
            X>>instruction;
            if(X)
            X>>name;
            if(X)
            X>>file;
            
        //primera operacion mkdir
        if(instruction=="mkdir"){
            trees::TreeNode* nueva_carpeta = new trees::TreeNode(name,0);
            if(file==""||file=="."){
                nueva_carpeta->setParent(actual);//seteo como padre el nodo actual en el 
                //que voy a insertar

                //Inserto el nuevo nodo en el hijo del actual(el children es un TreeList)
                actual->getChildren()->insertFirst(nueva_carpeta);
            }
            
            else{
                trees::TreeNode* node= dentro_path(actual, name);
                
                if(node==nullptr){
                    std::cout<<"No existe esta dirección en el sistema"<<endl;
                }
                else{
                    if(node->isFile()!=1){
                        nueva_carpeta->setParent(node);
                        nueva_carpeta->setData(file);
                        sistem.insert(nueva_carpeta,node); 
                    }
                    else{
                        cout<<"no es posible insertar en un archivo"<<endl;

                    }
                    
                }

            }

        } 

        //MKFILE
        if(instruction=="mkfile"){
            //este es archivo asi que lol
            trees::TreeNode* nueva_carpeta = new trees::TreeNode(name,1);
            if(file==""||file=="."){
                nueva_carpeta->setParent(actual);//seteo como padre el nodo actual en el 
                //que voy a insertar

                //Inserto el nuevo nodo en el hijo del actual(el children es un TreeList)
                actual->getChildren()->insertFirst(nueva_carpeta);
            
            }
            //este es netamente opcional y puedes borrarlo lol
            else{
                trees::TreeNode* node= dentro_path(actual, name);
                
                
                if(node==nullptr){
                    std::cout<<"No existe esta dirección en el sistema"<<endl;
                }
                else{
                    if(node->isFile()!=1){
                        cout<<node->isFile()<<endl;
                        cout<<node->getData()<<endl;

                        nueva_carpeta->setParent(node);
                        nueva_carpeta->setData(file);
                        sistem.insert(nueva_carpeta,node);
                    }
                    else{
                        cout<<"no es posible insertar en un archivo"<<endl;
                    }
                    
                }

            }
        

        }

        //RM 
        if (instruction=="rm"){
            if(file == ""){
                //cuando es rm nombre
                //aca solo buscamos en el treeList si es que es archivo, si es así, tenemos que borarr de manera 
                //que se borre todo lo que esta adentr
                trees::TreeNode* actual_node=actual->getChildren()->find(name);
                if(actual_node->isFile()==0){
                    actual_node->getChildren()->removeAll();
                    actual->getChildren()->remove(name);
                }
                else
                //Si no, usamos el metodo de treeList para eliminar el nodo(archivo)
                    actual->getChildren()->remove(name);
            }
            else if(file=="."){
                //Borra dentro de la misma carpeta
                trees::TreeNode* actual_node=actual->getChildren()->find(name);
                if(actual_node->isFile()==0){
                    actual_node->getChildren()->removeAll();
                    actual->getChildren()->remove(name);
                }
                else
                    actual->getChildren()->remove(name);
            }
        }

        //acaba el ls
        if(instruction=="ls"){
            if(name==""||name=="."){
                //solo mandamos el print predeterminado :D
                actual->getChildren()->print();
            }
            else{
                trees::TreeNode* node= dentro_path(actual, name);
                
                if(node==nullptr){
                    std::cout<<"No existe esta dirección en el sistema"<<endl;
                }
                else{
                    node->getChildren()->print();
                }


            }
        }

        //cd







        //LO QUE TENIAS TU
        // while (getline(X, segment, ' ')) { 
        //     if (mod==0){
        //         if(segment=="cd" && flag==0 ){
        //             flag=1;
        //             mod=1;
        //             cout<<"entro aquí"<<endl;
                
        //         }
        //         else if(segment=="ls"&& flag==0){
        //             flag=2;
        //             mod=1;
        //         }
        //         else if(segment=="mkdir"&& flag==0){
        //             flag=3;
        //             mod=1;
        //         }
        //         else if(segment=="mkfile"&& flag==0){
        //             flag=4;
        //             mod=1;
        //         }
        //         else if(segment=="rm"&& flag==0){
        //             flag=5;
        //             mod=1;
        //         }
        //         else if(segment=="tree"&& flag==0){
        //             flag=6;
        //             mod=1;
        //         }
        //         else if(segment=="find"&& flag==0){
        //             flag=7;
        //             mod=1;
        //         }
        //         else{
        //             cout<<"No se reconoce instruccion: "<<segment<<endl;
        //         }
        //     }
        //     else if(flag==1){
        //         actual= sistem.find(segment);
        //         cout<<"Estoy en --"<<actual->getUbication()<<endl;
        //         mod=0;
        //         flag=0;
                
        //     }
            
        // }  

        //cout<<"Tu instruccion es: "<<order<<endl;
    }
    sistem.traverse();
    return 0;
}