#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<locale.h>
#include <conio.h>
#include "SerialClass/SerialClass.h"


#define MAX_BUFFER 200
#define PAUSA_MS 200


int menu();
int menu_luces();
int menu_ac();
/*float velocidad();
float vel_media();*/


//Funciones para sensores
void verifica_sensor_distancia(Serial*, char*);
void monitorizar_sensor_distancia(Serial*);
void monitorizar_sensor_ilum(Serial*);
void comprobar_mensajes(Serial*);
float leer_sensor_distancia(Serial*);
float leer_sensor_ilum(Serial*);
int Enviar_y_Recibir(Serial*, const char*, char*);
float float_from_cadena(char* cadena);


int main(void)
{
	setlocale(LC_ALL, "es-ES");

	//Menú principal
	int opcion;

	/*/Velocidad
	int opcion_v;
	float v_media;*/

	//Temperatura
	double temperatura;

	//Distancia
	float distancia;

	//Luces
	int luces_opcion;

	//Abrir o cerrar coche
	int abr_cerr_opcion;

	
	do
	{
		opcion = menu();
		switch (opcion)
		{
		/*case 1:
		{
			opcion_v = velocidad();
			do
			{
				switch (opcion_v)
				{
				case 1:
				{float v = 2.239;
				printf("/////////Pulse cualquier tecla del teclaro/////////\n\n");
				printf("La velocidad actual del vehículo es de:\n");

				do
				{
					printf("%.2f m/s", v);//Se irá actualizando hasta que no se pulse una letra
				} while (_kbhit()==0);
				system("cls");
				break;
				}

				case 2:
				{
					v_media = vel_media();
					system("cls");
					break;
				}

				default:
					break;
				}

			} while (opcion_v != 3);
			break;
		}*/


		case 2:
		{
			char control;
			//char direccion[L];
			//int i = 0;

			do
			{
				printf("/////////Selecione 0 para salir///////////\n\n");
				printf("Selecione: W A S para mover el coche\n");
				scanf_s("%c", &control);

				//direccion[i] = control;
				//i++;

				switch (control)
				{
				case 'w':
				{

					//Mover al frente
					break;
				}
				case 'a':
				{

					//Mover izquierda
					break;
				}
				case 'D':
				{

					//Mover derecha
					break;
				}

				default:
					break;
				}

			} while (control != '0');
		}

		case 3:
		{//Aquí se indicará el valor de la temperatura obtenida en el sensor de temperatura
			temperatura = 25.52;
			printf("La temperatura del experior del coche es %.2fºC y %.2fK", temperatura, temperatura + 273);
			int s;
			scanf_s("%d", &s);
			system("cls");
			break;
		}

		case 4:
		{

			monitorizar_sensor_distancia(Arduino);
			break;
		}

		case 5:
		{

			do {
				luces_opcion = menu_luces();

				switch (luces_opcion)
				{

				case 1:
				{
					int s;
					printf("1. Encendiendo luces de largo alcance\n");
					scanf_s("%d", &s);
					break;
					//Se encenderán los leds con mucha intensidad
				}
				case 2:
				{
					int s;
					printf("2. Encendiendo luces de corto alcance\n");
					scanf_s("%d", &s);
					break;
					//Se encenderán los leds con poca intensidad
				}
				case 3:
				{
					printf("3. Encendiendo luces automaticas\n\n");
					monitorizar_sensor_distancia(Arduino);
					break;
				
				}
				default:
					break;
				}
				system("cls");
			} while (luces_opcion != 4);
			break;
		}
		case 6:
		{			
			do {
				abr_cerr_opcion = menu_ac();
				switch (abr_cerr_opcion)
				{
				case 1:
				{
					int s;
					printf("1. El coche esta abierto\n");
					scanf_s("%d", &s);
					break;
					//Se desbloqueará la puerta
				}
				case 2:
				{
					int s;
					printf("2. El coche esta cerrado\n");
					scanf_s("%d", &s);
					break;
					//Se cerrará el coche
				}
				default:
					break;
				}
				system("cls");
			} while (abr_cerr_opcion!=3);
			break;
		}
		
		default:
			break;
		}
	}while (opcion != 7);


	return 0;
}




int menu()
{
	int opcion;
	printf("MENU PRINCIPAL:\n");
	printf("Seleccione una opción:\n\n");
	//printf("1. Velocidad del coche\n");
	printf("2. Movilidad del coche\n");
	printf("3. Temperatura fuera del coche\n");
	printf("4. Distancia a la que estan los objetos del coche\n");
	printf("5. Las luces del coche\n");
	printf("6. Abrir o cerrar puertas del coche.\n");
	printf("7. Salir de la aplicación.\n");

	scanf_s("%d", &opcion);
	system("cls");
	return opcion;
}

int menu_ac()
{
	int opc;
	printf("¿Quieres abrir o cerrar coche?\n");
	printf("1. Abrir coche\n");
	printf("2. Cerrar coche\n");
	printf("3. Salir\n");
	
	scanf_s("%d", &opc);
	system("cls");

	return opc;
}

int menu_luces()
{
	int op;
	printf("¿Que luces quieres encender?\n");
	printf("1. Luces de largo alcance\n");
	printf("2. Luces de corto alcance\n");
	printf("3. Luces de forma automatica\n");
	printf("4. Salir\n");

	scanf_s("%d", &op);
	system("cls");
	return op;


}






/*float velocidad()
{
	int op_v;
	int v;
	printf("Seleccione una opción:\n");
	printf("1.Velocidad del veículo en este momento\n");
	printf("2.Velocidad media del coche en un intervalo determinado\n\n");
	printf("3.Atrás\n");

	scanf_s("%d", &op_v);
	system("cls");
	return op_v;
	
}

float vel_media()
{
	printf("Seleccione cuando quiera empezar el tiempo");
	//Aquí se podrá seleccionar una tecla para empezar a cronometrar el tiempo para realizar el recorrido
	float v1, v2, v3;
	float v;
	do
	{
		v1 = 1;
		v2 = 3;
		v3 = 5;
		v = (float)(v1 + v2 + v3) / 3;
		printf("La velocidad media del vehículo en el recorrido seleccionado es de %.2f m/s", v);
	} while (_kbhit()==0);
	return v;
}*/


void verifica_sensor_distancia(Serial* Arduino, char* port)
{
	float distancia;

	if (Arduino->IsConnected())
	{
		distancia = leer_sensor_distancia(Arduino);
		if (distancia != -1)
			printf("\nDistancia: %f\n", distancia);
	}
	else
	{
		printf("\nNo se ha podido conectar con Arduino.\n");
		printf("Revise la conexión, el puerto %s y desactive el monitor serie del IDE de Arduino.\n", port);
	}
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
		mensaje_recibido[total - 1] = '\0';
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

void verifica_sensores(Serial* Arduino, char* port)
{
	float distancia;

	if (Arduino->IsConnected())
	{
		distancia = leer_sensor_distancia(Arduino);
		if (distancia != -1)
			printf("\nDistancia: %f\n", distancia);
	}
	else
	{
		printf("\nNo se ha podido conectar con Arduino.\n");
		printf("Revise la conexión, el puerto %s y desactive el monitor serie del IDE de Arduino.\n", port);
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

int Enviar_y_Recibir(Serial* Arduino, const char* mensaje_enviar, char* mensaje_recibir)
{
	int bytes_recibidos = 0, total = 0;
	int intentos = 0, fin_linea = 0;


	Arduino->WriteData((char*)mensaje_enviar, strlen(mensaje_enviar));
	Sleep(PAUSA_MS);

	bytes_recibidos = Arduino->ReadData(mensaje_recibir, sizeof(char) * MAX_BUFFER - 1);

	while ((bytes_recibidos > 0 || intentos < 5) && fin_linea == 0)
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
		bytes_recibidos = Arduino->ReadData(mensaje_recibir + total, sizeof(char) * MAX_BUFFER - 1);
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


	for (i = 0; cadena[i] != '\0' && estado != 3 && i < MAX_BUFFER; i++)
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