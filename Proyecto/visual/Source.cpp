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
int menu_dist(void);
int menu_temp(void);

//Funciones Sensores
void verifica_sensores(Serial*, char*);

void monitorizar_sensor_distancia(Serial*);
void monitorizar_sensor_ilum(Serial*);
void monitorizar_sensor_temperatura(Serial*);
void guardar_temperatura(float* temperatura);
void leer_temperatura(void);
void leer_distancia(void);
void guardar_distancia(float* distancia);

void comprobar_mensajes(Serial*);

float leer_sensor_distancia(Serial*);
float leer_sensor_ilum(Serial*);
float leer_sensor_temperatura(Serial*);

int Enviar_y_Recibir(Serial*, const char*, char*);
float float_from_cadena(char* cadena);

//Funci?n motores
void mandar_motores(Serial*, char);


int main(void)
{
	Serial* Arduino;
	char puerto[] = "COM3"; // Puerto serie al que est? conectado Arduino
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
			char control_mover;
			do
			{
				control_mover = menu_mover();
				mandar_motores(Arduino, control_mover);

			} while (control_mover != 'e');
			break;

		case 2:
		{
			system("cls");
			int opcion_temp;
			do {
				opcion_temp = menu_temp();
				switch (opcion_temp)
				{
				case 1:
				{
					monitorizar_sensor_temperatura(Arduino);
				}
				break;
				case 2:
				{
					leer_temperatura();
				}
				break;
				default:
					break;
				}


			} while (opcion_temp != 3);
		}
		break;


		case 3:
		{
			system("cls");
			int opcion_dist;
			do {
				opcion_dist = menu_dist();
				switch (opcion_dist)
				{
				case 1:
				{
					monitorizar_sensor_distancia(Arduino);
				}
				break;
				case 2:
				{
					leer_distancia();
				}
				break;
				default:
					break;
				}

			} while (opcion_dist != 3);
		}break;

		case 4:
		{ system("cls");
			int opcion_luces;
			do {
				opcion_luces = menu_luces();
				switch (opcion_luces)
				{
				case 0:
					break;
				case 1:
					system("cls");
					monitorizar_sensor_ilum(Arduino);
					break;
				default:
					break;
				}
			} while (opcion_luces != 2);
				break;
				
		case 5:
			system("cls");
			printf("\nSalida del programa\n\n");;
			break;

		default:
			system("cls");
			break;
			}
		}
	} while (opcion_menu != 5);
	return 0;
}






// ***************************************************************************************
// Las funciones men? se limitan a mostrar en pantalla las ofertas de opciones disponibles
// ***************************************************************************************
int menu(void)
{

	static int opcion = -1;

	if (opcion != 0)
	{
		system("cls");
		printf("\n");
		printf("MENU PRINCIPAL:\n");
		printf("Seleccione una opci?n:\n\n");
		printf("1. Movilidad del coche\n");
		printf("2. Temperatura del coche\n");
		printf("3. Distancia a la que estan los objetos del coche\n");
		printf("4. Las luces del coche\n");
		//printf("5. Abrir o cerrar puertas del coche.\n");
		printf("5. Salir de la aplicaci?n.\n");
		printf("Opci?n:");
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
		printf("Seleccione una direcci?n:\n\n");
		printf("                              ---\n");
		printf("                             | W |\n");
		printf("                      ---     ---    ---\n");
		printf("                     | A |          | D |\n");
		printf("                      ---     ---    ---\n");
		printf("                             | S |\n");
		printf("                              ---\n\n\n");
		printf("///////////////Selecciones E para salir a menu///////////////\n");
	}
	if (_kbhit())
	{
		opcion = (char)_getch();
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
		printf("\n\n");
		printf("?Que luces quieres encender?\n");
		printf("1. Valores de la luz\n");
		printf("2. Salir\n");
		printf("Opci?n:");
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

int menu_temp(void)
{
	setlocale(LC_ALL, "es-ES");
	static int opcion_temp = -1;

	if (opcion_temp != 0)
	{
		printf("\n\n");
		printf("Seleciona una opci?n:\n");
		printf("1. Valores de las temperaturas\n");
		printf("2. Temperaturas registradas\n");
		printf("3. Salir\n");
		printf("Opci?n:");
	}
	if (_kbhit())
	{
		opcion_temp = (int)_getch() - '0';
		printf("%d\n", opcion_temp);
	}
	else
		opcion_temp = 0;
	return opcion_temp;
}

int menu_dist(void)
{

	setlocale(LC_ALL, "es-ES");
	static int opcion_dis = -1;

	if (opcion_dis != 0)
	{
		printf("\n\n");
		printf("Seleciona una opci?n:\n");
		printf("1.Leer distancia\n");
		printf("2.Distancias registradas\n");
		printf("3. Salir\n");
		printf("Opci?n:");
	}
	if (_kbhit())
	{
		opcion_dis = (int)_getch() - '0';
		printf("%d\n", opcion_dis);
	}
	else
		opcion_dis = 0;
	return opcion_dis;
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




void guardar_distancia(float* distancia)
{
	FILE* fichero;
	errno_t e;
	e = fopen_s(&fichero, "Registro_distancia.txt", "a+t");
	if (fichero == NULL)
	{
		printf("Hay algun error");
	}
	else
	{
		fprintf_s(fichero, "%f\n", *distancia);
	}
	fclose(fichero);
}

void leer_distancia(void)
{
	
	FILE* fichero;
	errno_t e;
	float  distancias[50];
	int i = 0, contador = 0;
	e = fopen_s(&fichero, "Registro_distancia.txt", "a+t");
	if (fichero == NULL)
	{
		printf("Hay algun error");
	}
	else
	{
		while (!feof(fichero))
		{
			fscanf_s(fichero, "%f", &distancias[i]);
			i++;
			contador++;
		}
		
		printf("\n Distancias registradas hasta el momento: \n");
		for (i = 0; i < contador-1; i++)
		{
			printf("%.2f\n", distancias[i]);

		}

	}
	fclose(fichero);
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

	printf("Pulse una tecla para finalizar la monitorizaci?n\n");
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

	printf("Pulse una tecla para finalizar la monitorizaci?n\n");
	do
	{
		if (Arduino->IsConnected())
		{
			temperatura = leer_sensor_temperatura(Arduino);
			if (temperatura != -1)
			{
				printf("%.2f ", temperatura);
				guardar_temperatura(&temperatura);
			}

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

void monitorizar_sensor_distancia(Serial* Arduino)
{
	float frecuencia, distancia;
	char tecla;
	do
	{
		printf("Establezca frecuencia de muestreo (0,5 Hz - 2,0 Hz):");
		scanf_s("%f", &frecuencia);
	} while (frecuencia < 0.5 || frecuencia>2.0);

	printf("Pulse una tecla para finalizar la monitorizaci?n\n");
	do
	{
		if (Arduino->IsConnected())
		{
			distancia = leer_sensor_distancia(Arduino);
			if (distancia != -1)
			{
				printf("%.2f ", distancia);
				guardar_distancia(&distancia);
			}
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




void guardar_temperatura(float* temperatura)
{
	FILE* fichero;
	errno_t e;
	e = fopen_s(&fichero, "Registro_temperatura.txt", "a+t");
	if (fichero == NULL)
	{
		printf("Hay algun error");
	}
	else
	{
		fprintf_s(fichero, "%.2f\n", *temperatura);
	}
	fclose(fichero);
}

void leer_temperatura(void)
{
	FILE* fichero;
	errno_t e;
	float temperaturas[50];
	int i = 0, contador = 0;
	float menor, mayor;
	e = fopen_s(&fichero, "Registro_temperatura.txt", "rt");
	if (fichero == NULL)
	{
		printf("Hay algun error");
	}
	else
	{
		while (!feof(fichero))
		{
			fscanf_s(fichero, "%f", &temperaturas[i]);
			i++;
			contador++;
		}
		menor = mayor = temperaturas[0];
		printf("Temperaturas registradas hasta el momento: \n");
		for (i = 0; i <contador-1; i++)
		{
			printf("%.2f\n", temperaturas[i]);
			if (temperaturas[i] < menor)
			{
				menor = temperaturas[i];
			}
			if (temperaturas[i] > mayor)
			{
				mayor = temperaturas[i];
			}
		}
		printf("La temperatura maxima registrada ha sido %.2f\n", mayor);
		printf("La temperatura minima registrada ha sido %.2f\n", menor);
	}
	fclose(fichero);
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
		printf("Revise la conexi?n, el puerto %s y desactive el monitor serie del IDE de Arduino.\n", port);
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
		case 0:// Antes del n?mero
			if (cadena[i] >= '0' && cadena[i] <= '9')
			{
				numero = cadena[i] - '0';
				estado = 1;
			}
			break;
		case 1:// Durante el n?mero
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





void mandar_motores(Serial* Arduino, char control_mover)
{
	int bytesRecibidos;
	char mensaje_recibido[MAX_BUFFER];

	switch (control_mover)
	{
	case 0:
		break;
	case 'w':
	{
		system("cls");
		bytesRecibidos = Enviar_y_Recibir(Arduino, "w\n", mensaje_recibido);
		printf("////Moviendo coche recto////\n\n");
		break;
	}
	case 'a':
	{
		system("cls");
		bytesRecibidos = Enviar_y_Recibir(Arduino, "a\n", mensaje_recibido);
		printf("////Moviendo coche izquierda////\n\n");

		break;
	}
	case 'd':
	{system("cls");
	printf("////Moviendo coche derecha/////\n\n");
	bytesRecibidos = Enviar_y_Recibir(Arduino, "d\n", mensaje_recibido);

	break;
	}
	case 's':
	{
		system("cls");
		bytesRecibidos = Enviar_y_Recibir(Arduino, "s\n", mensaje_recibido);
		printf("////Moviendo coche hacia atras////\n\n");

		break;
	}
	case 'e':
		break;

	default:system("cls");
		printf("Opci?n incorrecta de movimiento\n");
		break;
	}
}
