#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string.h>

using namespace std;

#include "funciones.h"

/**
Definición de funciones declaradas en funciones.h
*/


//SubMenu jugar correspondiente a opción 1 (Jugar):
void subMenuJugar(int puntosHistorial[], string nombresHistorial[]){
    setlocale(LC_ALL, "Spanish");
    char mjuego;
    bool regresar;
    char nombre[50];
    char nombreJugador2[50];
    regresar=false;


            while (!regresar){
                system("cls");
                cout << "                    A JUGAR                    "<< endl;
                cout << "-----------------------------------------------"<< endl;
                cout <<endl;
                 cout <<"  1. Un jugador" << endl;
                 cout <<"  2. Dos jugadores" << endl;
                 cout <<"  3. Demostración" << endl;
                 cout <<"  4. Volver a menú anterior"<< endl;
                 cout <<endl;
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
                        jugarSolo(nombre, puntosHistorial, nombresHistorial);
                     }
                        break;
                     case '2':{ //cout<<"Sin desarrollar"<<endl;
                       system("cls");
                       registraJugadores(nombre, nombreJugador2);
                       system("cls");
                       cout<<"Empieza el juego!"<<endl;
                       cout <<"Bienvenidos: "<<nombre<<endl<<nombreJugador2<<endl;
                       juegoDeDos(nombre, nombreJugador2, puntosHistorial, nombresHistorial);
                     }
                        break;
                     case '3':{
                        system("cls");
                        registrarJugador(nombre);
                        system("cls");
                        cout<<"Empieza el juego!"<< endl;
                        cout <<"Bienvenido: "<< nombre<<endl;
                        jugarDemostracion(nombre, puntosHistorial, nombresHistorial);
                     }
                        break;
                     case '4':{
                         regresar=true;
                         system("cls");
                     }
                        break;
                      default:system("cls");
                            cout << "                    A JUGAR                    "<< endl;
                            cout << "-----------------------------------------------"<< endl;
                            cout <<"Opcíon ingresada no es válida"<< endl;
                            cout <<endl;
                        break;

                     }
             }

}

//Registra nombre de jugador
void registrarJugador(char n[]){
    cout << "                    A JUGAR                    "<< endl;
    cout << "-----------------------------------------------"<< endl;
    cout<< endl;
    cout<<"Ingrese nombre de jugador para registrarse: ";
    cin>>n;
}

//Registra nombre de jugadores
void registraJugadores(char n[], char j[]){
     cout << "                    A JUGAR                    "<< endl;
    cout << "-----------------------------------------------"<< endl;
    cout<< endl;
    cout<<"Ingrese nombre de jugador 1: ";
    cin>>n;
    cout<<"Ingrese nombre de jugador 2: ";
    cin>>j;
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
    while (cant>=7){
    cout<<"Cantidad  ingresada no es válida. Ingrese numero del 1 al 5:";
    cin>>cant;
    }
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
    int uno, dos, tres, cuatro, cinco, seis;

    copiarVector(v, vCopia);
    ordenarDados(vCopia);

    if (vCopia[0]==vCopia[1] && vCopia[1]==vCopia[2] && vCopia[2]==vCopia[3] && vCopia[3]==vCopia[4]){ //GENERALA
        puntos=50;
        cout<<endl<<"Se obtuvo: GENERALA"<<endl;
    }
    else{
        if ((vCopia[0]==vCopia[1] && vCopia[1]==vCopia[2] && vCopia[2]==vCopia[3]) || (vCopia[1]==vCopia[2] && vCopia[2]==vCopia[3] && vCopia[3]==vCopia[4])){ //POKER
            puntos=40;
            cout<<endl<<"Se obtuvo: POKER"<<endl;
        }
        else{
            if (((vCopia[0]==vCopia[1] && vCopia[1]==vCopia[2]) && (vCopia[3]==vCopia[4])) || ((vCopia[2]==vCopia[3] && vCopia[3]==vCopia[4]) && (vCopia[0]==vCopia[1]))){ //FULL
                puntos=30;
                cout<<endl<<"Se obtuvo: FULL"<<endl;
            }
            else{
                if (v[0]==(v[1]-1) && v[1]==(v[2]-1) && v[2]==(v[3]-1) && v[3]==(v[4]-1)){ //ESCALERA
                    puntos=25;
                    cout<<endl<<"Se obtuvo: ESCALERA"<<endl;
                }
                else{
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

/// Juega GENERALA para un solo jugador.
void jugarSolo(char n[], int puntosHistorial[], string nombresHistorial[]){
    int vDado1[5], cantidadDados, puntos, x,cantDadosCambiados, lanzamiento, puntosLanzamiento;
    char esNumero[50];
    bool bandGeneral=true;
    int bandGeneralaDoble=0;
    char sn;
    puntos=0;
    for (x=0; x<10 && bandGeneral;x++){
        bool band=true;//Primer ingreso de dados
        calcularRonda(n, x+1, puntos);
        system("cls");

        for (lanzamiento=2; lanzamiento>0 && band==true;lanzamiento--){//Entra en un FOR para empezar tomar en cuenta los lanzamientos. 3 permitidos max, empieza en 2 porque el primero es aleatorio y es al principio.
            puntosLanzamiento=0;
            informacionRonda(n,x+1,puntos,lanzamiento);
            if (lanzamiento==2){
                tirarDados(vDado1);
                puntosLanzamiento=calculoDePuntaje(vDado1); //Calculamos aca si saca generala en el primer lanzamiento aleatorio.
                system("cls");
                if (puntosLanzamiento==50){
                cout<<endl<<"¡¡¡ GENERALA EN EL PRIMER LANZAMIENTO!!!"<<endl;
                cout<<endl<<"¡FELICITACIONES! GANASTE EL PARTIDO"<<endl;
                mostrarDados(vDado1);
                bandGeneral=false;
                band=false;
                }else{
                informacionRonda(n,x+1,puntos,lanzamiento);
                }
            } if (bandGeneral){
            cout <<endl<<"Dados de "<<n<<":"<<endl;
            mostrarDados(vDado1);
            cout<<endl<<"¿Desde volver a tirar algun dado? S/N: ";
            cin>> sn;
            }
               while(sn!='s'&&sn!='S'&&sn!='n'&&sn!='N'&&bandGeneral==true){ //Valida que entre si ingresan un caracter diferenteo y si no se hizo generala todavía.
                cout<<"Opción ingresada no es válida. Ingrese 'S' o 'N': ";
                cin>>sn;
            }
            if (sn=='s' || sn=='S'){
                cout<<"¿Cuantos dados desea volver a tirar?: ";
                cin>>esNumero;
                cantDadosCambiados=atoi(esNumero);
                while(cantDadosCambiados==0||cantDadosCambiados=='0'){
                cout<<"Cantidad invalída. Ingrese numeros del 1 al 5: ";
                cin>>esNumero;
                cantDadosCambiados=atoi(esNumero);
                }
                modificarDados(vDado1, cantDadosCambiados);
                 if (lanzamiento==1){                                    //Si decide agotar todos los lanzamientos y valida que esta en el ultimo, calcula el puntaje del cambio de dados.
                    puntosLanzamiento=calculoDePuntaje(vDado1);
                }
                system("cls");
            }
            else{
                if(sn=='n' || sn=='N'){
                    lanzamiento=-1;
                    band=false;
                     puntosLanzamiento=calculoDePuntaje(vDado1);
                }
            }

            if (puntosLanzamiento==50 && bandGeneral==true){

               if (bandGeneralaDoble==0){
                     cout<<endl<<"   ¡EXCELENTE! "<<endl;
                    bandGeneralaDoble=1;
                    band=false;
               }
                else {
                    bandGeneralaDoble=2;
                    cout<<endl<<"¡¡¡ GENERALA DOBLE !!!"<<endl;
                    cout<<endl<<"¡FELICITACIONES! GANASTE EL PARTIDO "<<endl;
                    bandGeneral=false;
                    band=false;
                }
            }
        }
        puntos+=puntosLanzamiento;
        lanzamientoEnCero(lanzamiento, band, bandGeneralaDoble, n, x+1, puntos, vDado1);
        cout<<"PUNTOS DE LA RONDA: "<<puntosLanzamiento<<endl;
        system("pause");
    }
    finDelJuegoUno(puntos, x, n);
    cargarHistorial(puntosHistorial, nombresHistorial, puntos, n);//Envia los datos del jugador para poder cargarlos en el historial
}
// Cuenta cuantos caracteres hay en un vector de char
int contarCaracteres(char v[]){
    for (int x=0;x<50; x++){
        if (v[x]=='\0'){
            return(x+1);
        }
    }
}


//Se ingresa un texto mas el nombre del juegador y lo centra dentro de la pantalla.
void centrarNombre(char texto[], char n[]){
    int cantCar1, cantCar2, div, tot;

    cantCar1=contarCaracteres(n);
    cantCar2=contarCaracteres(texto);

    tot=(53-cantCar1-cantCar2);
    div=tot/2;
    if (tot%2==0){
        cout<<"*";

    }
    else{
        cout<<"* ";
    }
    for (int x=0; x<=div; x++){
        cout<<" ";
    }
    cout<<texto<<n;
    for (int x=0; x<=div; x++){
        cout<<" ";
    }
    cout<<"*"<<endl;
}

//Se ingresa un texto, un numero (puntaje) y otro texto y los centra dentro de la pantalla.
void centrarPuntaje(char texto1[],int num, char texto2[]){
    int cantTe1,cantTe2,cantTe3,cantNum, div, tot;

    cantTe1=contarCaracteres(texto1);
    cantTe2=contarCaracteres(texto2);
    if (num<10){
        cantNum=1;
    }
    else{
        if (num<100){
            cantNum=2;
        }
        else{
            cantNum=3;
        }
    }

    tot=(53-cantTe1-cantNum-cantTe2);
    div=tot/2;
    if (tot%2==0){
        cout<<"*";
    }
    else{
        cout<<"* ";
    }
    for (int x=0; x<=div; x++){
        cout<<" ";
    }
    cout<<texto1<<num<<texto2;
    for (int x=0; x<=div; x++){
        cout<<" ";
    }
    cout<<"*"<<endl;
}

//Recibe nombre del jugador, el numero de ronda, y el puntaje. Lo muestra siempre que se termina un turno.
void calcularRonda(char n[], int r, int p){
    system("cls");
    cout<<"*******************************************************"<<endl;
    cout<<"*                    Ronda N°"<<r<<"                        *"<<endl;
    centrarNombre("Proximo turno: ", n);
    centrarPuntaje("Puntaje: ", p, " puntos");
    cout<<"*******************************************************"<<endl;
    system("pause");
}

//Una vez finalizado el juego de uno nos muestra en pantalla la cantidad de rondas, el nombre del ganador y el puntaje.
void finDelJuegoUno(int puntos, int ronda, char n[]){
    system("cls");
    cout<<"*******************************************************"<<endl;
    cout<<"*                    FIN DEL JUEGO                    *"<<endl;
    centrarPuntaje("Rondas: N°",ronda,"");//Sirve tambien para centrarlo, dado que el tercer parametro lo pasamos "vacio" y no suma caracteres
    centrarNombre("Ganador: ", n);
    centrarPuntaje("Puntaje ganador: ",puntos," puntos. ");
    cout<<"*******************************************************"<<endl;
    system("pause");
}

//Calcula ronda para 2 jugadores
void calcularRondaconDos(char n[], char j[], int r, int p, int pDos, bool t){
    system("cls");
    cout<<"*******************************************************"<<endl;
    cout<<"*                    Ronda N°"<<r<<"                        *"<<endl;
    cout<<"*                                                     *"<<endl;
    centrarNombre("Jugador: ", n);
    centrarPuntaje("Puntaje: ", p, " puntos");
    cout<<"*                                                     *"<<endl;
    centrarNombre("Jugador: ", j);
    centrarPuntaje("Puntaje: ", pDos, " puntos");
    cout<<"*                                                     *"<<endl;
    if (t==true){
    centrarNombre("Proximo turno: ", n);
    cout<<"*******************************************************"<<endl;
    system("pause");
    }else {
    centrarNombre("Proximo turno: ", j);
    cout<<"*******************************************************"<<endl;
    system("pause");
    }
}
///FUNCIONES SOLAMENTE UTILIZADAS PARA MODO "DEMOSTRACION"


// Juega GENERALA para DEMOSTRACION.
void jugarDemostracion(char n[], int puntosHistorial[], string nombresHistorial[]){
    int vDado1[5], cantidadDados, numeroDado, puntos, x, cantDadosCambiados, lanzamiento, puntosLanzamiento;
    char esNumero[50];
    bool bandGeneral=true;
    int bandGeneralaDoble=0;
    char sn;
    puntos=0;
    for (x=0; x<10 && bandGeneral;x++){
        bool band=true;//Primer ingreso de dados
        calcularRonda(n, x+1, puntos);
        system("cls");
        for (lanzamiento=3; lanzamiento>0 && band==true;lanzamiento--){//Entra en un FOR para empezar tomar en cuenta los lanzamientos. 3 permitidos max
            puntosLanzamiento=0;
            if (lanzamiento==3){//Si es el primer lanzamiento, evalua que salga o no generala.
                informacionRonda(n,x+1,puntos,lanzamiento);
                tirarDadosManual(vDado1);//Tiro los dados
                puntosLanzamiento=calculoDePuntaje(vDado1);
                system("cls");//LImpio la pantalla
                if(puntosLanzamiento==50){ // Si saca generala, gana el partido directamente
                cout<<endl<<"¡¡¡ GENERALA EN PRIMER RONDA !!!"<<endl;
                cout<<endl<<"¡FELICITACIONES! GANASTE EL PARTIDO "<<endl;
                mostrarDados(vDado1);
                bandGeneral=false;
                band=false;
            }
            lanzamiento--;
            }
            if (bandGeneral){ //Si en el primer lanzamiento no saca generala, sigo teniendo opción de tirar.
            informacionRonda(n,x+1,puntos,lanzamiento);//Muestro los dados que obtuve en el primer lanzamiento y muestro lanzamiento-1 para la pantalla.
            cout <<endl<<"Dados de: "<<n<<":"<<endl;
            mostrarDados(vDado1);
            cout<<endl<<"¿Desde volver a tirar algun dado? S/N: ";
            cin>> sn;
            }
            while(sn!='s'&&sn!='S'&&sn!='n'&&sn!='N'&&bandGeneral==true){ //Valida que entre si ingresan un caracter diferenteo y si no se hizo generala todavía.
                cout<<"Opción ingresada no es válida. Ingrese 'S' o 'N': ";
                cin>>sn;
            }
            if (sn=='s' || sn=='S'){
                cout<<"¿Cuantos dados desea volver a tirar?: ";
                cin>>esNumero;
                cantDadosCambiados=atoi(esNumero);
                while(cantDadosCambiados==0){
                cout<<"Cantidad invalída. Ingrese numeros del 1 al 5: ";
                cin>>esNumero;
                cantDadosCambiados=atoi(esNumero);              //Valida que sea un numero ingresado
                }
                modificarDadosManual(vDado1, cantDadosCambiados);
                if (lanzamiento==1){                                    //Si decide agotar todos los lanzamientos y valida que esta en el ultimo, calcula el puntaje del cambio de dados.
                    puntosLanzamiento=calculoDePuntaje(vDado1);
                }
                system("cls");
            }
            else{
                if(sn=='n' || sn=='N'){
                    lanzamiento=-1;//Se me ocurrio este negativo, lo podemos modificar igual pero es para que no se pise con la pantalla que muestra cuando el lanzamiento es 0.
                    band=false;
                    puntosLanzamiento=calculoDePuntaje(vDado1); //Lo cambie de lugar asi solo muestra el calculo cuando no se quiere tirar mas los dados.
                }
            }
              if(puntosLanzamiento==50 && bandGeneral==true){ // Si se obtiene Generala en un turno diferente al primero se le avisa al jugador para que lo tenga en cuenta.
                if(bandGeneralaDoble==0) {
                    cout<<endl<<" ¡EXCELENTE! "<<endl;
                    bandGeneralaDoble=1;    //Se suma 1 a la bandera de generala para saber que en caso de repetirse, no entra en este ciclo y gana directo por generala doble.
                    band=false;             //Se termina el turno, se alcanza la maxima puntuación
                }
                else{
                    bandGeneralaDoble=2;    //Bandera para que, en caso de sacar generala en lanzamiento en el ultimo lanzamiento, termine el juego.
                    cout<<endl<<"¡¡¡ GENERALA DOBLE !!! "<<endl; //Si saca generala por segunda vez, entra en else y termina el juego!.
                    cout<<endl<<" ¡FELICITACIONES! GANASTE EL PARTIDO "<<endl;
                    bandGeneral=false;
                    band=false;
                    }
              }
        }
        puntos+=puntosLanzamiento;//Esto es para que despues del ultimo lanzamiento (Ya fuera del for de lanzamiento) vuelva a mostrar la pantalla como la mostraba antes solo si usamos todos los lanzamientos y la bandera de band=true
        lanzamientoEnCero(lanzamiento, band,bandGeneralaDoble, n, x+1, puntos, vDado1);
        cout<<"PUNTOS DE LA RONDA: "<<puntosLanzamiento<<endl;
        system("pause");
    }
         finDelJuegoUno(puntos, x+1, n);
    cargarHistorial(puntosHistorial, nombresHistorial, puntos, n); //Envia los datos del jugador de mostracion para cargarlos en el historial de juego.

}

//Calcula ronda si se llega a lanzamiento=0
void lanzamientoEnCero(int lanzamiento, bool band,int generalaDoble, char n[], int x, int puntos, int vDado[]){
     if (lanzamiento==0 && band==true){
            system("cls");
            informacionRonda(n,x+1,puntos,lanzamiento);
            mostrarDados(vDado);
            calculoDePuntaje(vDado);
            cout<<endl;
        }
        else{
            if (lanzamiento==0 && band==false && generalaDoble==1){
           system("cls");
           informacionRonda(n,x+1,puntos,lanzamiento);
           mostrarDados(vDado);
           calculoDePuntaje(vDado);
           cout<<endl<<" ¡EXCELENTE!  "<<endl;
            }
            else if(lanzamiento==0 && band==false && generalaDoble==2){
            system("cls");
            informacionRonda(n,x+1,puntos,lanzamiento);
            mostrarDados(vDado);
            calculoDePuntaje(vDado);
            cout<<endl<<"¡¡¡ GENERALA DOBLE !!! "<<endl; //Si saca generala por segunda vez, entra en else y termina el juego!.
            cout<<endl<<" ¡FELICITACIONES! GANASTE EL PARTIDO "<<endl;
            }
        }

}

//Valida que el ingreso de un numero pueda corresponder a un dado. (Utiliza recursividad)
int validarValorDado(int num){
    if (num>0 && num<7){
        return num;
    }
    else{
        cout<<"¡Ingreso un valor no correspondido para un dado!"<<endl;
        cout<<"Por favor vuelva a ingresar un valor: ";
        cin>>num;
        validarValorDado(num);
    }
    return(num);
}

//Carga un vector de 5 posiciones manualmente.
void tirarDadosManual(int v[]){
    int i, valor;
    char esNumero[50];
    for (i=0; i<5; i++){
        cout << "Ingrese el valor del dado nro "<<i+1<<" : ";
        cin>>esNumero;                  //Valida que sea un numero el ingresado
        valor=atoi(esNumero);
        while (valor==0){
        cout<<"No se admiten caracteres, ingrese el valor del dado correspondiente: ";
        cin>>esNumero;
        valor=atoi(esNumero);
        }
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
cout<<"Jugador: "<<n<<" | "<<"Ronda n° "<<r<<" | "<<"Puntaje total: "<<p<< endl;
        cout<<"---------------------------------------------------------------------"<<endl;
        if (l==1){
            cout<<"Lanzamientos restantes: "<<l<<" | "<<"¡Ultimo lanzamiento!"<<endl;
        }
        else{
            if (l==0){
                cout<<"Lanzamientos restantes: "<<l<<" | "<<"¡Ya no quedan lanzamientos!"<<endl;
            }
            else{
                cout<<"Lanzamientos restantes: "<<l<<endl;
            }
        }
        cout<<"---------------------------------------------------------------------"<<endl;
}


//Gana Jugador
void ganaJugadorPorPuntos(char nGan[],int puntosGan, char nSeg[],int puntosSeg, int ronda){
            cout<<"*******************************************************"<<endl;
            cout<<"*                    FIN DEL JUEGO                    *"<<endl;
            centrarPuntaje("Rondas jugadas: ",ronda,"");
            cout<<"*                                                     *"<<endl;
            cout<<"*                       GANADOR                       *"<<endl;
            centrarNombre("Jugador: ", nGan);
            centrarPuntaje("Puntaje : ",puntosGan," puntos. ");
            cout<<"*                                                     *"<<endl;
            cout<<"*                    SEGUNDO PUESTO                   *"<<endl;
            centrarNombre("Jugador: ", nSeg);
            centrarPuntaje("Puntaje : ",puntosSeg," puntos. ");
            cout<<"*******************************************************"<<endl;
            system("pause");
}

//Empatan jugadores por puntos
void empatanPorPuntos(int puntos, int puntosJDOS, int ronda, char n[], char j[]){
        cout<<"*******************************************************"<<endl;
        cout<<"*                    FIN DEL JUEGO                    *"<<endl;
        centrarPuntaje("Rondas jugadas: ", ronda, "");
        cout<<"*                                                     *"<<endl;
        centrarNombre("Jugador 1:  ", n);
        centrarNombre("Jugador 2: ", j);
        cout<<"*                                                     *"<<endl;
        cout<<"*                    ¡E M P A T E!                    *"<<endl;
        cout<<"*                                                     *"<<endl;
        centrarPuntaje("Puntos obtenidos para ambos jugadores: ",puntos," puntos. ");
        cout<<"*******************************************************"<<endl;
        system("pause");
}

//Gana jugador por Generala
void ganaJugadorPorGenerala(char n[],int ronda, int puntos){
            cout<<"*******************************************************"<<endl;
            cout<<"*                    FIN DEL JUEGO                    *"<<endl;
            centrarPuntaje("Rondas jugadas: ", ronda, "");
            centrarNombre("Ganador: ", n);
            centrarPuntaje("Puntaje ganador: ",puntos," puntos. ");
            cout<<"*                   ¡GANO POR GENERALA!               *"<<endl;
            cout<<"*******************************************************"<<endl;
            system("pause");
}

//Empatan por generala
void empatanPorGenerala(int puntos, int puntosJDOS, int ronda, char n[], char j[]){
        cout<<"*******************************************************"<<endl;
        cout<<"*                   FIN DEL JUEGO                     *"<<endl;
        centrarPuntaje("Rondas jugadas: ", ronda, "");
        centrarNombre("Jugador 1:  ", n);
        centrarNombre("Jugador 2: ", j);
        cout<<"*                      ¡EMPATE!                       *"<<endl;
        cout<<"* GENERALA SERVIDA PARA AMBOS JUGADORES.  ¡Increible! *"<<endl;
        //centrarPuntaje("Puntos obtenidos para ambos jugadores: ",puntos," puntos. ");//Falta desarrollar, por ahi en vez de los puntos ponemos directamente el mensaje de generala o ambos.
        cout<<"*******************************************************"<<endl;
        system("pause");
}

///Juego de 2 jugadores
void juegoDeDos(char n[], char j[], int puntosHistorial[], string nombresHistorial[]){
  int vDado1[5], cantidadDados, puntos, x, cantDadosCambiados, lanzamiento, puntosLanzamiento, puntosJugadorDos;
  char esNumero[50];
  int bandGeneral=0; //Cambio el booleano por valores. Asi le doy chance al jugador 2 de sacar generala aunque sea imposible.
  int bandGeneralDobleUno=0; //Bandera para Generala doble jugador 1
  int bandGeneralDobleDos=0; //Bandera para Generala doble jugador 2
  char sn;
  puntos=0;
  puntosJugadorDos=0;
    for(x=0; x<10 && bandGeneral==0;x++){//Empieza las rondas. Ambos jugadores comparten ronda. Si band general es 0, nadie saco generala servida y siguen las rondas.
    bool band=true; //Primer ingreso de dados para jugador 1
    int turnoJugador=true;
    calcularRondaconDos(n, j, x+1, puntos, puntosJugadorDos, turnoJugador);
    system("cls");
        for (lanzamiento=2; lanzamiento>0 && band==true; lanzamiento--){//Jugador 1
        puntosLanzamiento=0;
        informacionRonda(n, x+1, puntos, lanzamiento);
            if (lanzamiento==2){
                tirarDados(vDado1);
                puntosLanzamiento=calculoDePuntaje(vDado1);
             system("cls");
             if(puntosLanzamiento==50){
                cout<<endl<<" ¡¡¡ GENERALA EN EL PRIMER LANZAMIENTO !!!"<<endl;
                cout<<j<<" esta obligado a sacar Generala en su primer lanzamiento"<<endl;
                mostrarDados(vDado1);
                bandGeneral=1;
                band=false;
             }else{
             informacionRonda(n,x+1,puntos,lanzamiento);
             }
            }if (bandGeneral==0){
                cout<<endl<<"Dados de "<<n<<":"<<endl;
                mostrarDados(vDado1);
                cout<<endl<<"¿Desea volver a tirar algun dado? S/N: ";
                cin>> sn;
            }
               while(sn!='s'&&sn!='S'&&sn!='n'&&sn!='N'&&bandGeneral==0){ //Valida que entre si ingresan un caracter diferenteo y si no se hizo generala todavía.
                cout<<"Opción ingresada no es válida. Ingrese 'S' o 'N': ";
                cin>>sn;
            }
                if (sn == 's' || sn=='S'){
                    cout<<"¿Cuantos dados desea volver a tirar?: ";
                    cin>>esNumero;
                    cantDadosCambiados=atoi(esNumero);
                     while(cantDadosCambiados==0||cantDadosCambiados=='0'){
                        cout<<"Cantidad invalída. Ingrese numeros del 1 al 5: ";
                        cin>>esNumero;
                        cantDadosCambiados=atoi(esNumero);
                    }
                    modificarDados(vDado1, cantDadosCambiados);
                    if (lanzamiento==1){ //Si decide agotar todos los lanzamientos y valida que esta en el ultimo, calcula el puntaje del cambio de dados.
                    puntosLanzamiento=calculoDePuntaje(vDado1);
                    }
                    system("cls");
                }
                else{
                    if (sn=='n' || sn=='N'){
                        lanzamiento=-1;
                        band=false;
                        puntosLanzamiento=calculoDePuntaje(vDado1);
                        }
                    }
            if (puntosLanzamiento==50 && bandGeneral==0){
                if (bandGeneralDobleUno==0){
                        cout<<endl<<"¡¡¡ EXCELENTE !!!"<<endl;
                        bandGeneralDobleUno=1;
                        band=false;
                }
                else {
                    bandGeneralDobleUno=2;
                    cout<<endl<<"¡¡¡ GENERALA DOBLE !!!"<<endl;
                    cout<<endl<<"!FELICITACIONES! GANASTE EL PARTIDO "<<endl;
                    bandGeneral=1;
                    band=false;
                    }

            }

        }
        puntos+=puntosLanzamiento;
        lanzamientoEnCero(lanzamiento, band, bandGeneralDobleUno, n, x+1, puntos, vDado1);
        cout<<"PUNTOS DEL TURNO: " <<puntosLanzamiento<<endl;
        system("pause");
        turnoJugador=false;//FIN DE JUGADOR 1
        calcularRondaconDos(n, j, x+1, puntos, puntosJugadorDos, turnoJugador);
        system("cls");
        band=true;//Resetamos, primer ingreso de dados para jugador 2
        for (lanzamiento=2; lanzamiento>0 && band==true; lanzamiento--){ //Jugador 2
            puntosLanzamiento=0;
            informacionRonda(j, x+1, puntosJugadorDos, lanzamiento);
            if (lanzamiento==2){
                 if (bandGeneral==1){
                    cout<<n<<" saco Generala servida, estas obligado a obtener la misma combinación para empatar."<<endl;
                    cout<<"Caso contrario, se pierde el juego"<<endl;
                    system("pause");
                    tirarDados(vDado1);
                    puntosLanzamiento=calculoDePuntaje(vDado1);
                    system("cls");
                    if(puntosLanzamiento==50){
                        mostrarDados(vDado1);
                        cout<<endl<<" ¡INCREIBLE! ¡GENERALA SERVIDA!"<<endl;
                        cout<<endl<<"EMPATAN"<<endl;
                        band=false;
                        bandGeneral=3;
                    }
                    else{
                        mostrarDados(vDado1);
                        cout<<endl<<"Perdiste el juego"<<endl;
                        band=false;
                    }
                }
                else{
                    tirarDados(vDado1);
                    puntosLanzamiento=calculoDePuntaje(vDado1);
                    system("cls");
                    if(puntosLanzamiento==50){
                        cout<<endl<<"¡¡¡ GENERALA EN EL PRIMER LANZAMIENTO!!!"<<endl;
                        cout<<endl<<"¡FELICITACIONES! GANASTE EL PARTIDO"<<endl;
                        mostrarDados(vDado1);
                        bandGeneral=2;
                        band=false;
                    }else
                    {
                        informacionRonda(j, x+1, puntos,lanzamiento);
                    }
                }

            }
            if (bandGeneral==0){
                cout<<endl<<"Dados de "<<j<<":"<<endl;
                mostrarDados(vDado1);
                cout<<endl<<"¿Desea volver a tirar algun dado? S/N: ";
                cin>> sn;
            }
            while(sn!='s'&&sn!='S'&&sn!='n'&&sn!='N'&&bandGeneral==0){ //Valida que entre si ingresan un caracter diferenteo y si no se hizo generala todavía.
                cout<<"Opción ingresada no es válida. Ingrese 'S' o 'N': ";
                cin>>sn;
            }
            if (sn == 's' || sn=='S'){
                    cout<<"¿Cuantos dados desea volver a tirar?: ";
                    cin>>esNumero;
                    cantDadosCambiados=atoi(esNumero);
                    while(cantDadosCambiados==0||cantDadosCambiados=='0'){
                        cout<<"Cantidad invalída. Ingrese numeros del 1 al 5: ";
                        cin>>esNumero;
                        cantDadosCambiados=atoi(esNumero);
                    }
                    modificarDados(vDado1, cantDadosCambiados);
                    if (lanzamiento==1){
                        puntosLanzamiento=calculoDePuntaje(vDado1);
                    }
                    system("cls");
            }
            else{
                if (sn=='n' || sn=='N'){
                        lanzamiento=-1;
                        band=false;
                        puntosLanzamiento=calculoDePuntaje(vDado1);
                }
            }
            if (puntosLanzamiento==50 && bandGeneral==0){ //Lo que no se es si que si saca Generala debería terminar el turno directamente, sin opción de volver a tirar. A esperar que el J2 saque generala sino gana.
                if (bandGeneralDobleDos==0){
                        cout<<endl<<"¡¡¡ EXCELENTE !!!"<<endl;
                        bandGeneralDobleDos=1;
                        band=false;
                }
                else{
                    bandGeneralDobleDos=2;
                    cout<<endl<<"¡¡¡ GENERALA DOBLE !!!"<<endl;
                    cout<<endl<<"!FELICITACIONES! GANASTE EL PARTIDO "<<endl;
                    bandGeneral=2;
                    band=false;
                }
            }
        }
        puntosJugadorDos+=puntosLanzamiento;
        //Esto es para que despues del ultimo lanzamiento (Ya fuera del for de lanzamiento) vuelva a mostrar la pantala como la mostraba antes.
        lanzamientoEnCero(lanzamiento, band, bandGeneralDobleDos, j, x+1, puntosJugadorDos,vDado1);
        cout<<"PUNTOS DEL TURNO: "<<puntosLanzamiento<<endl;
        system("pause");
    }
    cargarHistorial(puntosHistorial, nombresHistorial, puntos, n); //Envia los datos del jugador 1 al historial de juego
    cargarHistorial(puntosHistorial, nombresHistorial, puntosJugadorDos, j); //Envia los datos del jugador 2 al historial de juego
    finDelJuegoDos(puntos, puntosJugadorDos, x, n, j, bandGeneral);// Se envian los datos de a partida para calcular y mostrar el jugador ganador.
}

// Fin del juego para el modo de 2 jugadores
void finDelJuegoDos(int puntos, int puntosJDos, int ronda, char n[], char j[], int g){
    system("cls");
    if(g!=0){
        switch (g){
        case 1: ganaJugadorPorGenerala(n, ronda, puntos);
        break;

        case 2: ganaJugadorPorGenerala(j, ronda, puntosJDos);
        break;

        case 3: empatanPorGenerala(puntos, puntosJDos, ronda, n, j);
        break;
        }
    }
    else {
        if (puntos==puntosJDos) {
            empatanPorPuntos(puntos, puntosJDos, ronda, n, j);
        }
        else{//void ganaJugadorPorPuntos(char nGan[],int puntosGan, char nSeg[],int puntosSeg, int ronda, int puntos)
            if(puntos>puntosJDos){
                ganaJugadorPorPuntos(n, puntos, j, puntosJDos, ronda);
            }
            else{
                ganaJugadorPorPuntos(j, puntosJDos, n, puntos, ronda);
            }
        }
    }
}

//Recibe los datos a fin de cada jugada y los almacena de los vectores histirial
void cargarHistorial(int puntosHistorial[], string nombresHistorial[], int puntos, char nombre[]){
     int ind;
     ind=ultimaAsignacion(puntosHistorial);
     puntosHistorial[ind]=puntos;
     nombresHistorial[ind]=string(nombre);
}

//Inicializa todas las posiciones d eun vector en 0
void iniciliarVector(int v[]){
    for (int x=0;x<50;x++){
        v[x]=0;
    }
}

//Devuelve el indice de donde es el primer lugar del vector sin asignacion
int ultimaAsignacion(int v[]){
    for (int x=0;x<50;x++){
        if (v[x]==0){
            return(x);
        }
    }
}

void ordenarRanking(int puntosHistorial[], string nombresHistorial[]){
    int limite, posmin, auxInt;
    string auxString;
    limite= ultimaAsignacion(puntosHistorial);
    for(int i=0;i<limite;i++){
        for(int j=0;j<limite-1;j++){
            if(puntosHistorial[j]<puntosHistorial[i]) {
                auxInt=puntosHistorial[i];
                puntosHistorial[i]=puntosHistorial[j];
                puntosHistorial[j]=auxInt;
                auxString=nombresHistorial[i];
                nombresHistorial[i]=puntosHistorial[j];
                nombresHistorial[i]=auxString;
            }
        }
    }

}
void subMenuHistorial(int puntosHistorial[], string nombresHistorial[]){ // Se pasan como parametros las dos variables que contienen el historial de puntos y jugadores y nos imprime un ranking
    int limite;
    char n[50];
    limite=ultimaAsignacion(puntosHistorial);
    if (limite==0 && puntosHistorial[limite]==0){
        cout<<endl<<"¡No hay jugadores registrados!"<<endl<<"Empiece a jugar para armar un historial "<<endl<<endl;
        system("pause");
        system("cls");
    }
    else {
        ordenarRanking(puntosHistorial,nombresHistorial);
        cout<<"*******************************************************"<<endl;
        cout<<"*                RANKING DE JUGADORES                 *"<<endl;
        cout<<"*                                                     *"<<endl;
        for(int x=0; x<limite;x++){
            cout<<"*                                                     *"<<endl;
            strcpy(n, nombresHistorial[x].c_str());
            centrarNombre("Jugador: ", n);
            centrarPuntaje("Puntaje: ",puntosHistorial[x]," puntos.");
        }
        cout<<endl;
        cout<<"*******************************************************"<<endl;
        system("pause");
    }
}



///REGLAS Y COMBINACIONES


void menuReglas(){
system("cls");
cout<<"                              ¡Bienvenido a Generala!                             "<<endl<<endl;
cout<<"                                 Reglas generales            "<<endl<<endl;
cout<<" 1. El objetivo del juego es sacar Generala Servida, Generala doble u la mayor obtener la "<<endl;
cout<<"puntuación a lo largo de 10 rondas"<<endl<<endl;
cout<<" 2. Cada ronda esta compuesta por tres lanzamientos, cuando iniciamos una ronda se toma en cuenta"<<endl;
cout<<"que se realizo el primer lanzamiento"<<endl<<endl;
cout<<" 3. Un lanzamiento consiste en tirar los cinco dados y evaluar sus valores para determinar el puntaje. "<<endl;
cout<<"Si se considera oportuno se puede volver a tirar todos o algunos de los dados en dos oportunidades más"<<endl<<endl;
cout<<" 4. El sistema siempre preguntará al usuario si quiere realizar otro lanzamiento y cuales son los dados "<<endl;
cout<<"que quiere elegir para volver a tirar"<<endl<<endl;
cout<<" 5. Para calcular el sistema de puntaje, ir a 'Combinaciones ganadoras'"<<endl<<endl;
system("pause");
}

void menuCombinaciones(){
system("cls");
cout<<"                              ¡Bienvenido a Generala!                             "<<endl<<endl;
cout<<"                       Combinaciones para el calculo de puntaje                "<<endl;
cout<<endl;
cout<<" 1. GENERALA: Se obtienen 5 dados con el mismo valor. En caso de sacar generala en el "<<endl;
cout<<"primer lanzamiento de cualquier ronda, se gana el partido automaticamente. PUNTAJE: 50 puntos"<<endl;
cout<<" Nota: Si la combinación de dados se diera en el segundo o ultimo lanzamiento, se debe esperar"<<endl;
cout<<"a lograr la misma combinación en otra ronda mas para lograr Generala doble y ganar el partido"<<endl;
cout<<endl;
cout<<" 2. PÓKER: Se obtienen 4 dados con el mismo valor. PUNTAJE: 40 puntos."<<endl;
cout<<endl;
cout<<" 3. FULL: Se obtienen 3 dados con el mismo valor y 2 dados con el mismo valor. PUNTAJE: 30 puntos."<<endl;
cout<<endl;
cout<<" 4. ESCALERA: Se obtienen 5 dados enforma creciente. Puede empezar en el numero 1 o 2. PUNTAJE: 25 puntos."<<endl;
cout<<endl;
cout<<" 5. JUEGO DE NUMEROS: En caso de no obtener ninguna combinación antes mencionada, se tomará el "<<endl;
cout<<"puntaje del resultado de multiplicar la cantidad de dados con valor repetido por ese mismo valor."<<endl;
cout<<" Nota: Siempre que se de este resultado, se tomará el valor mas alto disponible. Si obtuve 3 dados "<<endl;
cout<<"con valor 1 y dos dados con valor 5 y 6 respectivamente, el juego tomará como valor para el "<<endl;
cout<<"calculo de punto el número 6"<<endl<<endl;
system("pause");
}

//Submenu reglas

void subMenuReglas(){
    char op;
    bool regresar=false;
    system("cls");

    while (!regresar){
        cout<<"                              ¡Bienvenido a Generala!                             "<<endl<<endl;
        cout<<"En esta sección te explicamos las reglas del juego y las combinaciones ganadoras: "<<endl;
        cout<<endl;
        cout<<"  1. Reglas del juego"<<endl;
        cout<<"  2. Combinaciones ganadoras"<<endl;
        cout<<"  3. Volver a menú principal"<<endl;
        cout<<endl;
        cout<<"Seleccione una opción: ";
        cin>>op;
        cout<<endl;
            switch(op){
            case '1': menuReglas();
                      system("cls");
            break;

            case '2': menuCombinaciones();
                      system("cls");
            break;

            case '3': regresar=true;
            break;

            default: cout<<"Opción ingresada no es válida, seleccione las indicadas"<<endl;
                     system("pause");
                     system("cls");
            break;
            }
     }
}


