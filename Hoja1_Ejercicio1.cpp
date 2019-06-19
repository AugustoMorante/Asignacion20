#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

using namespace System;
using namespace std;

void GenerarValoresMatriz(int** matriz, int &filas, int &columnas) {
	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++)
		{
			matriz[fila][columna] = rand() % 11;
		}
	}
}

void MostrarMatriz(int** matriz, int& filas, int& columnas)
{
	for (int fila = 0; fila < filas; fila++)
	{
		for (int columna = 0; columna < columnas; columna++)
		{
			cout << matriz[fila][columna] << " ";
		}
		cout << endl;
	}
}

void MostrarMatrizTranspuesta(int** matriz, int& filas, int& columnas)
{
	for (int columna = 0; columna < columnas; columna++)
	{
		for (int fila = 0; fila < filas; fila++)
		{
			cout << matriz[fila][columna] << " ";
		}
		cout << endl;
	}
}

void SumaFilas(int** matriz, int& filas, int& columnas, int* sumas)
{
	for (int fila = 0; fila < filas; fila++)
	{
		for (int columna = 0; columna < columnas; columna++)
		{
			sumas[fila] = sumas[fila] + matriz[fila][columna];
		}
	}
}

void PromedioFilas(int** matriz, int& filas, int& columnas, double* promedios)
{
	for (int fila = 0; fila < filas; fila++)
	{
		for (int columna = 0; columna < columnas; columna++)
		{
			promedios[fila] = promedios[fila] + matriz[fila][columna];
		}
		promedios[fila] = promedios[fila] / columnas;
	}
}

void PromedioColumnas(int** matriz, int& filas, int& columnas, double* promedios)
{
	for (int columna = 0; columna < columnas; columna++)
	{
		for (int fila = 0; fila < filas; fila++)
		{
			promedios[columna] = promedios[columna] + matriz[fila][columna];
		}
		promedios[columna] = promedios[columna] / filas;
	}
}

void IniciarMatrizCeros(int** matriz, int& filas, int& columnas)
{
	for (int fila = 0; fila < filas; fila++)
	{
		for (int columna = 0; columna < columnas; columna++)
		{
			matriz[fila][columna] = 0;
		}
	}
}

void IniciarArregloCerosInt(int* arreglo, int& tamanio)
{
	for (int i = 0; i < tamanio; i++)
	{
		arreglo[i] = 0;
	}
}

void IniciarArregloCerosFloat(double* arreglo, int& tamanio)
{
	for (int i = 0; i < tamanio; i++)
	{
		arreglo[i] = 0.0;
	}
}

int MayorArregloInt(int* arreglo, int& tamanio)
{
	int mayor = -1;
	for (int i = 0; i < tamanio; i++)
	{
		if (arreglo[i] > mayor)
		{
			mayor = arreglo[i];
		}
	}

	return mayor;
}

int MenorArregloInt(int* arreglo, int& tamanio)
{
	int menor = 100000;
	for (int i = 0; i < tamanio; i++)
	{
		if (arreglo[i] < menor)
		{
			menor = arreglo[i];
		}
	}

	return menor;
}

double MayorArregloFloat(double* arreglo, int& tamanio)
{
	double mayor = -1.0;
	for (int i = 0; i < tamanio; i++)
	{
		if (arreglo[i] > mayor)
		{
			mayor = arreglo[i];
		}
	}

	return mayor;
}

void MayorMatrizInt(int** matriz, int& filas, int& columnas, int& mayorValor, int& posFila, int& posCol)
{
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (matriz[i][j] > mayorValor)
			{
				mayorValor = matriz[i][j];
				posFila = i;
				posCol = j;
			}
		}
	}
}

int main()
{
	int** matriz;
	int filas;
	int columnas;
	int* suma;
	double* promedios;
	int posFila = -1;
	int posCol = -1;
	int mayorValor = -1;


	do {
		cout << "Ingrese el numero de filas: "; cin >> filas;
	} while (filas <= 0 || filas > 10);
	do {
		cout << "Ingrese el numero de columnas: "; cin >> columnas;
	} while (columnas <= 0 || columnas > 10);

	matriz = new int*[filas];
	for (int fila = 0; fila < filas; fila++)
	{
		matriz[fila] = new int[columnas];
	}
	suma = new int[filas];
	promedios = new double[filas];

	IniciarMatrizCeros(matriz, filas, columnas);
	IniciarArregloCerosInt(suma, filas);
	IniciarArregloCerosFloat(promedios, filas);

	GenerarValoresMatriz(matriz, filas, columnas);

	MostrarMatriz(matriz, filas, columnas);

	cout << endl;

	MostrarMatrizTranspuesta(matriz, filas, columnas);

	cout << endl;

	SumaFilas(matriz, filas, columnas, suma);


	cout << endl;

	PromedioFilas(matriz, filas, columnas, promedios);

	for (int i = 0; i < filas; i++)
	{
		cout << "La suma de la fila #" << i << ": " << suma[i] << endl;
	}
	cout << "El mayor valor de las sumas es: " << MayorArregloInt(suma, filas);
	cout << endl;
	cout << "El menor valor de las sumas es: " << MenorArregloInt(suma, filas);

	cout << endl;


	for (int i = 0; i < filas; i++)
	{
		cout << "El promedio de la fila " << i << ": " << promedios[i] << endl;
	}

	cout << endl;

	delete[] promedios;

	promedios = new double[columnas];

	IniciarArregloCerosFloat(promedios, columnas);
	PromedioColumnas(matriz, filas, columnas, promedios);

	for (int i = 0; i < filas; i++)
	{
		cout << "El promedio de la columna :" << i << ": " << promedios[i] << endl;
	}
	cout << "El mayor valor de los promedios: " << MayorArregloFloat(promedios, columnas);
	cout << endl;


	MayorMatrizInt(matriz, filas, columnas, mayorValor, posFila, posCol);
	cout << "El mayor valor de la matriz es: " << mayorValor << endl;
	cout << "Fila: " << posFila << endl;
	cout << "Columna: " << posCol << endl;

	for (int fila = 0; fila < filas; fila++)
	{
		delete[] matriz[fila];
	}

	delete[] matriz;
	delete[] suma;
	delete[] promedios;


	_getch();
	return 0;
}
