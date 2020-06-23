#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
Declaraci�n de funciones
*/

void subMenuJugar(); //Muestra men� para jugador 1.
void registrarJugador(char n[]); //Registra jugador que va a jugar
void jugarDemostracion(char n[]); //Juega en modo de "demostracion", recibe el nombre del jugador y aca se juega todo el turno.Se inician vectores y  llama a las funciones tirarDados, mostrarDados y cambiarDados
//int calcularPuntos();// calcula los puntos que le corresponden
void calcularRonda(char n[], int r, int p);////Recibe nombre del jugador, el numero de ronda, y el puntaje. Lo muestra siempre que se termina un turno
void ingresarDados();// Ingresar dados para DEMOSTRACI�N.
void cambiarDadosManualmente();// Cambia los dados para DEMOSTRACI�N
void informacionRonda(char n[], int r, int p, int l);//Encabezado para cada lanzamiento en cada ronda

/**
Funciones Agus
*/
int copiarVector(int v[], int v2[]);
void ordenarDados(int v[]);//Ordena el vector de "dados" de menor a mayor.
int calculoDePuntaje(int v[]); //Calcula que tipo de puntaje corresponde por jugada.
int validarValorDado(int num); //Valida que un valor ingresado manualmente este entre 1 y 6.
void tirarDados(int v[]); //Carga en un vector de 5 posiciones(dados) valores al azar del 1 al 6
void tirarDadosManual(int v[]); //Carga manualmente un vector de 5 posiciones.
void mostrarDados(int v[]); //Muestra el vector(dados) de 5 posiciones
void cambiarUnDado(int v[], int pos); //Cambia el valor de un dado en especifico (Se ingresa directamente el nro de dado cargado por el usuario)
void modificarDadosManual(int v[], int cant); //Pide al usuario los dados y porque valores dese cambiarlos.
void cambiarUnDadoManual(int v[], int pos, int valor); //Cambiar el valor de un dado es especifico indicado por el usuario

#endif // FUNCIONES_H_INCLUDED