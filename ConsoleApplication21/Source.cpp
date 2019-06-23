/* @file Source.cpp 
  @author игнатенко Д.Д., гр. 515А
* @date 22.06.2019
* @brief Практична работа
*/
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct {
	char nazva[20];
	int dlinna;
	int glubina;
} RIV;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	FILE *fileukaz;
	RIV reki[12] = { 0 };
	fileukaz = (FILE*)fopen("file.txt", "r");
	int summa = 0, n = 0;
	fseek(fileukaz, 0, SEEK_SET);
	for (int i = 0; i < 12; ++i)
	{
		fscanf(fileukaz, "%s", reki[i].nazva);
		fscanf(fileukaz, " %ld", &reki[i].dlinna);
		fscanf(fileukaz, " %d;", &reki[i].glubina);
		if (reki[i].glubina < 50)
		{
			summa += reki[i].dlinna;
		}
	}
	printf("1. Просмотр \n2. Общая длинна рек с глубиной меньше 50 м\n");
	scanf(" %d", &n);
	switch (n)
	{
	case 1:
		for (int i = 0; i < 12; i++)
		{
			printf("%20s", reki[i].nazva);
			printf(" %4d", reki[i].dlinna);
			printf(" %2d;\n", reki[i].glubina);
		} break;
	case 2:
		printf(" %d км \n", summa); break;
	default:
		printf("Ошибка!"); break;
	}
	fclose(fileukaz);
	system("pause");
	return 0;
}