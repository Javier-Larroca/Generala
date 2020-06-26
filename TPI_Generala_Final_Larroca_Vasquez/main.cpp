#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>

using namespace std;

#include "funciones.h"

int main()
{
    setlocale(LC_ALL, "Spanish");
    system("color 0b");
    SetConsoleTitle("GENERALA - LARROCA - VASQUEZ");
    string nombresHistorial[50];
    int puntosHistorial[50];
    iniciliarVector(puntosHistorial);
    char opc;
        ///Pantalla de intro
        cout<<endl<<endl;
        cout<<"   ..%%%%...%%%%%%..%%..%%..%%%%%%..%%%%%....%%%%...%%.......%%%%.."<<endl;
        cout<<"   .%%......%%......%%%.%%..%%......%%..%%..%%..%%..%%......%%..%%."<<endl;
        cout<<"   .%%.%%%..%%%%....%%.%%%..%%%%....%%%%%...%%%%%%..%%......%%%%%%."<<endl;
        cout<<"   .%%..%%..%%......%%..%%..%%......%%..%%..%%..%%..%%......%%..%%."<<endl;
        cout<<"   ..%%%%...%%%%%%..%%..%%..%%%%%%..%%..%%..%%..%%..%%%%%%..%%..%%."<<endl;
        cout<<"   ................................................................"<<endl;
        cout<<endl<<endl;
        cout<<"                       ~ BINVENIDO AL JUEGO ~                      "<<endl;
        cout<<endl<<endl<<endl;
        cout<<"  Creado por los alumnos:"<<endl;
        cout<<"                            - LARROCA JAVIER"<<endl;
        cout<<"                            - VASQUEZ ELMER"<<endl;
        cout<<endl<<endl<<endl<<endl;
        cout<<"  LABORATORIO DE COMPUTACIÓN - 1C - 2020"<<endl<<endl<<endl<<endl;
    system("pause");
    while(true){
    system("cls");
    cout << "             Bienvenido a Generala             "<< endl;
    cout << "-----------------------------------------------"<< endl;
    cout <<endl;
    cout <<"  1. Jugar"<< endl;
    cout <<"  2. Historial"<< endl;
    cout <<"  3. Reglas"<< endl;
    cout <<"  4. Salir"<< endl;
    cout <<endl;
    cout <<"Seleccione una opción: ";
    cin >> opc;
    system("cls");

    switch (opc){
    case '1':subMenuJugar(puntosHistorial, nombresHistorial);
        break;
    case '2':subMenuHistorial(puntosHistorial, nombresHistorial);cout<<"Sin desarrollar"<<endl;
        break;
    case '3':subMenuReglas();
        break;
    case '4':cout<<"Gracias por jugar Generala, te esperamos pronto!"<< endl;
        return 0;
        break;
    default:system("cls");
            cout << "             Bienvenido a Generala             "<< endl;
            cout << "-----------------------------------------------"<< endl;
            cout <<"Opción ingresada no es válida"<< endl;
            cout<< endl;
        break;
    }
}

}
