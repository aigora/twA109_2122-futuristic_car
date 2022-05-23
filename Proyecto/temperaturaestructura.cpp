#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10

void guardar_en_disco(int v[], float temp);
int leer_desde_disco(int v[]);

int main(void)
{
    int temperaturas[MAX];
    int i, temperatura, total = 0;

    setlocale(LC_ALL, "es-ES");
    total = leer_desde_disco(temperaturas);
    printf("Partimos de\n");
    for (i = 0; i < total; i++)
        printf("%d ", temperaturas[i]);

    printf("Introduzca enteros (FIN=-1)");
    scanf_s("%d", &temperatura);
    while (temperatura != -1)
    {
        temperaturas[total] = temperatura;
        total++;
        scanf_s("%d", &temperatura);
    }
    printf("Ahora hay\n");
    for (i = 0; i < total; i++)
        printf("%d ", temperaturas[i]);
    guardar_en_disco(temperaturas, total);

    return 0;
}

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

void guardar_en_disco(int v[], float* temp)
{
    FILE* fichero;
    errno_t e;
    int i;

    e = fopen_s(&fichero, "Temperaturas.txt", "at");
    if (fichero == NULL)
        printf("Error: No se ha podido guardar el fichero\n");
    else
    {
       
       fprintf(fichero, "%.2f", temp);
        
    }
	fclose(fichero);
}

void verifica_sensores(Serial* Arduino, char* port)
{
	float temperatura;

	if (Arduino->IsConnected())
	{
		temperatura = leer_sensor_temperatura(Arduino);
		if (temperatura != -1)
			printf("%f\n", temperatura);
	}
	else
	{
		printf("\nNo se ha podido conectar con Arduino.\n");
		printf("Revise la conexión, el puerto %s y desactive el monitor serie del IDE de Arduino.\n", port);
	}
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
