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
                         //cout<<"Sin desarrollar"<<endl;
                        system("cls");
                        registrarJugador(nombre);
                        system("cls");
                        cout<<"Empieza el juego!"<< endl;
                        cout <<"Bienvenido: "<< nombre<<endl;
                        jugarSolo(nombre);
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
    cout<<endl<<"   1            2            3            4            5   ";
    cout<<endl<<"-------      -------      -------      -------      -------";
    cout<<endl<<"|     |      |     |      |     |      |     |      |     |";
    cout<<endl<<"|  "<<v[0]<<"  |      |  "<<v[1]<<"  |      |  "<<v[2]<<"  |      |  "<<v[3]<<"  |      |  "<<v[4]<<"  |";
    cout<<endl<<"|     |      |     |      |     |      |     |      |     |";
    cout<<endl<<"-------      -------      -------      -------      -------";
    cout<<endl;
}

// Cambiar los dados. Cambia los dados ALEATORIAMENTE
void cambiarUnDado(int v[], int pos){
    srand(time(NULL));
    v[pos-1]=(rand()%6)+1;
}

//Se ingresa la cantidad de dados que se desean cambiar. Pide al usuario el nro de dado que quiere cambiar y lo cambia aleatoriamente.
void modificarDados(int v[], int cant){
    int nroDado;
    for (int x=0; x<cant; x++){
        cout<<"Ingrese el nro de dado a cambiar: ";
        cin>>nroDado;
        cambiarUnDado(v, nroDado);
    }
}

//Ordena el vector de dados de menor a mayor.
void ordenarDados(int v[]){
    int i,j, posmin, aux;
    for(i=0;i<5;i++){
        posmin=i;
        for(j=i+1;j<5;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

//Copia en otro vector el contenido del vector 1
int copiarVector(int v[], int v2[]){
    int i;
    for(i=0;i<5;i++){
        v2[i]=v[i];
    }
}

//Devuelve la cantidad de dados con el valor que se envia como parametro
int contarDadosRepetidos(int v[], int numero){
    int i, cant=0;
    for(i=0;i<5;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}

//Calcula que tipo de puntaje corresponde por jugada.
int calculoDePuntaje(int v[]){
    int vCopia[5], puntos;
    //bool bMayor=false;// Este bool lo uso en el for para buscar las combinaciones basicas.
    //int valorRepetido;// Valor para las combinaciones basicas
    //int puntosAprox;//Valor para calcular los puntos de cada numero
    //int puntoMayor;// Valor para comparar el punto mayor temporal
    int uno, dos, tres, cuatro, cinco, seis; //Vamos a ver si esto funciona
    copiarVector(v, vCopia);
    ordenarDados(vCopia);

    if (vCopia[0]==vCopia[1] && vCopia[1]==vCopia[2] && vCopia[2]==vCopia[3] && vCopia[3]==vCopia[4]){ //GENERALA
        puntos=50;
        cout<<endl<<"GENERALA"<<endl;
    }
    else{
        if ((vCopia[0]==vCopia[1] && vCopia[1]==vCopia[2] && vCopia[2]==vCopia[3]) || (vCopia[1]==vCopia[2] && vCopia[2]==vCopia[3] && vCopia[3]==vCopia[4])){ //POKER
            puntos=40;
            cout<<endl<<"POKER"<<endl;
        }
        else{
            if (((vCopia[0]==vCopia[1] && vCopia[1]==vCopia[2]) && (vCopia[3]==vCopia[4])) || ((vCopia[2]==vCopia[3] && vCopia[3]==vCopia[4]) && (vCopia[0]==vCopia[1]))){ //FULL
                puntos=30;
                cout<<endl<<"FULL"<<endl;
            }
            else{
                if (v[0]==(v[1]-1) && v[1]==(v[2]-1) && v[2]==(v[3]-1) && v[3]==(v[4]-1)){ //ESCALERA
                    puntos=25;
                    cout<<endl<<"Se obtuvo: ESCALERA"<<endl;
                }
                else{
                /*
                //Aca arme un for para buscar las combinaciones basicas. Lo explico punto a punto.
                for( int r=0; r<6; r++){ // Aca entrar en un FOR para buscar los numeros del 1 al 6.
                    valorRepetido=r+1; // Empezamos por el 1
                    int vecesRepite=0; // Para cada numero, repite 1 sola vez
                    for (int x=0; x<5; x++){ // Cada numero, recorre 1 vez el vector copia de los dados.
                        if(vCopia[x]==valorRepetido){ //Compara la posición del vector con el numero.
                            vecesRepite++; // Si repite aumenta en 1. Con aparecer 1 vez suma.
                            puntosAprox=vecesRepite*valorRepetido; //Calculo de los puntos aproximados
                        }
                    }
                    if (bMayor==false){ // Bandera para comparar con los numeros que le siguen
                        puntoMayor=puntosAprox;
                        bMayor=true;
                    }
                    else{
                        if(puntosAprox>puntoMayor){
                            puntoMayor=puntosAprox;
                        }
                    }
                }
                puntos=puntoMayor;// Si no lo dejaba aca, me traia numero basura.
                **/
                    //uno=dos=tres=cuatro=cinco=seis=0;
                    uno =contarDadosRepetidos(v, 1)*1;
                    dos =contarDadosRepetidos(v, 2)*2;
                    tres =contarDadosRepetidos(v, 3)*3;
                    cuatro =contarDadosRepetidos(v, 4)*4;
                    cinco =contarDadosRepetidos(v, 5)*5;
                    seis =contarDadosRepetidos(v, 6)*6;
                    if (seis>uno && seis>dos && seis>tres && seis>cuatro && seis>cinco){
                        puntos=seis;
                    }
                    else{
                        if (cinco>uno && cinco>dos && cinco>tres && cinco>cuatro){
                            puntos=cinco;
                        }
                        else{
                            if (cuatro>uno && cuatro>dos && cuatro>tres){
                                puntos=cuatro;
                            }
                            else{
                                if (tres>uno && tres>dos){
                                    puntos=tres;
                                }
                                else{
                                    if(dos>uno){
                                        puntos=dos;
                                    }
                                    else{
                                        puntos=uno;
                                    }
                                }
                            }
                        }
                    }
                    cout<<endl;
                }
            }
        }
    }
    return puntos;
}

// Juega GENERALA para un solo jugador.
void jugarSolo(char n[]){
    int vDado1[5], cantidadDados, numeroDado,ronda, puntos, x, cantDadosCambiados, lanzamiento, puntosLanzamiento;
    char sn;

    ronda=1;
    puntos=0;
    for (x=0; x<10;x++){
        bool primerIngreso=false;//Primer ingreso de dados
        calcularRonda(n, ronda, puntos);
        system("cls");
        for (lanzamiento=3; lanzamiento>0;lanzamiento--){//Entra en un FOR para empezar tomar en cuenta los lanzamientos. 3 permitidos max
         informacionRonda(n,ronda,puntos,lanzamiento);
        if (primerIngreso==false){
            tirarDados(vDado1);
            primerIngreso=true;
        }
        cout <<endl<<"Dados de "<<n<<":"<<endl;
        mostrarDados(vDado1);
        cout<<endl<<"¿Desde volver a tirar algun dado? S/N: ";
        cin>> sn;
        if (sn=='s' || sn=='S'){
            cout<<"¿Cuantos dados desea volver a tirar?: ";
            cin>>cantDadosCambiados;
            modificarDados(vDado1, cantDadosCambiados);
            system("cls");
        }
        else{
            if(sn=='n' || sn=='N'){
                lanzamiento=0;
            }
        }
        }
        puntosLanzamiento=calculoDePuntaje(vDado1);
        if (puntosLanzamiento==50 && ronda==1){
            cout<<endl<<"¡¡¡ GANASTE LOCURA !!!"<<endl;
        }
        puntos+=puntosLanzamiento;
        ronda++;
        cout<<"PUNTOS: "<<puntos<<endl;
        system("pause");
    }
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
    int vDado1[5], cantidadDados, numeroDado,ronda, puntos, x, cantDadosCambiados, lanzamiento, puntosLanzamiento;
    char sn;
    ronda=1;
    puntos=0;
    for (x=0; x<10;x++){
        bool primerIngreso=false;//Primer ingreso de dados
        calcularRonda(n, ronda, puntos);
        system("cls");
        for (lanzamiento=3; lanzamiento>0;lanzamiento--){//Entra en un FOR para empezar tomar en cuenta los lanzamientos. 3 permitidos max
         informacionRonda(n,ronda,puntos,lanzamiento);
        if (primerIngreso==false){
            tirarDadosManual(vDado1);
            primerIngreso=true;
        }
        cout <<endl<<"Dados de "<<n<<":"<<endl;
        mostrarDados(vDado1);
        cout<<endl<<"¿Desde volver a tirar algun dado? S/N: ";
        cin>> sn;
        if (sn=='s' || sn=='S'){
            cout<<"¿Cuantos dados desea volver a tirar?: ";
            cin>>cantDadosCambiados;
            modificarDadosManual(vDado1, cantDadosCambiados);
            system("cls");
        }
        else{
            if(sn=='n' || sn=='N'){
                lanzamiento=0;
            }
        }
        }
        puntosLanzamiento=calculoDePuntaje(vDado1);
        if (puntosLanzamiento==50 && ronda==1){
            cout<<endl<<"¡¡¡ GANASTE LOCURA !!!"<<endl;
        }
        puntos+=puntosLanzamiento;
        ronda++;
        cout<<"PUNTOS: "<<puntos<<endl;
        system("pause");
    }
}

//Valida que el ingreso de un numero pueda corresponder a un dado. (Utiliza recursividad)
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
    for (int x=0; x<cant; x++){
        cout<<"Ingrese el nro de dado a cambiar: ";
        cin>>nroDado;
        cout<<"Ingrese el valor por el cual dese cambiarlo: ";
        cin>>valorDado;
        cambiarUnDadoManual(v, nroDado, valorDado);
    }
}

//Encabezado para cada lanzamiento en cada ronda.
void informacionRonda(char n[],int r, int p, int l){
cout<<"Jugador: "<<n<<" | "<<"Turno de "<<n<<" | "<<"Ronda n° "<<r<<" | "<<"Puntaje total: "<<p<< endl;
        cout<<"---------------------------------------------------------------------"<<endl;
        if (l==1){
        cout<<"Lanzamientos restantes: "<<l<<" | "<<"¡Ultimo lanzamiento!"<<endl;
        }else{
        cout<<"Lanzamientos restantes: "<<l<<endl;
        cout<<"---------------------------------------------------------------------"<<endl;
        }

}
