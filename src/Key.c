#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Key.h"

// Gera uma chave aleatória...
int GenerateKey()
{
	static int init = 0;
	if (!init)
	{
		srand(time(NULL));
		init++;
	}
	
	return rand();
}

// Gera um arquivo com uma chave gravada...
int SetKey(const char* keyPath, int key)
{
	FILE* file = fopen(keyPath, "w");

	if (!file) printf("Error!\n");
	else
	{
		fprintf(file, "%d", key);
		fclose(file);

		return key;
	}
}

// Retorna chave gravada no arquivo de chave...
int GetKey(const char* keyPath)
{
	FILE* file = fopen(keyPath, "r");

	if (!file) printf("Error!");
	else
	{
		int key;
		fscanf(file, "%d", &key);
		fclose(file);

		return key;
	}
}