/*
Michelle Aylin Calzada Montes
A01706202
En este proyecto decidi hacer una tienda, que va atener envíos nacionales, internacionales y a otros planetas
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>//Agarre esta librería para poner el comando "cls", que sirve para limpiar la pantalla

using namespace std;

//Esta es la clase Padre
class Tienda{
    private:
        float precio;
    public:
        Tienda(float _precio);
        float get_precio();
        float set_precio(float dinero);
};
//Constructor de la clase padre
Tienda::Tienda(float _precio){
    precio=_precio;
}
//Funcion para modificar el precio dependiendo del porcentaje extra de envio que se elija
float Tienda::set_precio(float dinero){
    precio=precio+precio*dinero;
    return precio;
}
//Funcion para optener el precio
float Tienda::get_precio(){
    return precio;
}

//Clase hedereda de Tienda, cuando el envio de los artículos es nacional y de donde se saca el primer Objeto
class Nacional: public Tienda{
    private:
        int lugar;
        float porcentaje_envio;
    public:
        Nacional(int _lugar, float _precio);
        float get_porcentaje();
};
//Constructor de la clase Nacional
Nacional::Nacional(int _lugar, float _precio): Tienda(_precio){
    lugar=_lugar;
    porcentaje_envio=.15;
}
//Se obtiene el porcentaje de envios nacionales
float Nacional::get_porcentaje(){
    return porcentaje_envio;
}

//Clase hedereda de Tienda, cuando el envio de los artículos es internacional y de donde se saca el segundo Objeto
class Internacional: public Tienda{
    private:
        int lugar;
        float porcentaje_envio;
    public:
        Internacional(int _lugar, float _precio);
        float get_porcentaje();
};
//Constructor de la clase internacional
Internacional::Internacional(int _lugar, float _precio): Tienda(_precio){
    lugar=_lugar;
    porcentaje_envio=.30;
}
//Se obtiene el porcentaje de envios internacionales
float Internacional::get_porcentaje(){
    return porcentaje_envio;
}

//Clase hedereda de Tienda, cuando el envio de los articulos es a otros planetas y de donde se saca el tercer Objeto
class Otro_planeta: public Tienda{
    private:
        int lugar;
        float porcentaje_envio;
    public:
        Otro_planeta(int _lugar, float precio);
        float get_porcentaje();
};
//Constructor de la clase Otro_planeta
Otro_planeta::Otro_planeta(int _lugar, float _precio): Tienda(_precio){
    lugar=_lugar;
    porcentaje_envio=.30;
}
//Se obtiene el porcentaje de envios a otros planetas
float Otro_planeta::get_porcentaje(){
    return porcentaje_envio;
}

//Muestra el menu de artículos en la tienda
void menu(){
    cout<<"Bienvenido a la tienda V A P O R W A V E~"<<endl;
    cout<<endl;
    cout<<"Nuestro inventario:"<<endl;
    cout<<"1) Disco de musica.............. 300 pesos"<<endl;
    cout<<"2) Sudadera..................... 800 pesos"<<endl;
    cout<<"3) Playera...................... 500 pesos"<<endl;
    cout<<"4) Pines........................ 60 pesos"<<endl;
    cout<<"5) Poster....................... 150 pesos"<<endl;
    cout<<endl;
}
//Muestra el menu de opciones de envío
void menu_enviar(){
    cout<<endl;
    cout<<"Envio:"<<endl;
    cout<<"1)Nacional........... 15% mas"<<endl;
    cout<<"2)Internacional...... 30% mas"<<endl;
    cout<<"3)A otro planeta..... 50% mas"<<endl;
    cout<<"Opcion (ponga numero): ";
    }

int main(){
    int opcion, enviar;
    float precio=0;

    //EL ciclo es para elegir varios articulos que quieras comprar hasta que presiones -1
    while(opcion!=-1){
        //Imprime el menu de articulos
        menu();
        //Imprime el total que se lleva hasta ese momento
        cout<<precio<<endl;
        cout<<"Seleccione articulos (numero de opcion, -1 para acabar):";
        cin>>opcion;
        //Se suma el precio total dependiendo del artículo que elijas
        switch(opcion){
            case 1:
                precio=precio+300;
                break;
            case 2:
                precio=precio+800;
                break;
            case 3:
                precio=precio+500;
                break;
            case 4:
                precio=precio+60;
                break;
            case 5:
                precio=precio+150;
                break;
            default:
                cout<<"\nLa opccion no existe";
                break;
        }
        //Es un comando que limpia la Consola
        system("cls");

}
    //Se imprime el menu de envio
    menu_enviar();
    cin>>enviar;

    //Dependiendo de la opcion que elijas, se te mostrara el resultado con el óbjeto indicado
    switch(enviar){
        case 1:
            {
            //Objeto 1
            Nacional compra_nacional(enviar, precio);
            //Le pone un nuevo precio sacando el porcentaje extra que se tiene qe poner
            compra_nacional.set_precio(compra_nacional.get_porcentaje());
            cout<<endl;
            //Imprime el nuevo precio
            cout<<"El precio total es "<<compra_nacional.get_precio()<<"\nGracias por su compra ^_^";

            //Casos de prueba:
            //Nacional prueba1(1, 544);
            //prueba1.set_precio(prueba1.get_porcentaje());
            //cout<<endl;
            //cout<<"El precio total es "<<prueba1.get_precio()<<"\nGracias por su compra ^_^";

            //Nacional prueba2(1, 544);
            //prueba2.set_precio(prueba2.get_porcentaje());
            //cout<<endl;
            //cout<<"El precio total es "<<prueba2.get_precio()<<"\nGracias por su compra ^_^";
            }
            break;
        case 2:
            {
            //Objeto 2
            Internacional compra_internacional(enviar, precio);
            //Le pone un nuevo precio sacando el porcentaje extra que se tiene qe poner
            compra_internacional.set_precio(compra_internacional.get_porcentaje());
            //Imprime el nuevo precio
            cout<<endl;
            cout<<"El precio total es "<<compra_internacional.get_precio()<<"\nGracias por su compra ^_^";

            //Casos de prueba:
            //Internacional prueba3(2, 876);
            //prueba3.set_precio(prueba3.get_porcentaje());
            //cout<<endl;
            //cout<<"El precio total es "<<prueba4.get_precio()<<"\nGracias por su compra ^_^";

            //Internacional prueba4(2, 8006);
            //prueba4.set_precio(prueba4.get_porcentaje());
            //cout<<endl;
            //cout<<"El precio total es "<<prueba4.get_precio()<<"\nGracias por su compra ^_^";
            }
            break;
        case 3:
            {
            //Objeto 3
            Otro_planeta compra_interplanetaria(enviar, precio);
            //Le pone un nuevo precio sacando el porcentaje extra que se tiene qe poner
            compra_interplanetaria.set_precio(compra_interplanetaria.get_porcentaje());
            //Imprime el nuevo precio
            cout<<endl;
            cout<<"El precio total es "<<compra_interplanetaria.get_precio()<<"\nGracias por su compra ^_^";

            //Casos de prueba:
            //Otro_planeta prueba5(3,3444);
            //prueba5.set_precio(prueba5.get_porcentaje());
            //cout<<endl;
            //cout<<"El precio total es "<<prueba5.get_precio()<<"\nGracias por su compra ^_^";

            //Otro_planeta prueba6(3,3480.4);
            //prueba6.set_precio(prueba6.get_porcentaje());
            //cout<<endl;
            //cout<<"El precio total es "<<prueba6.get_precio()<<"\nGracias por su compra ^_^";
            }
            break;
        default:
            cout<<"Opcion de envio no valida";
    }

}
