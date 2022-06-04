#pragma once

// Gera uma chave aleatória...
int GenerateKey();

// Gera um arquivo com uma chave gravada...
int SetKey(const char* keyPath, int key);

// Retorna chave gravada no arquivo de chave...
int GetKey(const char* keyPath);