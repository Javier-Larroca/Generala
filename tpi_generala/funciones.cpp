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

//SubMenu jugar correspondiente a opción 1:
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
                 case '1':cout<<"Sin desarrollar"<<endl;
                    break;
                 case '2':cout<<"Sin desarrollar"<<endl;
                    break;
                 case '3':system("cls");
                          registrarJugador(nombre);
                          system("cls");
                          cout<<"Empieza el juego!"<< endl;
                          cout <<"Bienvenido: "<< nombre<<endl;
                          jugar(nombre);
                    break;
                 case '4': regresar=true;
                           system("cls");
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

// Juega GENERALA para DEMOSTRACION. VER SI SE PUEDE ACORTAR
void jugar(char n[]){
int vDado1[5], cantidadDados, numeroDado,ronda, puntos, x;
char sn;
ronda=1;
puntos=0;
for (x=0; x<10;x++){
calcularRonda(n, ronda, puntos);
system("cls");
cout<<"Jugador: "<<n<<" | "<<"Turno de "<<n<<" | "<<"Ronda n° "<<ronda<<" | "<<"Puntaje total: "<<puntos<< endl;
tirarDados(vDado1);
cout <<endl<<"Dados de "<<n<<":"<<endl;
mostrarDados(vDado1);
cout<<endl<<"¿Desde volver a tirar algun dado? S/N: ";
cin>> sn;
cambiarUnDado(vDado1, numeroDado);
ronda++;
puntos+=20;
}
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
