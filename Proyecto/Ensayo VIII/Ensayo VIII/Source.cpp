/*
#include <stdio.h>
#include<stdlib.h>

int es_primo(int numero);

int main(void)
{
	int numero, i;

	do
	{
		printf("Introduce: ");
		scanf_s("%d", &numero);
		if (numero < 0)
			printf("El num no es positivo flaco\n");

	} while (numero < 0);

	/*
	//Este programa no funciona porq no pudes obtener otro número
	for (i = 2;i < numero;i++)
	{
		if (es_primo(i) == 1)
		{
			if (numero % i == 0)
			{
				printf("%d", i);
				numero = numero / i;
			}
		}
	}
	*//*
	i = 2;
	while (!es_primo(numero))
	{
		if (es_primo(i) == 1)
		{
			if (numero % i == 0)
			{
				printf("%d ", i);
				numero = numero / i;
				i = 2;
			}
			else
			{
				i++;
			}
		}
	}
	printf("%d", numero);


}
int es_primo(int numero)
{
	int primo = 1, i;
	for (i = 2;i < numero && primo == 1;i++)
	{
		if (numero % i == 0)
			primo = 0;
	}
	return primo;
}

*/


#include <stdio.h>
#include <stdlib.h>


int es_primo(int);

int main(void)
{
	int numero;
	do
	{
		scanf("%d", &numero);
		if (numero < 0)
			printf("El número debe ser positivo\n");
	} while (numero < 0);

	int i = 2;

	while (!es_primo(numero))
	{
		if (es_primo(i) == 1)
		{
			if (numero % i == 0)
			{
				printf("%d ", i);
				numero = numero / i;
				i = 2;
			}
			else
			{
				i++;
			}
		}
	}
	printf("%d\n", numero);
	return 0;
}

int es_primo(int n)
{
	int i;
	int primo = 1;
	for (i = 2; i < n && primo == 1; i++)
	{
		if (n % i == 0)
			primo = 0;
	}
	return primo;
}