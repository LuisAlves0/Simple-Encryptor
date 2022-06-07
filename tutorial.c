#include <stdio.h>
#include "src/encryptor.h" // Esse arquivo contém todas as funções da API.

int main()
{
    const char* filePath = "test/archive.txt"; // Caminho até o arquivo que será criptografado.
    const char* keyPath = "test/my.key"; // Caminho até onde você quer que a chave fique.
    int key = 13; // A chave deve ser um valor inteiro.
    key  = GenerateKey(); // Você também pode usar o GenerateKey() que retorna um inteiro aleatório.
    
    // Não use essas próximas funções uma após a outra em um intervalo de tempo curto, e certifique-se de ter um backup do arquivo.
    Encrypt(filePath, keyPath, key); // Criptografa arquivo.
    Decrypt(filePath, keyPath); // Descriptografa arquivo.

    return 0;
}
