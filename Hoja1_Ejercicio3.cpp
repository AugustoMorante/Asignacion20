
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;
using namespace System;


int main()
{
	int m, n;
	int**matriz;
	do
	{
		cout << "Inserte m: "; cin >> m;
	} while (m < 0 || m >= 10);

	do
	{
		cout << "Inserte n: "; cin >> n;
	} while (n < 0 || n >= 10);
	matriz = new int*[m];

	for (int i = 0; i < m; ++i)
	{
		matriz[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			cout << "Inserte matriz[" << i << "][" << j << "] :"; cin >> matriz[i][j];
		}
	}

	cout << endl;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << matriz[i][j];
		}
		cout << endl;
	}

	cout << endl;
	cout << "Matriz transpuesta\n" << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << matriz[j][i];
		}
		cout << endl;
	}
	

	_getch();
}