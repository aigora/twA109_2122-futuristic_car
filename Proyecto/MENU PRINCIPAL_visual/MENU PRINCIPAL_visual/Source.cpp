#include<stdio.h>
#include<stdlib.h>
#include<locale.h>



int menu();


int main(void)
{
	setlocale(LC_ALL, "es-ES");

	//Men� principal
	int opcion;

	//Velocidad
	int opcion_v;
	float v1, v2, v3;

	//Temperatura
	float temperatura;

	//Distancia
	float distancia;

	//Luces
	int luces_opci�n;

	//Abrir o cerrar coche
	int abr_cerr_opci�n;

	opcion = menu();
	
	do
	{
		switch (opcion)
		{
		case 1:
			opcion_v = velocidad();
			do
			{
				switch (opcion_v)
				{
				case 1:
					int v = 2.239;
					/*Aqu� se calcular� la velocidad que llevar� el veiculo.
					(Calculando el per�metro de la rueda, dividido por el tiempo que tarda la rueda en hacer una revoluci�n)*/
					do
					{
						printf("La velocidad actual del veh�culo es de %.2f m/s", velocidad);
					}while


				default:
					break;
				}

			} while (op_v != 3);




		default:
			break;
		}

		if (opcion == 1)
		{
			printf("Seleccione una opci�n:\n");
			printf("1.Velocidad del ve�culo en este momento\n");
			printf("2.Velocidad media del coche en un intervalo determinado\n\n");

			scanf_s("%d", &velocidad_opcion);
			if (velocidad_opci�n == 1)
			{
				velocidad = 2.239;
				/*Aqu� se calcular� la velocidad que llevar� el veiculo.
				(Calculando el per�metro de la rueda, dividido por el tiempo que tarda la rueda en hacer una revoluci�n)*/
				printf("La velocidad actual del veh�culo es de %.2f m/s", velocidad);
			}
			else if (velocidad_opci�n == 2)
			{
				printf("Seleccione cuando quiera empezar el tiempo");
				//Aqu� se podr� seleccionar una tecla para empezar a cronometrar el tiempo para realizar el recorrido

				v1 = 1;
				v2 = 3;
				v3 = 5;

				velocidad = (v1 + v2 + v3) / 3;
				/*Aqu� se pondr�n las velocidades que se obtendr�n cada poco tiempo del recorrido*/
				printf("La velocidad media del veh�culo en el recorrido seleccionado es de %.2f m/s", velocidad);
			}


		}
		else if (opci�n == 2)
		{
			//Aqu� se indicar� el valor de la temperatura obtenida en el sensor de temperatura
			temperatura = 25.52;
			printf("La temperatura del experior del coche es %.2f�C y %.2fK", temperatura, temperatura + 273);

		}
		else if (opci�n == 3)
		{
			distancia = 2.54;
			//Aqu� se indicar� el valor de la distancia obtenida en el sensor de distancia
			printf("La distancia al objeto es %.2f metros", distancia);
		}
		else if (opci�n == 4)
		{
			printf("�Que luces quieres encender?\n");
			printf("1. Luces de largo alcance\n");
			printf("2. Luces de corto alcance\n");
			printf("3. Luces de forma automatica\n\n");

			scanf_s("%d", &luces_opci�n);

			if (luces_opci�n == 1)
			{
				printf("1. Encendiendo luces de largo alcance\n");
				//Se encender�n los leds con mucha intensidad
			}
			else if (luces_opci�n == 2)
			{
				printf("2. Encendiendo luces de corto alcance\n");
				//Se encender�n los leds con poca intensidad
			}
			else if (luces_opci�n == 3)
			{
				printf("3. Encendiendo luces automaticas\n\n");
				//Se encender�n los leds con una intensidad que depende de la luz que detecte el sensor de luz
			}
		}
		else if (opci�n == 5)
		{
			printf("�Quieres abrir o cerrar coche?\n");
			printf("1. Abrir coche\n");
			printf("2. Cerrar coche\n");

			scanf_s("%d", &abr_cerr_opci�n);

			if (abr_cerr_opci�n == 1)
			{
				printf("1. El coche esta abierto\n");
				//Se desbloquear� la puerta
			}
			else if (abr_cerr_opci�n == 2)
			{
				printf("2. El coche esta cerrado\n");
				//Se cerrar� el coche
			}
		}
		else {
			printf("Error.\n");
		}
		scanf_s("%d", &opci�n);
	} while (opci�n != 6);

	return 0;
}




int menu()
{
	int opcion;
	printf("MENU PRINCIPAL:\n");
	printf("Seleccione una opci�n:\n\n");
	printf("1. Velocidad del coche\n");
	printf("2. Temperatura fuera del coche\n");
	printf("3. Distancia a la que estan los objetos del coche\n");
	printf("4. Las luces del coche\n");
	printf("5. Abrir o cerrar puertas del coche.\n");
	printf("6. Salir de la aplicaci�n.\n");

	scanf_s("%d", &opcion);
	system("cls");
	return opcion;
}

int velocidad()
{
	int op_v;
	int v;
	printf("Seleccione una opci�n:\n");
	printf("1.Velocidad del ve�culo en este momento\n");
	printf("2.Velocidad media del coche en un intervalo determinado\n\n");
	printf("3.Atr�s\n");

	scanf_s("%d", &op_v);
	system("cls");
	
}
