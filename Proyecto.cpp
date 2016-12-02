/*Nombre: Natalia Isabel Hernandez Naveros
Fecha:01 Dic 2016
Proyecto Final*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <windows.h>
#include <cstdlib>
#define US "Natalia"
#define PASS "Naveros"
using namespace std;
//usuario
int id=0;
char nombre [50];
char usern [30];
char password[30];
char fechacreacion[30];
int tipodeusuario;

//producto
float idp;
char nombrep[30];
float valor;
char fechaproducto[30];
char usuariocreacion[30];

//ventas
float idv;
char usuarioventa [30];
char productoventa [30];
float valorv;
char fechaventa[30];

// Funcion Menu
void menu();

//Funcion Usuario
void crearusuario();
void editarusuario();
void eliminarusuario();
void cerrarsesion();
void listadeusuarios();

//Funciones Producto
void crearproducto();
void editarproducto();
void eliminarproducto();
void listadeproductos();
// Funciones Venta
void crearventa();
void editarventa();
void eliminarventa();
void listadeventa();
//Variables Globales
bool encontrado;
char auxuser[30];
float auxpro;
float auxve;
int auxid=0;
char mensaje[22]={'C','e','r','r','o',' ','s','e','s','i','o','n',' ','c','o','n',' ','e','x','i','t','o'};
int main (){
    //iniciarsesion();
    menu();
return 0;
}
void menu (){
int op;

    do{
        cout<<"Opcion Supermercado"<<endl;
        cout << endl;
        cout<<"1. Crear Usuario "<<endl;
        cout<<"2. Editar Usuario"<<endl;
        cout<<"3. Eliminar Usuario"<<endl;
        cout<<"4. Cerrar sesion "<<endl;
        cout<<"5. Lista de usuarios"<<endl;
        cout<<"6. Crear producto"<<endl;
        cout<<"7. Editar producto"<<endl;
        cout<<"8. Eliminar producto"<<endl;
        cout<<"9. Lista de productos"<<endl;
        cout<<"10. Crear venta"<<endl;
        cout<<"11. Editar venta"<<endl;
        cout<<"12. Eliminar venta"<<endl;
        cout<<"13. Lista de ventas"<<endl;
        cout << endl;
        cout << "Ingrese un numero: ";
        cin>>op;
        cin.ignore();
    }
  while(op<=0 || op>=15);
    switch (op){
        case 1: crearusuario();
        break;
        case 2: editarusuario();
        break;
        case 3: eliminarusuario();
        break;
        case 4: cerrarsesion();
        break;
        case 5: listadeusuarios();
        break;
        case 6: crearproducto();
        break;
        case 7: editarproducto();
        break;
        case 8: eliminarproducto();
        break;
        case 9: listadeproductos();
        break;
        case 10: crearventa();
        break;
        case 11: editarventa();
        break;
        case 12: eliminarventa();
        break;
        case 13: listadeventa();
        break;
        default: cout<<"No es una opción valida"<<endl;
            menu();
  }
  menu();
}
//Fin de la funcion menu
void crearusuario(){
    int adm, cli;
    string adp;
    string cont;
    ofstream usuarios;
    ifstream consulta;
    bool repetido=false;
    usuarios.open("Usuarios.txt",ios::out|ios::app);//Abrir archivo
    consulta.open("Usuarios.txt",ios::in);//Leer archivo
    if (usuarios.is_open()&&consulta.is_open()){
        cout << "Ingrese su id" << endl;
        cin>>auxid;
        consulta>>id;
        while(!consulta.eof()){
            consulta>>nombre;
            consulta>>usern;
            consulta>>password;
            consulta>>fechacreacion;
            consulta>>tipodeusuario;
            if (id==auxid){
                cout << "Ya existe este usuario" << endl;
                repetido=true;
                break;
            }
            consulta>>id;
        }
        if (repetido==false){

               usuarios << "Identificacion: " << auxid<< endl;
               cout << "Ingrese su nombre" << endl;
               cin.getline(nombre,50);cin.ignore();
               usuarios << "Nombre:" << nombre << endl;
               usuarios << "Nombre de usuario: " << auxuser << endl;
               cout << "Ingrese su clave" << endl;
               cin.getline(password,30);cin.ignore();
               usuarios << "Contraseña: " << password << endl;
               cout << "Ingrese su fecha" << endl;
               cin.getline(fechacreacion,30);cin.ignore();
               usuarios << "Fecha: " << fechacreacion << endl;
               cout << "Ingrese su tipo de usuario 1.Administrador 2.Cliente" << endl;
               cin>>(tipodeusuario);cin.ignore();
               if ((tipodeusuario)==1){
                    cout << "Ingrese el usuario del administrador principal" << endl;
                    cin>>adp;
                    cout << "Ingrese la contrasena del administador principal" << endl;
                    cin>>cont;
                    if((adp==US) && (cont==PASS)){
                        cout << "Administrador" << endl;
                        usuarios << tipodeusuario << endl;
                        usuarios << "Tipo de usuario: Administrador" << endl << endl;
                        adm++;
                    }else {
                        cout << "Usuario Incorrecto" << endl;
                    }
               }else {
                cout << "Cliente" << endl;
                usuarios << tipodeusuario << endl;
                usuarios << "Tipo de usuario: Cliente" << endl << endl;
                cli++;
                }

        }
    }else{
        cout<<"Error, el Archivo No se Pudo Abrir o No ha sido Creado"<<endl;
    }
    usuarios.close();//Cerrar archivo
    consulta.close();//Cerrar archivo
    cin.ignore();
    menu();
}
//Fin de la funcion Crear Usuario
void editarusuario(){
    ofstream editar;
    ifstream leer;
    int auxid=0;
    encontrado= false;
    char auxuser[30];
    char auxname[50];
    editar.open("Editar.txt",ios::out|ios::app);//Abrir achivo
    leer.open("Usuarios.txt",ios::in);//leer archivo
    if (editar.is_open() && leer.is_open()){
        cout << "Ingrese su usuario" << endl;
        cin>>auxid;
        leer>>id;
        while (!leer.eof()){
            leer>>usern;
            leer>>nombre;
            leer>>password;
            leer>>fechacreacion;
            leer>>tipodeusuario;

            if (id==auxid){
                encontrado=true;
                cout << "Identificacion: " << id << endl;
                cout << "Nombre: " << nombre << endl;
                cout << "Nombre del usuario: " << usern << endl;
                cout << "Contasena: " << password << endl;
                cout << "Fecha de creacion: " << fechacreacion << endl;
                cout << "Tipo de Usuario: " << tipodeusuario << endl;
                cout << "Ingrese el nuevo usuario con id  " << id << ": "<<endl;
                cin.getline(auxname,30);
                editar<<id<< endl;
                editar<<auxname<< endl;
                editar<<usern << endl;
                editar<<password<< endl;
                editar<<fechacreacion<<endl;
                editar<<tipodeusuario<< endl;
                cout << "Registro Modificado" << endl;
            } else {
                editar<<id;
                editar<<nombre;
                editar<<usern;
                editar<<password;
                editar<<fechacreacion;
                editar<<tipodeusuario;
            }
            leer >> id;
        }
    } else {
        cout << "No se puso crear el archivo" << endl;
    }
    if (encontrado=false){
        cout << "No se ha encontrado ningun registro" << endl;
    }
    editar.close();
    leer.close();
    remove("Usuarios.txt");//Cerrar archivo
    rename ("Editar.txt","Usuarios.txt");//Cerrar archivo
}
//Fin de la funcion Editar Usuario
void eliminarusuario(){
    ofstream editar;
    ifstream leer;
    encontrado=false;
    char auxuser[30];
    editar.open("Editar.txt",ios::out);//Arbrir archivo
    leer.open("Usuarios.txt",ios::in);//Leer archivo
    if (editar.is_open()&&leer.is_open()){
        cout << "Ingrese el usuario que desea eliminar" << endl;
        cin>>auxid;
        leer>>id;
        while(!leer.eof()){
            leer>>nombre;
            leer>>usern;
            leer>>password;
            leer>>fechacreacion;
            leer>>tipodeusuario;
            if (auxid==id){
                encontrado=true;
                cout << "Registro eliminado" << endl;
            } else {
                editar<<id;
                editar<<nombre;
                editar<<usern;
                editar<<password;
                editar<<fechacreacion;
                editar<<tipodeusuario;
            }
            leer>>id;
        }
    } else {
        cout << "El archivo contiene errores" << endl;
    }
    if (encontrado=false){
        cout << "No se encontro ningun resgistro" << endl;
    }
    editar.close();//Cerrar archivo
    leer.close();//Cerrar archivo
    remove("Usuarios.txt");//Elimar Archivo
    rename ("Editar.txt","Usuarios.txt");//Renombrar archivo
}
//Fin de la funcion Elinimar Usuario
void cerrarsesion(){
    int i=0;
    for (i=0;i<22;i++){
        cout << mensaje[i];
        Sleep(200);
    }
    exit(0);
}
//Fin de la funcion Cerrar Sesion
void listadeusuarios(){
    ifstream leer;
    leer.open ("Usuarios.txt",ios::out|ios::in);
            char lista[2000];
            if (leer.good()){
                while (!leer.eof()){
                    leer.getline(lista,2000);
                    cout << lista << endl;
                }
            }else{
                cout << "el archivo contiene errores"<<endl;
            }
    leer.close();//Cerrar archivo
}
//Fin de la funcion Lista Usuario
void crearproducto(){
    ofstream productos;
    ifstream consulta;
    float auxpro;
    bool repetido=false;
    productos.open("Productos.txt",ios::out|ios::app);//Abrir archivo
    consulta.open("Productos.txt",ios::in);//Leer archivo
    if (productos.is_open()&&consulta.is_open()){
        cout << "Ingrese el id del producto" << endl;
        cin>>auxpro;
        consulta>>idp;
        while (!consulta.eof()){
            consulta>>nombrep;
            if (idp==auxpro){
                cout << "Ya existe producto con esa id" << endl;
                repetido=true;
                break;
            }
        }
        if (repetido==false){
                cout << "Ingrese la identificacion del producto" << endl;
                cin>>idp;cin.ignore();
                productos << "Numero de identificacion del producto: " << idp << endl;
                cout << "Ingrese el nombre del producto" << endl;
                cin.getline(nombrep,30);
                productos << "Nombre del producto: " << nombrep << endl;
                cout << "Ingrese el valor del producto" << endl;
                cin>>valor;
                productos << "Valor del producto: " << valor << endl;
                cout << "Ingrese la fecha del producto" << endl;
                cin.getline(fechaproducto,30);cin.ignore();
                productos << "Fecha del producto: " << fechaproducto << endl;
                cout << "Ingrese el usuario que lo creo" << endl;
                cin.getline(usuariocreacion,30); cin.ignore();
                productos << "Usuario que creo el producto: " << usuariocreacion << endl << endl;

        } else {
            cout << "Error en el archivo" << endl;
        }
        }


productos.close();//Cerrar archivo
consulta.close();//Cerrar archivo
menu();
cin.ignore();
}
//Fin de la funcion Crear Producto
void editarproducto(){
    ofstream editarp;
    ifstream leerp;
    encontrado= false;
    float auxidp;
    char auxname[50];
    editarp.open("EditarProducto.txt",ios::out|ios::app);//Abrir archivo
    leerp.open("Productos.txt",ios::in);//Leer archivo

    if (editarp.is_open() && leerp.is_open()){
        cout << "Ingrese el id de la venta" << endl;
        cin>>auxidp;
        leerp>>idp;
        while (!leerp.eof()){
            leerp>>nombrep;
            leerp>>valor;
            leerp>>fechaproducto;
            leerp>>usuariocreacion;
            break;
            if (idp==auxidp){
                encontrado=true;
                cout << "Identificacion: " << idp << endl;
                cout << "Nombre del produto: " << nombrep << endl;
                cout << "valor: " << valor<< endl;
                cout << "Fecha de creacion: " << fechaproducto << endl;
                cout << "Nombre del usuario: " << usuariocreacion << endl;
                cout << "Ingrese el nuevo usuario con id  " << idp << ": "<<endl;
                cin.getline(auxname,50);
                editarp<<idp<< endl;
                editarp<<auxname<< endl;
                editarp<<valor << endl;
                editarp<<fechaproducto<< endl;
                editarp<<usuariocreacion<<endl;
                cout << "Registro Modificado" << endl;
            } else {
                editarp<<idp<< endl;
                editarp<<nombrep<< endl;
                editarp<<valor << endl;
                editarp<<fechaproducto<< endl;
                editarp<<usuariocreacion<<endl;
            }
            leerp >>idp;
        }
    } else {
        cout << "No se puso crear el archivo" << endl;
    }
    if (encontrado=false){
        cout << "No se ha encontrado ningun registro" << endl;
    }
    editarp.close();//Cerrar archivo
    leerp.close();//Cerrar archivo
    remove("Productos.txt");//Eliminar archivo
    rename ("EditarProducto.txt","Productos.txt");//Renombrar archivo
}
//Fin de la funcion Editar producto
void eliminarproducto(){
    ofstream editarp;
    ifstream leerp;
    encontrado= false;
    float auxidp;
    editarp.open("EditarProducto.txt",ios::out|ios::app);//Abrir archivo
    leerp.open("Productos.txt",ios::in);//Leer archivo
    if (editarp.is_open() && leerp.is_open()){
        cout << "Ingrese el id de la venta" << endl;
        cin>>auxidp;
        leerp>>idp;
        while (!leerp.eof()){
            leerp>>nombrep;
            leerp>>valor;
            leerp>>fechaproducto;
            leerp>>usuariocreacion;

            if (idp==auxidp){
                encontrado=true;
                cout << "Producto Eliminado" << endl;
            } else {
                editarp<<idp<< endl;
                editarp<<nombrep<< endl;
                editarp<<valor << endl;
                editarp<<fechaproducto<< endl;
                editarp<<usuariocreacion<<endl;
            }
            leerp >>idp;
        }
    } else {
        cout << "No se puso crear el archivo" << endl;
    }
    if (encontrado=false){
        cout << "No se ha encontrado ningun registro" << endl;
    }
    editarp.close();//Cerrar archivo
    leerp.close();//Cerrar archivo
    remove("Productos.txt");//Eliminar archivo
    rename ("EditarProducto.txt","Productos.txt");//Renombrar archivo
}
//Fin de la funcion eliminar producto
void listadeproductos(){
    ifstream leerp;
    leerp.open ("Productos.txt",ios::out|ios::in);//Leer archivo
    char listap[2000];
    if (leerp.good()){
            while (!leerp.eof()){
                leerp.getline(listap,2000);
                cout << listap << endl;
            }
    }else{
        cout << "el archivo contiene errores"<<endl;
    }
    leerp.close();//Cerrar archivo
}
//Fin de la funcion lista producto
void crearventa(){
    ofstream venta;
    ifstream consulta;
    bool repetido=false;
    venta.open("Venta.txt",ios::out|ios::app);//Abrir archivo
    consulta.open("Venta.txt",ios::in);//Leer archivo
    if (venta.is_open()&&consulta.is_open()){
        cout << "Ingrese el id del producto" << endl;
        cin>>auxve;
        consulta>>idv;
        while (!consulta.eof()){
            consulta>>productoventa;
            if (idv==auxve){
                cout << "Ya existe producto con esa id" << endl;
                repetido=true;
                break;
            }
        }
        if (repetido=false){
                cout << "Ingrese la identificacion de la venta" << endl;
                cin>>idv;cin.ignore();
                venta << "Nueva venta: " << idv << endl;
                cout << "Ingrese usuario que creo la venta" << endl;
                cin.getline(usuarioventa,30);
                venta << "Usuario que creo la venta: " << usuarioventa << endl;
                cout << "Ingrese el producto para la nueva venta" << endl;
                cin.getline(productoventa,30);
                venta << "Producto Sugerido: " << productoventa << endl;
                cout << "Ingrese su valor" << endl;
                cin>> valor;cin.ignore();
                venta << "Valor: " << valor << endl;
                cout << "Ingrese la fecha" << endl;
                cin.getline(fechaventa,30);
                venta << "Fecha: " << fechaventa << endl << endl;

        } else {
            cout << "Error en el archivo" << endl;
        }
    }

    venta.close();//Cerrar archivo
    consulta.close();//Cerrar archivo
    menu();
}
//Fin de la funcion crear venta
void editarventa(){
    ofstream editarv;
    ifstream leerv;
    encontrado= false;
    float auxidv;
    char auxname[50];
    editarv.open("EditarVenta.txt",ios::out|ios::app);//Abrir archivo
    leerv.open("Venta.txt",ios::in);//Leer archivo
    if (editarv.is_open() && leerv.is_open()){
        cout << "Ingrese el id de la venta" << endl;
        cin>>auxidv;
        leerv>>idv;
        while (!leerv.eof()){
            leerv>>usuarioventa;
            leerv>>productoventa;
            leerv>>valor;
            leerv>>fechaventa;
            if (idv==auxidv){
                encontrado=true;
                cout << "Identificacion: " << idv << endl;
                cout << "Nombre del usuario: " << usuarioventa << endl;
                cout << "Nombre del produto: " << productoventa << endl;
                cout << "valor: " << valor << endl;
                cout << "Fecha de creacion: " << fechaventa << endl;
                cout << "Ingrese el nuevo usuario con id  " << idv << ": "<<endl;
                cin.getline(auxname,50);
                editarv<<idv<< endl;
                editarv<<usuarioventa<< endl;
                editarv<<auxname << endl;
                editarv<<valor<< endl;
                editarv<<fechaventa<<endl;
                cout << "Registro Modificado" << endl;
            } else {
                editarv<<idv<< endl;
                editarv<<usuarioventa<< endl;
                editarv<<productoventa << endl;
                editarv<<valor<< endl;
                editarv<<fechaventa<<endl;
            }
            leerv >>idv;
        }
    } else {
        cout << "No se puso crear el archivo" << endl;
    }
    if (encontrado=false){
        cout << "No se ha encontrado ningun registro" << endl;
    }
    editarv.close();//Cerrar archivo
    leerv.close();//Cerrar archivo
    remove("Venta.txt");//Eliminar archivo
    rename ("EditarVenta.txt","Venta.txt");//Renombrar archivo
}
//Fin de la funcion editar venta
void eliminarventa(){
    ofstream editarv;
    ifstream leerv;
    encontrado= false;
    int auxtp;
    float auxidv;
    editarv.open("EditarVenta.txt",ios::out|ios::app);//Abrir archivo
    leerv.open("Venta.txt",ios::in);//Leer archivo
            if (editarv.is_open() && leerv.is_open()){
            cout << "Ingrese el id de la venta que desea eliminar" << endl;
            cin>>auxidv;
            leerv>>idv;
            while (!leerv.eof()){
                leerv>>usuarioventa;
                leerv>>productoventa;
                leerv>>valor;
                leerv>>fechaventa;

                if (idv==auxidv){
                    encontrado=true;
                    cout << "Venta Eliminada" << endl;
                } else {
                    editarv<<idv<< endl;
                    editarv<<usuarioventa<< endl;
                    editarv<<productoventa << endl;
                    editarv<<valor<< endl;
                    editarv<<fechaventa<<endl;
                }
                leerv >>idv;
            }
            } else {
                cout << "No se puso crear el archivo" << endl;
            }
            if (encontrado=false){
                cout << "No se ha encontrado ningun registro" << endl;
            }



editarv.close();//Cerrar archivo
leerv.close();//Cerrar archivo
remove("Venta.txt");//Eliminar archivo
rename ("EditarVenta.txt","Venta.txt");//Renombrar archivo
}
//Fin de la funcion eliminar venta
void listadeventa(){
    ifstream leerv;
    leerv.open ("Venta.txt",ios::out|ios::in);//Abrir archivo
    char listav[2000];
    if (leerv.good()){
            while (!leerv.eof()){
                leerv.getline(listav,2000);
                cout << listav << endl;
            }
    }else{
        cout << "el archivo contiene errores"<<endl;
    }
    leerv.close();//Cerrar archivo
}
//Fin de la funcion lista venta

