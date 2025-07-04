#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO_LETRAS_OCULTAS 3

void digitar_palavra(char *palavra);
void preencher_arrays_underline(char *tentativa, char *certas, int tamanho);
void verificar_acerto_letra(int tamanho, char *palavra, char letra, char *letras_certas, int *total_acertos, char *letras_tentativa, int *total_erros);
void verificar_acerto_palavra(char *palavra, char *tentativa);
void loop_digitacao(int tamanho, char *palavra, char letra, char *letras_certas, int *total_acertos, char *letras_tentativa, int *total_erros);

int main()
{
    char palavra[20], letras_tentativa[20], letras_certas[20], letra;
    int total_acertos = 0, total_erros = 0;

    digitar_palavra(palavra);

    int tamanho = strlen(palavra);

    preencher_arrays_underline(letras_tentativa, letras_certas, tamanho);

    loop_digitacao(tamanho, palavra,  letra,  letras_certas,  &total_acertos,  letras_tentativa,  &total_erros);

    printf("Digite a palavra completa:\n");
    scanf("%s", letras_tentativa);

    verificar_acerto_palavra(palavra, letras_tentativa);

    return 0;
}

void digitar_palavra(char *palavra)
{
    printf("Digite a palavra secreta (sem acento e sem espaço):\n");
    scanf("%s", palavra);
    system("cls || clear");
}

void preencher_arrays_underline(char *tentativa, char *certas, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        certas[i] = '_';
        tentativa[i] = '_';
    }
    certas[tamanho] = '\0';
    tentativa[tamanho] = '\0';
}

void verificar_acerto_palavra(char *palavra, char *tentativa){
    if (strcmp(palavra, tentativa) == 0)
    {
        printf("Você acertou!\n");
    }
    else
    {
        printf("Você não acertou!\n");
        printf("A palavra era: %s\n", palavra);
    }
}


void verificar_acerto_letra(int tamanho, char *palavra, char letra, char *letras_certas, int *total_acertos, char *letras_tentativa, int *total_erros){
        int acertou = 0;
        for (int i = 0; i < tamanho; i++)
        {
            if (palavra[i] == letra && letras_certas[i] == '_')
            {
                letras_certas[i] = letra;
                (*total_acertos)++;
                acertou = 1;
            }
        }

        if (!acertou)
        {
            letras_tentativa[*total_erros] = letra;
            (*total_erros)++;
        }   
}


void loop_digitacao(int tamanho, char *palavra, char letra, char *letras_certas, int *total_acertos, char *letras_tentativa, int *total_erros){
    while ((*total_erros) < tamanho && (tamanho - *total_acertos) > MAXIMO_LETRAS_OCULTAS)
    {
        printf("Digite uma letra:\n");
        scanf(" %c", &letra);

        verificar_acerto_letra(tamanho, palavra, letra, letras_certas, total_acertos, letras_tentativa, total_erros);

        printf("Palavra: %s\n", letras_certas);
        printf("Erros: %s\n\n", letras_tentativa);
    }
}
    
