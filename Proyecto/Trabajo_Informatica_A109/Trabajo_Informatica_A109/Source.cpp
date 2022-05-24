#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include "SerialClass/SerialClass.h"

#define MAX_BUFFER 200
#define PAUSA_MS 200

// Funciones Menu
int menu(void);
int menu_mover(void);
int menu_luces(void);
int menu_abrir_cerrar(void);

//Funciones Sensores
void verifica_sensores(Serial*,char*);

void monitorizar_sensor_distancia(Serial*);
void monitorizar_sensor_ilum(Serial*);
void monitorizar_sensor_temperatura(Serial*);

void comprobar_mensajes(Serial*);

float leer_sensor_distancia(Serial*);
float leer_sensor_ilum(Serial*);
float leer_sensor_temperatura(Serial*);

int Enviar_y_Recibir(Serial* ,const char* , char* ); 
float float_from_cadena(char* cadena);


/*//Funciones para guardar ficheros
#define MAX 20
void guardar_en_disco(int v[], float* temp);
int leer_desde_disco(int v[]);
*/





int main(void)
{
	Serial* Arduino;
	char puerto[] = "COM6"; // Puerto serie al que está conectado Arduino
	int opcion_menu;

	setlocale(LC_ALL, "es-ES");
	Arduino = new Serial((char*)puerto);
	do
	{
		comprobar_mensajes(Arduino);
		opcion_menu = menu();
		switch (opcion_menu)
		{
		case 0:
			break;

		case 1: 
			system("cls");
			int control_mover;
			do
			{
				control_mover = menu_mover();
				switch (control_mover)
				{
				case 0:
					break;
				case 'w':
				{
					system("cls");
					//monotorizar_motor
					printf("////Moviendo coche recto////\n\n");
					break;
				}
				case 'a':
				{
					system("cls");
					printf("////Moviendo coche izquierda////\n\n");

					break;
				}
				case 'd':
				{system("cls");
					printf("////Moviendo coche derecha/////\n\n");

					break;
				}
				default:system("cls");
					printf("Opción incorrecta de movimiento\n");
					break;
				}
			} while (control_mover != 'e');
			break;

		case 2:
		{
			system("cls");
			monitorizar_sensor_temperatura(Arduino);
			break;
		}

		case 3:
		{
			system("cls");
			monitorizar_sensor_distancia(Arduino);
			break;
		}

		case 4:
			system("cls");
			int opcion_luces;
			do {
				opcion_luces = menu_luces();
				switch (opcion_luces)
				{
				case 0:
					break;
				case 1:
				{
					system("cls");
					monitorizar_sensor_ilum(Arduino);
					break;
				}
				case 2:
				{
					system("cls");
					int s;
					printf("2. Encendiendo luces de corto alcance\n");
					scanf_s("%d", &s);
					break;
					//Se encenderán los leds con poca intensidad
				}
				case 3:
				{
					system("cls");
					int s;
					printf("3. Encendiendo luces automaticas\n\n");
					scanf_s("%d", &s);
					break;
					//Se encenderán los leds con una intensidad que depende de la luz que detecte el sensor de luz
				}
				default:
					printf("Opción incorrecta\n");
					break;
				}
				system("cls");
			} while (opcion_luces != 4);

			break;


		case 5:
		{
			system("cls");
			int opcion_abrir_cerrar = menu_abrir_cerrar();
			do {
		
				switch (opcion_abrir_cerrar)
				{
				case 0:
					break;
				case 1:
				{system("cls");
					printf("1. El coche esta abierto\n");
					break;
					//Se desbloqueará la puerta
				}
				case 2:
				{system("cls");
					printf("2. El coche esta cerrado\n");
					break;
					//Se cerrará el coche
				}
				default:
					system("cls");
					break;
				}
			} while (opcion_abrir_cerrar != 3);
			
		break;
		}
		case 6:
			system("cls");
			printf("\nSalida del programa\n\n");;
			break;

		default: 
			system("cls");
			break;
		}
		
	} while (opcion_menu != 6);
	return 0;
}






// ***************************************************************************************
// Las funciones menú se limitan a mostrar en pantalla las ofertas de opciones disponibles
// ***************************************************************************************
int menu(void)
{
	static int opcion = -1;

	if (opcion != 0)
	{
		printf("\n");
		printf("MENU PRINCIPAL:\n");
		printf("Seleccione una opción:\n\n");
		printf("1. Movilidad del coche\n");
		printf("2. Temperatura del coche\n");
		printf("3. Distancia a la que estan los objetos del coche\n");
		printf("4. Las luces del coche\n");
		printf("5. Abrir o cerrar puertas del coche.\n");
		printf("6. Salir de la aplicación.\n");
		printf("Opción:");
	}
	if (_kbhit())
	{
		opcion = (int)_getch() - '0';
		printf("%d\n", opcion);
	}
	else
		opcion = 0;
	return opcion;
}

int menu_mover()
{


	static char opcion = -1;

	if (opcion != 0)
	{
		printf("\n");
		printf("Seleccione una opción:\n\n");
		printf("W. Mover para alante\n");
		printf("A. Mover hacia la izquierda\n");
		printf("D. Mover hacia la derecha\n\n");
		printf("////Selecciones E para salir/////\n");
		printf("Opción:");
	}
	if (_kbhit())
	{
		opcion = (char)_getch();
		printf("%d\n", opcion);
	}
	else
		opcion = 0;
	return opcion;
}

int menu_luces(void)
{
	static int opcion_luces = -1;

	if (opcion_luces != 0)
	{
		printf("\n");
		printf("¿Que luces quieres encender?\n");
		printf("1. Valores de la luz\n");
		printf("2. Encender luces\n");
		printf("3. Apagar luces\n");
		printf("4. Salir\n");
		printf("Opción:");
	}
	if (_kbhit())
	{
		opcion_luces = (int)_getch() - '0';
		printf("%d\n", opcion_luces);
	}
	else
		opcion_luces = 0;
	return opcion_luces;
}

int menu_abrir_cerrar(void)
{
	static int opcion_abr = -1;

	if (opcion_abr != 0)
	{
		printf("\n");
		printf("¿Quieres abrir o cerrar coche?\n");
		printf("1. Abrir coche\n");
		printf("2. Cerrar coche\n");
		printf("3. Salir\n");
		printf("Opción:");
	}
	if (_kbhit())
	{
		opcion_abr = (int)_getch() - '0';
		printf("%d\n", opcion_abr);
	}
	else
		opcion_abr = 0;
	return opcion_abr;
}




void comprobar_mensajes(Serial* Arduino)
{
	int bytesRecibidos, total = 0;
	char mensaje_recibido[MAX_BUFFER];

	bytesRecibidos = Arduino->ReadData(mensaje_recibido, sizeof(char) * MAX_BUFFER - 1);
	while (bytesRecibidos > 0)
	{
		Sleep(PAUSA_MS);
		total += bytesRecibidos;
		bytesRecibidos = Arduino->ReadData(mensaje_recibido + total, sizeof(char) * MAX_BUFFER - 1);
	}
	if (total > 0)
	{
		mensaje_recibido[total-1] = '\0';
		printf("\nMensaje recibido: %s\n", mensaje_recibido);
	}
}

void monitorizar_sensor_distancia(Serial* Arduino)
{
	float frecuencia, distancia;
	char tecla;
	do
	{
		printf("Establezca frecuencia de muestreo (0,5 Hz - 2,0 Hz):");
		scanf_s("%f", &frecuencia);
	} while (frecuencia < 0.5 || frecuencia>2.0);

	printf("Pulse una tecla para finalizar la monitorización\n");
	do
	{
		if (Arduino->IsConnected())
		{
			distancia = leer_sensor_distancia(Arduino);
			if (distancia != -1)
				printf("%.2f ", distancia);
			else
				printf("XXX ");
		}
		else
			printf("\nNo se ha podido conectar con Arduino.\n");
		if ((1 / frecuencia) * 1000 > PAUSA_MS)
		  Sleep((1 / frecuencia) * 1000 - PAUSA_MS);
	} while (_kbhit() == 0);
	tecla = _getch();
	return;
}

void monitorizar_sensor_ilum(Serial* Arduino)
{
	float frecuencia, ilum;
	char tecla;
	do
	{
		printf("Establezca frecuencia de muestreo (0,5 Hz - 2,0 Hz):");
		scanf_s("%f", &frecuencia);
	} while (frecuencia < 0.5 || frecuencia>2.0);

	printf("Pulse una tecla para finalizar la monitorización\n");
	do
	{
		if (Arduino->IsConnected())
		{
			ilum = leer_sensor_ilum(Arduino);
			if (ilum != -1)
				printf("%.2f ", ilum);
			else
				printf("XXX ");
		}
		else
			printf("\nNo se ha podido conectar con Arduino.\n");
		if ((1 / frecuencia) * 1000 > PAUSA_MS)
			Sleep((1 / frecuencia) * 1000 - PAUSA_MS);
	} while (_kbhit() == 0);
	tecla = _getch();
	return;
}

void monitorizar_sensor_temperatura(Serial* Arduino)
{
	float frecuencia, temperatura;
	char tecla;
	do
	{
		printf("Establezca frecuencia de muestreo (0,5 Hz - 2,0 Hz):");
		scanf_s("%f", &frecuencia);
	} while (frecuencia < 0.5 || frecuencia>2.0);

	printf("Pulse una tecla para finalizar la monitorización\n");
	do
	{
		if (Arduino->IsConnected())
		{
			temperatura = leer_sensor_temperatura(Arduino);
			if (temperatura != -1)
				printf("%.2f ", temperatura);
			else
				printf("XXX ");
		}
		else
			printf("\nNo se ha podido conectar con Arduino.\n");
		if ((1 / frecuencia) * 1000 > PAUSA_MS)
			Sleep((1 / frecuencia) * 1000 - PAUSA_MS);
	} while (_kbhit() == 0);
	tecla = _getch();
	return;
}

void verifica_sensores(Serial* Arduino,char* port)
{
	float distancia;

	if (Arduino->IsConnected())
	{
		distancia = leer_sensor_distancia(Arduino);
		if (distancia!=-1)
		  printf("\nDistancia: %f\n", distancia);
	}
	else
	{
		printf("\nNo se ha podido conectar con Arduino.\n");
		printf("Revise la conexión, el puerto %s y desactive el monitor serie del IDE de Arduino.\n",port);
	}
}

float leer_sensor_distancia(Serial* Arduino)
{
	float distancia;
	int bytesRecibidos;
	char mensaje_recibido[MAX_BUFFER];
	
	bytesRecibidos = Enviar_y_Recibir(Arduino, "GET_DISTANCIA\n", mensaje_recibido);

	if (bytesRecibidos <= 0)
		distancia = -1;
	else
		distancia = float_from_cadena(mensaje_recibido);
	return distancia;
}

float leer_sensor_ilum(Serial* Arduino)
{
	float ilum;
	int bytesRecibidos;
	char mensaje_recibido[MAX_BUFFER];

	bytesRecibidos = Enviar_y_Recibir(Arduino, "GET_ILUM\n", mensaje_recibido);

	if (bytesRecibidos <= 0)
		ilum = -1;
	else
		ilum = float_from_cadena(mensaje_recibido);
	return ilum;
}

float leer_sensor_temperatura(Serial* Arduino)
{
	float temperatura;
	int bytesRecibidos;
	char mensaje_recibido[MAX_BUFFER];

	bytesRecibidos = Enviar_y_Recibir(Arduino, "GET_TEMPERATURA\n", mensaje_recibido);

	if (bytesRecibidos <= 0)
		temperatura = -1;
	else
		temperatura = float_from_cadena(mensaje_recibido);
	return temperatura;
}

int Enviar_y_Recibir(Serial* Arduino, const char* mensaje_enviar, char* mensaje_recibir)
{
	int bytes_recibidos=0,total=0;
	int intentos = 0,fin_linea=0;


	Arduino->WriteData((char *)mensaje_enviar,strlen(mensaje_enviar));
	Sleep(PAUSA_MS);

	bytes_recibidos = Arduino->ReadData(mensaje_recibir,sizeof(char)*MAX_BUFFER-1);

	while ((bytes_recibidos > 0 || intentos < 5) && fin_linea==0)
	{
		if (bytes_recibidos > 0)
		{
			total += bytes_recibidos;
			if (mensaje_recibir[total - 1] == 13 || mensaje_recibir[total - 1] == 10)
				fin_linea = 1;
		}
		else
			intentos++;
		Sleep(PAUSA_MS);
		bytes_recibidos = Arduino->ReadData(mensaje_recibir+total, sizeof(char) * MAX_BUFFER - 1);
	}
	if (total > 0)
		mensaje_recibir[total - 1] = '\0';

	//printf("LOG: %d bytes -> %s\nIntentos=%d - EOLN=%d\n", total, mensaje_recibir,intentos,fin_linea);
	return total;
}

float float_from_cadena(char* cadena)
{
	float numero = 0;
	int i, divisor = 10, estado = 0;


	for (i=0;cadena[i]!='\0' && estado!=3 && i<MAX_BUFFER;i++)
		switch (estado)
		{
		case 0:// Antes del número
			if (cadena[i] >= '0' && cadena[i] <= '9')
			{
				numero = cadena[i] - '0';
				estado = 1;
			}
			break;
		case 1:// Durante el número
			if (cadena[i] >= '0' && cadena[i] <= '9')
				numero = numero * 10 + cadena[i] - '0';
			else
				if (cadena[i] == '.' || cadena[i] == ',')
					estado = 2;
				else
					estado = 3;
			break;
		case 2: // Parte decimal
			if (cadena[i] >= '0' && cadena[i] <= '9')
			{
				numero = numero + (float)(cadena[i] - '0') / divisor;
				divisor *= 10;
			}
			else
				estado = 3;
			break;
		}
	return numero;
}





/*
int leer_desde_disco(int v[])
{
	FILE* fichero;
	errno_t e;
	int total = 0, temperatura;

	e = fopen_s(&fichero, "Temperaturas.txt", "rt");
	if (fichero == NULL)
		printf("Error: No se ha podido abrir el fichero\n");
	else
	{
		fscanf_s(fichero, "%d", &temperatura);
		while (!feof(fichero))
		{
			v[total] = temperatura;
			total++;
			fscanf_s(fichero, "%d", &temperatura);
		}
		fclose(fichero);
	}
	return total;
}

ordenat_temp(int v[], int total)
{
	for (int i = 0; i < total; i++)
	{
		for (int j = i + 1; j < total; j++)
		{
			if (v[j] < v[i])
			{

			}
		}
	}
}

void guardar_en_disco(int v[], int total)
{
	FILE* fichero;
	errno_t e;
	int i;

	e = fopen_s(&fichero, "Temperaturas.txt", "at");
	if (fichero == NULL)
		printf("Error: No se ha podido guardar el fichero\n");
	else
	{
		for(i=0;i<total;i++)
		fprintf(fichero, "%.2f", temp);

	}
	fclose(fichero);
}
*/
