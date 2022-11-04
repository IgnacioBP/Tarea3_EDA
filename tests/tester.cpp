#include <iostream>
#include "trees/tree.hpp"
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;



string PATH="/";
string TEMP_PATH;


trees::TreeNode* dentro_path(trees::TreeNode* actual, string name){
    string nueva_direccion;
    trees::TreeNode* node = new trees::TreeNode;
    //lo que haremos aca sera recorrer los nodos buscando de a poco el path
    //en el cual queremos entrar, por lo que buscaremos de a poco dentro de este
    node = actual;
    //armamos de a poco la direccion
    for(int i=1;i<name.length();i++){
        if(name[i]!='/'){
            nueva_direccion += name[i];
        }
        else{
            //revisamos que el children no sea nodo terminal y que ademas se encunetre la direccion en
            //la altura(recordar que getCildren de este nodo me retorna una LinkedList que es TreeList)
            if(node->getChildren()!=nullptr && node->getChildren()->find(nueva_direccion)!=nullptr){
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
//el concepto de esta funcion es el mismo pero dado que la necesito para hacer el cd
//lo que utilice fue pasar por referencia una string para poder devolver tanto
//el nodo que necesitaba como el nuevo path para mostrarlo en la dir
trees::TreeNode*  dentro_path(trees::TreeNode* actual,string name,string* final_path,string actual_path){
    string dir;
    string nueva_dir;
    trees::TreeNode* node = new trees::TreeNode;
    node = actual;
    nueva_dir = actual_path;

    for(int i=1;i<name.length();i++){
        if(name[i]!='/'){
            dir += name[i];
        }
        else{
            if(node->getChildren()!=nullptr && node->getChildren()->find(dir)!=nullptr){
                node = node->getChildren()->find(dir);
                nueva_dir+=dir;
                nueva_dir+="/";
                dir="";
            }
            else{
                node = nullptr;
                break;
            }
        }
    }
    *final_path = nueva_dir;
    return node;

}

//Esta funcion es muy similiar al traverse de los trees pero tiene la particularidad de que va
//comparando con el PATH que es una variable global la cual nos permite reiniciar la variable para
//asi mostrar la posicionde cada una de las apariciones.
void find_rec(trees::TreeNode* node,string name,string path){
    if(node!=nullptr){
        if(node->getData()==name){
            cout<<path<<endl;
        }
        trees::TreeList* childrenList = node->getChildren();
        trees::TreeListNode* ptr = childrenList->getHead();
        while(ptr!=nullptr){
            path+=ptr->getData()->getData();
            path+="/";
            find_rec(ptr->getData(),name,path);
            ptr = ptr->getNext();
            path=PATH;

        }

    }
}

void find(trees::TreeNode* actual,string name,string path){
    find_rec(actual,name,path);
}

int main(){
    //INTRO PROGRAMA
    cout<<"¡Bienvenido a TreeSO!"<<endl;
    cout<<"¡Autores: Andrea Arredondo e Ignacio Bravo!"<<endl;
    cout<<endl;
    //FIN INTRO PROGRAMA

    //INICIO DECLARACION DE VARIABLES PRE-PROGRAMA
    string order;

    //DESPUES RENOMBRALAS GRACIAS
    string param1 ="";
    string instruction="";
    string param2="";

    trees::TreeNode* actual=new trees::TreeNode("/",0); //0 es carpeta y 1 es archivo


    //FIN DE DECLARACION VARIABLES

    //CREACION DE ARBOL S.O
    trees::Tree sistem;
    sistem.setRoot(actual);

    //Flow Principal
    while(order!="exit"){

        cout<<"Ingrese instruccion"<<endl;
        cout<<PATH<<"#"; //mostrar el path y el simbolo par input
        instruction="";
        param1="";
        param2="";
        getline(cin, order);//ingresar instruccion

        //separamos por espacio los parametros
        istringstream X(order);
        if(X)
            X>>instruction;
        if(X)
            X>>param1;
        if(X)
            X>>param2;

        //primera operacion mkdir
        if(instruction=="mkdir"){
            trees::TreeNode* nueva_carpeta = new trees::TreeNode(param1,0);
            if(param2==""||param1=="."){
                nueva_carpeta->setParent(actual);//seteo como padre el nodo actual en el
                //que voy a insertar
                //reviso si param2 es el nombre del archivo
                if(param1=="."){
                nueva_carpeta->setData(param2);
                }

                //Inserto el nuevo nodo en el hijo del actual(el children es un TreeList)
                actual->getChildren()->insertFirst(nueva_carpeta);
            }

            else{
                trees::TreeNode* node= dentro_path(actual, param1);

                if(node==nullptr){
                    std::cout<<"No existe esta dirección en el sistema"<<endl;
                }
                else{
                    if(node->isFile()!=1){
                        nueva_carpeta->setParent(node);
                        nueva_carpeta->setData(param2);
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
            trees::TreeNode* nueva_carpeta = new trees::TreeNode(param1,1);
            if(param2==""||param1=="."){
                nueva_carpeta->setParent(actual);//seteo como padre el nodo actual en el
                //que voy a insertar

                if(param1=="."){
                    nueva_carpeta->setData(param2);
                }

                //Inserto el nuevo nodo en el hijo del actual(el children es un TreeList)
                actual->getChildren()->insertFirst(nueva_carpeta);
            }
            else{

                trees::TreeNode* node= dentro_path(actual, param1);

                if(node==nullptr){
                    std::cout<<"No existe esta dirección en el sistema"<<endl;
                }
                else{
                    if(node->isFile()!=1){

                        nueva_carpeta->setParent(node);
                        nueva_carpeta->setData(param2);
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
            trees::TreeNode* actual_node=actual->getChildren()->find(param1);

            if(param2 == ""){
                //cuando es rm nombre
                //aca solo buscamos en el treeList si es que es archivo, si es así, tenemos que borarr de manera
                //que se borre todo lo que esta adentr
                if(actual_node->isFile()==0){
                    actual_node->getChildren()->removeAll();
                    actual->getChildren()->remove(param1);
                }
                else
                //Si no, usamos el metodo de treeList para eliminar el nodo(archivo)
                    actual->getChildren()->remove(param1);
            }
            else if(param2=="."){
                //Borra dentro de la misma carpeta
                if(actual_node->isFile()==0){
                    actual_node->getChildren()->removeAll();
                    actual->getChildren()->remove(param1);
                }
                else
                    actual->getChildren()->remove(param1);
            }
        }

        //acaba el ls
        if(instruction=="ls"){
            if(param1==""||param1=="."){
                //solo mandamos el print predeterminado :D
                actual->getChildren()->print();
            }
            else{
                trees::TreeNode* node= dentro_path(actual, param1);

                if(node==nullptr){
                    std::cout<<"No existe esta dirección en el sistema"<<endl;
                }
                else{
                    node->getChildren()->print();
                }
            }
        }

        //cd
        else if(instruction=="cd"){

            //revisamos para volver a la carpeta anterior y que no sea null el parent
            //por ende, que no sea root el actual
            if (param1==".." && actual->getParent()!=nullptr){
                //buscamos donde empieza el nombre del path y lo cortamos con una substring
                string new_path;
                new_path = PATH.substr(0,PATH.find(actual->getData()));

                //seteamos el actual a su parent
                actual = actual->getParent();

                //seteamos el PATH a la ubicacion de la actual
                PATH = new_path;
            }
            else{
                //buscamos el node donde queremos ir
                string new_path;
                trees::TreeNode* node = dentro_path(actual,param1,&new_path,PATH);
                //si no lo encuentra, nullptr y pa fuera
                if(node==nullptr){
                    cout<<"No existe esta direccion en el sistema"<<endl;
                }
                //de encontrarlo, cambiamos el actual a ese nodo y seteamos el path
                //a su ubicación
                else{
                    actual=node;
                    PATH = new_path;
                }
            }
        }

        //Tree
        else if(instruction=="tree"){
            if(param1 =="."||param1==""){
                sistem.traverse_rec(actual,1);
            }
            else{
                trees::TreeNode* node = dentro_path(actual,param1);
                sistem.traverse_rec(node,1);
            }
        }

        //Find
        else if(instruction=="find"){
            if(param2==""){
                find(actual,param1,PATH);
            }
            else if(param1 =="."){
                find(actual,param2,PATH);
            }
            else{
                string new_path;

                trees::TreeNode* node = dentro_path(actual,param1,&new_path,PATH);
                if (node==nullptr){
                    cout<<"No existe esta direccion en el sistema"<<endl;
                }
                else{
                    TEMP_PATH=new_path;
                    find(node,param2,TEMP_PATH);
                }

            }
        }


    }
    return 0;
}
