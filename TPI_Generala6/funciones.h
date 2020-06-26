#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
Declaración de funciones
*/
void iniciliarVector(int v[]);//Iniciliza el vector de puntajes con 0
int ultimaAsignacion(int v[]);//Se le envia el vector de puntajes y nos devuelve el indice del vector donde hacer la proxima asignacion
void ordenarRanking(int puntosHistorial[], string nombresHistorial[]);// Ordena de mayor a menor el ranking de jugadores.
void subMenuHistorial(int puntosHistorial[], string nombresHistorial[]); //Imprime en pantalla en forma decreciente los puntajes con sus respectivos jugadores.
void cargarHistorial(int puntosHistorial[], string nombresHistorial[], int puntos, char nombre[]);//Recibe los datos de cada partido y los almacena en los vectores de historial
void subMenuJugar(int puntosHistorial[], string nombresHistorial[]); //Muestra menú para jugador 1.
void jugarSolo(char n[], int puntosHistorial[], string nombresHistorial[]);
void juegoDeDos(char n[], char j[], int puntosHistorial[], string nombresHistorial[]);// Juego de 2
void jugarDemostracion(char n[], int puntosHistorial[], string nombresHistorial[]); //Juega en modo de "demostracion", recibe el nombre del jugador y aca se juega todo el turno.Se inician vectores y  llama a las funciones tirarDados, mostrarDados y cambiarDados
void iniciliarVector(int v[]); //Inicializa en 0 las posiciones de un vector de 50 posiciones.
void registrarJugador(char n[]); //Registra jugador que va a jugar
void calcularRonda(char n[], int r, int p);////Recibe nombre del jugador, el numero de ronda, y el puntaje. Lo muestra siempre que se termina un turno
void calcularRondaconDos(char n[], char j[], int r, int p, int pDos);
void informacionRonda(char n[], int r, int p, int l);//Encabezado para cada lanzamiento en cada ronda
void registraJugadores(char n[], char j[]);// Registra jugadores para juego de 2. Pense en unificarlo en una sola función para optimizar pero creo que sería lo mismo.
void ganaPorGenerala();//Si gana por generala, o los dos sacan generala servida en el primer intento. Empatan
void ganaPorPuntos();// Si gana por puntos, o los dos empatan. muestra empate
void finDelJuegoDos(int puntos, int puntosJDos, int ronda, char n[], char j[], int g);// Fin del juego para modo 2, si alguno gano por Generala lo muestra. Lo mismo que RegistraJugadores, pense en unificarlo en 1 sola funcion.
void lanzamientoEnCero(int lanzamiento, bool band,int generalaDoble, char[], int x, int puntos, int vDado[]);//Esta función, si se encuentran en la ultima ronda ayuda a que no se borre toda la pantalla.
void menuReglasJuego(); //MEnu reglas
void menuCombinaciones();//Menu combinaciones
void subMenuReglas();//Menu detallando reglas
//void opcionDeEmpatar(); //OpcionDeEmpatar para jugador 2

/**
Funciones Agus
*/
int contarCaracteres(char v[]);//Cuenta cuantos caracteres hay dentro de un vector de char.
void centrarPuntaje(char texto1[],int num, char texto2[]);// Patente pendiente
void centrarNombre(char texto[], char n[]); //Se ingresa un texto ("Jugador ", "Proximo turno:") y el nombre y nos lo imprime centrado
void finDelJuegoUno(int puntos, int ronda, char n[]);//Una vez finalizado el juego imprime una pantalla de "fin de juego"
int contarDadosRepetidos(int v[], int numero); //Cuenta cuantos dados hay con el valor que se envia como parametro
int copiarVector(int v[], int v2[]); //Copia el contenido de un vector de dados en otro vector (Ambos deben ser de 5 posiciones)
void ordenarDados(int v[]);//Ordena el vector de "dados" de menor a mayor.
int calculoDePuntaje(int v[]); //Calcula que tipo de puntaje corresponde por jugada.
int validarValorDado(int num); //Valida que un valor ingresado manualmente este entre 1 y 6.
void tirarDados(int v[]); //Carga en un vector de 5 posiciones(dados) valores al azar del 1 al 6
void tirarDadosManual(int v[]); //Carga manualmente un vector de 5 posiciones.
void mostrarDados(int v[]); //Muestra el vector(dados) de 5 posiciones
void cambiarUnDado(int v[], int pos); //Cambia el valor de un dado en especifico (Se ingresa directamente el nro de dado cargado por el usuario)
void modificarDadosManual(int v[], int cant); //Pide al usuario los dados y porque valores dese cambiarlos.
void modificarDados(int v[], int cant); //Pide al usuario que dados desea cambiar.
void cambiarUnDadoManual(int v[], int pos, int valor); //Cambiar el valor de un dado es especifico indicado por el usuario

#endif // FUNCIONES_H_INCLUDED
