/*
 ============================================================================
 Name        : BelucciSofia_RPPP1G.c
 Author      : Sofia Belucci
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {

	int id;
	char procesador[10];
	char marca[10];
	float precio;

} Notebook;

int calcularIVA(float precioBruto, float *impuesto);
int subibaja(char cadena[]);
int ordenarLista(Notebook array[], int tam);

int main(void) {
	setbuf(stdout, NULL);

	/*
	 float impuestoIva = 21;
	 calcularIVA(300, &impuestoIva);
	 */

	/*
	 char cadenaCaracteres[6] = "SoFiA";
	 subibaja(cadenaCaracteres);
	 printf("%s", cadenaCaracteres);
	 */

	Notebook listaNotebooks[5] = { { 1, "i5", "Lenovo", 30000 }, { 2, "Radeon",
			"Samsung", 60000 }, { 3, "i7", "HP", 75000 }, { 4, "amd",
			"Bangho", 55000 }, { 5, "i3", "Bangho", 25000 }, };

	ordenarLista(listaNotebooks, 5);

	for(int i = 0; i < 5; i++)
	{
		printf("\n ID: %d, Procesador: %s, Marca: %s, Precio: %.2f\n", listaNotebooks[i].id, listaNotebooks[i].procesador, listaNotebooks[i].marca, listaNotebooks[i].precio);
	}

	return 0;
}

int calcularIVA(float precioBruto, float *impuesto) {
	int todoOk = 0;
	float resultadoIva;

	if (impuesto != NULL) {

		resultadoIva = (precioBruto * 21) / 100;

		printf("%.2f", precioBruto - resultadoIva);

		todoOk = 1;
	}

	return todoOk;
}

int subibaja(char cadena[]) {
	int todoOk = 0;

	if (cadena != NULL) {
		for (int i = 0; i < strlen(cadena); i++) {
			if (isupper(cadena[i])) {
				cadena[i] = tolower(cadena[i]);
			} else if (islower(cadena[i])) {
				cadena[i] = toupper(cadena[i]);
			}
		}

		todoOk = 1;
	}

	return todoOk;

}

int ordenarLista(Notebook array[], int tam) {
	int todoOk = 0;
	Notebook auxNotebook;

	if (array != NULL && tam > 0) {

		for (int i = 0; i < tam - 1; i++) {

			for (int j = i + 1; j < tam; j++) {

				if(stricmp(array[i].marca, array[j].marca) > 0 || (stricmp(array[i].marca, array[j].marca) == 0 && array[i].precio < array[j].precio))
				{

					auxNotebook = array[i];
					array[i] = array[j];
					array[j] = auxNotebook;


				}
			}

		}

		todoOk = 1;
	}

	return todoOk;

}

