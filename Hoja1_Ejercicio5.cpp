#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
using namespace std;
#define filas 4
#define columnas 5

void generarVotos(int **votos, int &fila, int &columna) {
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {
			votos[i][j] = rand() % 51;
		}
	}
}

void mostrarMesas(int &mesa) {
	switch (mesa) {
	case 0:
		cout << "1";
		break;
	case 1:
		cout << "2";
		break;
	case 2:
		cout << "3";
		break;
	case 3:
		cout << "4";
		break;
	}
}

void mostrarVotos(int **votos, int &fila, int &columna) {
	cout << "\t";
	for (int j = 0; j < columna; j++) {
		cout << j + 1 << "\t";
	}
	cout << endl;
	for (int i = 0; i < fila; i++) {
		mostrarMesas(i);
		for (int j = 0; j < columna; j++) {
			cout << "\t" << votos[i][j];
		}
		cout << endl;
	}
}

int votosPorCandidato(int **votos, int &fila, int &candidato) {
	int suma = 0;
	for (int i = 0; i < fila; i++) {
		suma += votos[i][candidato];
	}
	return suma;
}

int votosTotal(int **votos, int &fila, int &columna) {
	int sumaTotal = 0;
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {
			sumaTotal += votos[i][j];
		}
	}
	return sumaTotal;
}

int main() {
	srand(time(NULL));
	int **votos;
	int fila = filas;
	int columna = columnas;
	votos = new int *[filas];
	for (int i = 0; i < filas; i++) {
		votos[i] = new int[columnas];
	}

	generarVotos(votos, fila, columna);
	mostrarVotos(votos, fila, columna);

	float *sumaCand = new float[5];
	float *sumaTotal = new float[5];
	float *porcentaje = new float[5];
	float mayor1 = porcentaje[0];
	float mayor2 = porcentaje[1];
	int posMayor1, posMayor2;
	int masVotado;
	int ganador = 0;
	int aux;
	for (int i = 0; i < columna; i++) {
		sumaCand[i] = votosPorCandidato(votos, fila, i);
		sumaTotal[i] = votosTotal(votos, fila, columna);
		porcentaje[i] = sumaCand[i] / sumaTotal[i] * 100;
		cout << "El total de votos obtenidos por el candidato " << i + 1 << " fueron " << sumaCand[i] << " con un " << porcentaje[i] << "%" << endl;

		if (porcentaje[i] > mayor1) {
			mayor1 = porcentaje[i];
			masVotado = i;
		}

	}
	cout << "El candidato mas votado fue el " << masVotado + 1 << endl;

	for (int i = 0; i < columna; i++) {
		if (porcentaje[i] >= 50) {
			aux = 0;
			masVotado = i;
		}
		else if (porcentaje[i] < 50) {
			aux = 1;
		}
		ganador += aux;
	}

	for (int i = 0; i < columna; i++) {
		if (mayor1 < porcentaje[i]) {
			mayor1 = porcentaje[i];
			posMayor1 = i;
		}
	}
	for (int i = 0; i < columna; i++) {
		if (mayor2 < porcentaje[i] && posMayor1 != i) {
			mayor2 = porcentaje[i];
			posMayor2 = i;
		}
	}

	if (ganador < 5) {
		cout << "El candidato ganador es " << ganador + 1 << endl;
	}
	if (ganador == 5) {
		cout << "El candidato " << posMayor1 + 1 << " y el candidato " << posMayor2 + 1 << " pasan a segunda ronda" << endl << endl;
	}
	_getch();
}