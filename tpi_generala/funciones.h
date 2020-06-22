#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
Declaración de funciones
*/

void subMenuJugar(); //Muestra menú para jugador 1.
void registrarJugador(char n[]); //Registra jugador que va a jugar
void jugar(char n[]); //Juega, recibe el nombre del jugador y aca se juega todo el turno.Se inician vectores y  llama a las funciones tirarDados, mostrarDados y cambiarDados
int calcularPuntos();// calcula los puntos que le corresponden
void calcularRonda(char n[], int r, int p);////Recibe nombre del jugador, el numero de ronda, y el puntaje. Lo muestra siempre que se termina un turno
void ingresarDados();// Ingresar dados para DEMOSTRACIÓN.
void cambiarDadosManualmente();// Cambia los dados para DEMOSTRACIÓN


/**
Funciones Agus
*/

void tirarDados(int v[]); //Carga en un vector de 5 posiciones(dados) valores al azar del 1 al 6
void mostrarDados(int v[]); //Muestra el vector(dados) de 5 posiciones
void cambiarUnDado(int v[], int pos); //Cambia el valor de un dado en especifico (Se ingresa directamente el nro de dado cargado por el usuario)




#endif // FUNCIONES_H_INCLUDED
