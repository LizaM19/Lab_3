#define _CRT_SECURE_NO_WARNINGS
#include "locale"
#include "stdio.h"
#include "conio.h"
#include <locale.h> 
#include <stdlib.h>
#include <malloc.h>
#include <iostream>

void main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	int size1;
	printf("Введите размерность матрицы 1:  ");
	scanf("%d", &size1);

	int size2;
	printf("Введите размерность матрицы 2:  ");
	scanf("%d", &size2);

	int** m1;
	m1 = (int**)malloc(size1 * sizeof(int*));

	for (int i = 0; i < size1; i++)  // цикл по строкам
	{
		m1[i] = (int*)malloc(size1 * sizeof(int));
	}

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++) {
			m1[i][j] = rand() % 2;
			if (i == j) {
				m1[j][i] = 0;
			}
			printf("%3d,", m1[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	int** m2;
	m2 = (int**)malloc(size2 * sizeof(int*));

	for (int i = 0; i < size2; i++)  // цикл по строкам
	{
		m2[i] = (int*)malloc(size2 * sizeof(int));
	}

	int temp;
	for (int i = 0; i < size2; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			m2[i][j] = rand() % 2;
			if (i == j) {
				m2[j][i] = 0;
				
			}
			printf("%3d,", m2[i][j]);
			
		}
	printf("\n");
	}
	printf("\n");


	int** n;
	n = (int**)malloc(size1 * size2 * sizeof(int*));

	for (int i = 0; i < size1 * size2; i++)  // цикл по строкам
	{
		n[i] = (int*)malloc(size1 * size2 * sizeof(int));
	}


	/*int m1[2][2] = {
		{0, 1},
		{1, 0}
	};
	int m2[3][3] = {
		{0, 1, 0},
		{1, 0, 1},
		{0, 1, 0},
	};
	int n[20][20];*/
	for (int i = 0; i < size1 * size2; i++) {
		for (int j = 0; j < size1 * size2; j++) {
			n[i][j] = 2;
		}
	}

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < i + 1; j++) {
			int ioffset = size2 * i;
			int joffset = size2 * j;
			for (int k = ioffset; k < ioffset + size2; k++) {
				for (int l = joffset; l < joffset + size2; l++) {
					int val = m1[i][j] == 0 ? m2[k - ioffset][l - joffset] : k - ioffset == l - joffset ? 1 : 0;
					n[k][l] = val;
					n[l][k] = val;
				}
			} 
		}
	}

	for (int i = 0; i < size1 * size2; i++) {
		for (int j = 0; j < size1 * size2; j++) {
			printf("%d, ", n[i][j]);
		}
		printf("\n");
	}
}




