#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <conio.h>

#define L 100;



int menu();
float velocidad();
float vel_media();
int comandos(char);


int main(void)
{
	setlocale(LC_ALL, "es-ES");

	//Men� principal
	int opcion;

	//Velocidad
	int opcion_v;
	float v_media;

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
		case 1:
		{
			opcion_v = velocidad();
			do
			{
				switch (opcion_v)
				{
				case 1:
				{float v = 2.239;
				/*Aqu� se calcular� la velocidad que llevar� el veiculo.
				(Calculando el per�metro de la rueda, dividido por el tiempo que tarda la rueda en hacer una revoluci�n)*/
				printf("/////////Pulse cualquier tecla del teclaro/////////\n\n");
				printf("La velocidad actual del veh�culo es de:\n");

				do
				{
					printf("%.2f m/s", v);//Se ir� actualizando hasta que no se pulse una letra
				} while (!_kbhit());
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
		}


		case 2:
		{
			char control;
			//char direccion[L];
			//int i = 0;

			do
			{
				printf("/////////Selecione 0 para salir///////////\n\n");
				printf("Selecione: W A S D para mover el coche\n");
				scanf_s("%c", &control);

				//direccion[i] = control;
				//i++;

				switch (control)
				{
				case 'W':
				{

					//Mover al frente
					break;
				}
				case 'A':
				{

					//Mover izquierda
					break;
				}
				case 'D':
				{

					//Mover derecha
					break;
				}

				case 'S':
				{

					//Mover atr�s
					break;
				}

				default:
					break;
				}

			} while (control != '0');

			/*char op;
			printf("�Quieres ver los movimientos que han sido enviados?");
			printf("a)S�\nb)No");
			scanf_s("%c", &op);
			if (op == 'a')
			{
				
			}

			*/

		}

		case 3:
		{//Aqu� se indicar� el valor de la temperatura obtenida en el sensor de temperatura
			temperatura = 25.52;
			printf("La temperatura del experior del coche es %.2f�C y %.2fK", temperatura, temperatura + 273);
			int s;
			scanf_s("%d", &s);
			system("cls");
			break;
		}

		case 4:
		{
			int s;
			distancia = 2.54;
			//Aqu� se indicar� el valor de la distancia obtenida en el sensor de distancia
			printf("La distancia al objeto es %.2f metros\n", distancia);
			scanf_s("%d",&s);
			system("cls");
			break;
		}

		case 5:
		{

			do {
				printf("�Que luces quieres encender?\n");
				printf("1. Luces de largo alcance\n");
				printf("2. Luces de corto alcance\n");
				printf("3. Luces de forma automatica\n");
				printf("4. Salir\n");

				scanf_s("%d", &luces_opcion);

				system("cls");

				switch (luces_opcion)
				{

				case 1:
				{
					int s;
					printf("1. Encendiendo luces de largo alcance\n");
					scanf_s("%d", &s);
					break;
					//Se encender�n los leds con mucha intensidad
				}
				case 2:
				{
					int s;
					printf("2. Encendiendo luces de corto alcance\n");
					scanf_s("%d", &s);
					break;
					//Se encender�n los leds con poca intensidad
				}
				case 3:
				{
					int s;
					printf("3. Encendiendo luces automaticas\n\n");
					scanf_s("%d", &s);
					break;
					//Se encender�n los leds con una intensidad que depende de la luz que detecte el sensor de luz
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
			printf("�Quieres abrir o cerrar coche?\n");
			printf("1. Abrir coche\n");
			printf("2. Cerrar coche\n");
			printf("3. Salir\n");

			
			do {
				scanf_s("%d", &abr_cerr_opcion);
				switch (abr_cerr_opcion)
				{

				case 1:
				{
					int s;
					printf("1. El coche esta abierto\n");
					scanf_s("%d", &s);
					break;
					//Se desbloquear� la puerta
				}
				case 2:
				{
					int s;
					printf("2. El coche esta cerrado\n");
					scanf_s("%d", &s);
					break;
					//Se cerrar� el coche
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
	printf("Seleccione una opci�n:\n\n");
	printf("1. Velocidad del coche\n");
	printf("2. Movilidad del coche\n");
	printf("3. Temperatura fuera del coche\n");
	printf("4. Distancia a la que estan los objetos del coche\n");
	printf("5. Las luces del coche\n");
	printf("6. Abrir o cerrar puertas del coche.\n");
	printf("7. Salir de la aplicaci�n.\n");

	scanf_s("%d", &opcion);
	system("cls");
	return opcion;
}

float velocidad()
{
	int op_v;
	int v;
	printf("Seleccione una opci�n:\n");
	printf("1.Velocidad del ve�culo en este momento\n");
	printf("2.Velocidad media del coche en un intervalo determinado\n\n");
	printf("3.Atr�s\n");

	scanf_s("%d", &op_v);
	system("cls");
	return op_v;
	
}

float vel_media()
{
	printf("Seleccione cuando quiera empezar el tiempo");
	//Aqu� se podr� seleccionar una tecla para empezar a cronometrar el tiempo para realizar el recorrido
	float v1, v2, v3;
	float v;
	do
	{
		v1 = 1;
		v2 = 3;
		v3 = 5;
		v = (float)(v1 + v2 + v3) / 3;
		/*Aqu� se pondr�n las velocidades que se obtendr�n cada poco tiempo del recorrido*/
		printf("La velocidad media del veh�culo en el recorrido seleccionado es de %.2f m/s", v);
	} while (!_kbhit);
	return v;
}
