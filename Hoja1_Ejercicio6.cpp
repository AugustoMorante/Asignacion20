
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace System;
using namespace std;


void GenerarValoresMatriz(int** matriz, int& filas, int& columnas) {
	srand(time(NULL));
	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
			matriz[fila][columna] = rand() % 10 + 1;
			_sleep(50);
		}
	}
}


void MostrarMatriz(int** matriz, int& filas, int& columnas) {

	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
			cout << matriz[fila][columna] << " ";
		}
		cout << endl;
	}
}




void IniciarArrayCeroInt(int* array, int tamanio) {
	for (int i = 0; i < tamanio; i++)
		array[i] = 0;
}


void IniciarMatrizCeroInt(int** matriz, int& filas, int&columnas) {
	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
			matriz[fila][columna] = 0;
		}
	}
}

void GenerarTrianguloIngerior(int** matriz, int& filas, int& columnas, int** trianguloInferior) {
	for (int fila = 1; fila < filas; fila++) {
		for (int columna = 0; columna < fila; columna++) {
			trianguloInferior[fila][columna] = matriz[fila][columna] + matriz[columna][fila];
		}
	}
}


int main()
{
	int** matriz;
	int** trinaguloInferior;
	int filas = 3;
	int columnas = 3;

	matriz = new int*[filas];
	for (int fila = 0; fila < filas; fila++)
		matriz[fila] = new int[columnas];

	trinaguloInferior = new int*[filas];
	for (int fila = 0; fila < filas; fila++)
		trinaguloInferior[fila] = new int[columnas];


	GenerarValoresMatriz(matriz, filas, columnas);

	MostrarMatriz(matriz, filas, columnas);

	IniciarMatrizCeroInt(trinaguloInferior, filas, columnas);

	GenerarTrianguloIngerior(matriz, filas, columnas, trinaguloInferior);

	cout << endl;

	MostrarMatriz(trinaguloInferior, filas, columnas);

	_getch();
}