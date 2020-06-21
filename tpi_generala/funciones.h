#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;

/// DECLARACIÓN/PROTOTIPO DE FUNCIONES

void tirarDados(int v[]); //Carga en un vector de 5 posiciones(dados) valores al azar del 1 al 6

void mostrarDados(int v[]); //Muestra el vector(dados) de 5 posiciones

void cambiarUnDado(int v[], int pos); //Cambia el valor de un dado en especifico (Se ingresa directamente el nro de dado cargado por el usuario)

/// DESARROLLO/ DEFINICIONES DE FUNCIONES

void tirarDados(int v[]){
    int i;
    srand(time(NULL));
    for( i=0; i<5; i++ ){
        v[i]=(rand()%6)+1;
    }
}

void mostrarDados(int v[]){
    int i;
    cout<<endl<<"   1            2            3            4            5   ";
    cout<<endl<<"-------      -------      -------      -------      -------";
    cout<<endl<<"|     |      |     |      |     |      |     |      |     |";
    cout<<endl<<"|  "<<v[0]<<"  |      |  "<<v[1]<<"  |      |  "<<v[2]<<"  |      |  "<<v[3]<<"  |      |  "<<v[4]<<"  |";
    cout<<endl<<"|     |      |     |      |     |      |     |      |     |";
    cout<<endl<<"-------      -------      -------      -------      -------";
}

void cambiarUnDado(int v[], int pos){
    srand(time(NULL));
    v[pos-1]=(rand()%6)+1;
}
