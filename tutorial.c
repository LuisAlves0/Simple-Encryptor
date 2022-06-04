#include <stdio.h>
#include "src/KrowKrypt.h" // Esse arquivo contém todas as funções da API

int main()
{
    const char* filePath = "teste/arquivo.txt"; // Caminho até o arquivo que será criptografado
    const char* keyPath = "teste/minha.chave"; // Caminho até onde você quer que a chave fique
    int key = 13; // A chave deve ser um valor inteiro.
    key  = GenerateKey(); // Você também pode usar o GenerateKey() que retorna um inteiro aleatório

    Encrypt(filePath, keyPath, key); // Criptografa arquivo
    Decrypt(filePath, keyPath); // Descriptografa arquivo

    return 0;
}
