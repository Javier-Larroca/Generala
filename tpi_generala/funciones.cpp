#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#include "funciones.h"

/**
Definición de funciones declaradas en funciones.h
*/


//SubMenu jugar correspondiente a opción 1 (Jugar):
void subMenuJugar(){
    setlocale(LC_ALL, "Spanish");
    char mjuego;
    bool regresar;
    char nombre[50];
    regresar=false;

             cout <<"A Jugar!" << endl;
             cout <<"-----------------------------"<< endl;
             while (!regresar){
                 cout <<"1. Un jugador" << endl;
                 cout <<"2. Dos jugadores" << endl;
                 cout <<"3. Demostración" << endl;
                 cout <<"4. Volver a menú anterior"<< endl;
                 cout <<"Seleccione Modo de juego: ";
                 cin >> mjuego;
                 cout <<endl;
                     switch(mjuego){
                     case '1':{
                         cout<<"Sin desarrollar"<<endl;

                     }
                        break;
                     case '2':cout<<"Sin desarrollar"<<endl;
                        break;
                     case '3':{
                        system("cls");
                        registrarJugador(nombre);
                        system("cls");
                        cout<<"Empieza el juego!"<< endl;
                        cout <<"Bienvenido: "<< nombre<<endl;
                        jugarDemostracion(nombre);
                     }
                        break;
                     case '4':{
                         regresar=true;
                         system("cls");
                     }
                        break;
                      default:system("cls");
                              cout <<"A Jugar!" << endl;
                              cout <<"-----------------------------"<< endl;
                              cout <<"Opcíon ingresada no es válida"<< endl;
                              cout <<endl;
                        break;

                     }
             }

}

//Registra nombre de jugador
    void registrarJugador(char n[]){
    cout <<"A Jugar!" << endl;
    cout <<"-----------------------------"<< endl;
    cout<<"Ingrese nombre de jugador para registrarse: ";
    cin >> n;
}

//Tira los dados ALEATORIAMENTE
void tirarDados(int v[]){
    int i;
    srand(time(NULL));
    for( i=0; i<5; i++ ){
        v[i]=(rand()%6)+1;
    }
}


//Muestra los dados.
void mostrarDados(int v[]){
    int i;
    cout<<endl<<"   1            2            3            4            5   ";
    cout<<endl<<"-------      -------      -------      -------      -------";
    cout<<endl<<"|     |      |     |      |     |      |     |      |     |";
    cout<<endl<<"|  "<<v[0]<<"  |      |  "<<v[1]<<"  |      |  "<<v[2]<<"  |      |  "<<v[3]<<"  |      |  "<<v[4]<<"  |";
    cout<<endl<<"|     |      |     |      |     |      |     |      |     |";
    cout<<endl<<"-------      -------      -------      -------      -------";
}

// Cambia los dados. Cambia los dados ALEATORIAMENTE
void cambiarUnDado(int v[], int pos){
    srand(time(NULL));
    v[pos-1]=(rand()%6)+1;
}

//Recibe nombre del jugador, el numero de ronda, y el puntaje. Lo muestra siempre que se termina un turno.
void calcularRonda(char n[], int r, int p){
    system("cls");
    cout<<"*******************************************************"<<endl;
    cout<<"*                    Ronda N°"<<r<<"                        *"<<endl;
    cout<<"*                 Proximo turno: "<<n<<"                *"<<endl;
    cout<<"*              Puntaje "<<n<<" : "<<p<<" puntos"<<"               *"<<endl;
    cout<<"*******************************************************"<<endl;
    system("pause");
}

///FUNCIONES SOLAMENTE UTILIZADAS PARA MODO "DEMOSTRACION"


// Juega GENERALA para DEMOSTRACION. VER SI SE PUEDE ACORTAR
void jugarDemostracion(char n[]){
    int vDado1[5], cantidadDados, numeroDado,ronda, puntos, x, cantDadosCambiados;
    char sn;
    ronda=1;
    puntos=0;
    for (x=0; x<10;x++){
        calcularRonda(n, ronda, puntos);
        system("cls");
        cout<<"Jugador: "<<n<<" | "<<"Turno de "<<n<<" | "<<"Ronda n° "<<ronda<<" | "<<"Puntaje total: "<<puntos<< endl;
        tirarDadosManual(vDado1);
        cout <<endl<<"Dados de "<<n<<":"<<endl;
        mostrarDados(vDado1);
        cout<<endl<<"¿Desde volver a tirar algun dado? S/N: ";
        cin>> sn;
        if (sn=='s' || sn=='S'){
            cout<<"¿Cuantos dados desea volver a tirar?: ";
            cin>>cantDadosCambiados;
            modificarDadosManual(vDado1, cantDadosCambiados);
        }
        ronda++;
        puntos+=20;
    }
}

//Valida que el ingreso d eun numero pueda corresponder a un dado. (Utiliza recursividad)
int validarValorDado(int num){
    if (num>0 && num<7){
        return num;
    }
    else{
        cout<<"Ingreso un valor no correspondido para un dado."<<endl<<"Por favor vuelva a ingresar un valor: ";
        cin>>num;
        validarValorDado(num);
    }
    return(num);
}

//Carga un vector de 5 posiciones manualmente.
void tirarDadosManual(int v[]){
    int i, valor;
    for (i=0; i<5; i++){
        cout << "Ingrese el valor del dado nro "<<i+1<<" : ";
        cin>>valor;
        v[i]=validarValorDado(valor);
    }
}

//Cambia el valor un dado en especifico determinado manualmente.
void cambiarUnDadoManual(int v[], int pos, int valor){
    v[pos-1]=validarValorDado(valor);
}

//Se ingresa la cantidad de dados a modificar.
void modificarDadosManual(int v[], int cant){
    int nroDado, valorDado;
    for (int x=0; x<=cant; x++);{
        cout<<"Ingrese el nro de dado a cambiar: ";
        cin>>nroDado;
        cout<<"Ingrese el valor por el cual dese cambiarlo: ";
        cin>>valorDado;
        cambiarUnDadoManual(v, nroDado, valorDado);
    }
}
