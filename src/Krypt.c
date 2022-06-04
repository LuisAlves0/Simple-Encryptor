#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Krypt.h"

// Criptografa arquivo
void Encrypt(const char* filePath, const char* keyPath, int key)
{
	FILE* file = fopen(filePath, "r");

	if (!file) printf("Error!\n");
	else
	{
		SetKey(keyPath, key);
		char buffer[99999];
		FILE* crpt = fopen("___.krpt", "a");

		while (fgets(buffer, 99999, file))
		{
			for (int i = 0; i < 99999 && buffer[i] != '\0'; i++)
			{
				buffer[i] += key;
			}
			fputs(buffer, crpt);
		}

		fclose(file);
		fclose(crpt);
		remove(filePath);
		rename("___.krpt", filePath);
	}
}

// Descriptografa arquivo
void Decrypt(const char* filePath, const char* keyPath)
{
	FILE* file = fopen(filePath, "r");

	if (!file) printf("Error!\n");
	else
	{
		int key = GetKey(keyPath);
		char buffer[99999];
		FILE* crpt = fopen("___.krpt", "a");

		while (fgets(buffer, 99999, file))
		{
			for (int i = 0; i < 99999 && buffer[i] != '\0'; i++)
			{
				buffer[i] -= key;
			}
			fputs(buffer, crpt);
		}

		fclose(file);
		fclose(crpt);
		remove(filePath);
		remove(keyPath);
		rename("___.krpt", filePath);
	}
}