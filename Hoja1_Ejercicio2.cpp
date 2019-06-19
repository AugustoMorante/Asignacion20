#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
	int m, n;
	bool simetrica;
	int**matriz;
	while (1)
	{
		do
		{
			cout << "Inserte m: "; cin >> m;
		} while (m <= 0 || m >= 10);
		do
		{
			cout << "Inserte n: "; cin >> n;
		} while (n <= 0 || n >= 10);
		cout << endl;
		matriz = new int*[n];
		for (int i = 0; i < n; i++)
		{
			matriz[i] = new int[m];
			for (int j = 0; j < m; j++)
			{
				if (i == j)
				{
					simetrica = 1;
				}
				else
				{
					simetrica = 0;
				}
			}
		}

		if (simetrica == true)
			cout << "Si es simetrica" << endl;
		else
			cout << "No es simetrica" << endl;
		cout << endl;
	}
	_getch();
}