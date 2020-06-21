#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#include "funciones.h"

int main()
{
    int vec_dado1[5], cant_dados, nro_dado;
    char sn;

    tirarDados(vec_dado1);
    cout<<endl<<"Dados de jugador 1: "<<endl;
    mostrarDados(vec_dado1);
    cout<<endl<<"¿Desea volver a tirar algun dado? S/N ";
    cin>>sn;
    if (sn=='s'|| sn=='S'){
        cout<<"¿Cuantos dados quiere volver a tirar? ";
        cin>>cant_dados;
        for (int x=0; x<cant_dados; x++){
            cout<<"¿Que nro de dado desea tirar nuevamente? ";
            cin>>nro_dado;
            cambiarUnDado(vec_dado1, nro_dado);
        }
        mostrarDados(vec_dado1);
    }


}

