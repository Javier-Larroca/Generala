#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>

using namespace std;

#include "funciones.h"

int main()
{
    setlocale(LC_ALL, "Spanish");
    char opc;
    char nombre[50];

    cout << "Bienvenido a Generala"<< endl;
    cout << "---------------------"<< endl;
    cout <<endl;

    while(true){
    //cout << endl;
    cout <<"1. Jugar"<< endl;
    cout <<"2. Historial"<< endl;
    cout <<"3. Reglas"<< endl;
    cout <<"4. Salir"<< endl;
    cout <<endl;
    cout <<"Seleccione una opción: ";
    cin >> opc;
    system("cls");

    switch (opc){
    case '1':subMenuJugar();
        break;
    case '2':cout<<"Sin desarrollar"<<endl;
        break;
    case '3':cout<<"Sin desarrollar"<<endl;
        break;
    case '4':cout<<"Gracias por jugar Generala, te esperamos pronto!"<< endl;
        return 0;
        break;
    default:system("cls");
            cout << "Bienvenido a Generala"<< endl;
            cout << "---------------------"<< endl;
            cout <<"Opción ingresada no es válida"<< endl;
            cout<< endl;
        break;
    }
}

}
