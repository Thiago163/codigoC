#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 100
#define NUM_PERGUNTAS 8
#define TAM 900
#define SENHA_CORRETA "banana"

typedef struct
{
    char pergunta[TAM];
    char opcoes[4][MAX_CHAR];
    char resposta;
} Pergunta;

void apresentarPergunta(Pergunta pergunta, FILE *arquivo, FILE *binario, int numeroQuestao)
{
    char opcao;
    printf("\nQuestão %d:\n%s\n", numeroQuestao, pergunta.pergunta);

    for (int i = 0; i < 4; i++)
    {
        printf("%c) %s\n", 'A' + i, pergunta.opcoes[i]);
    }

    // Obter resposta do usuário
    printf("Sua resposta (A, B, C ou D, ou # para parar): ");
    scanf(" %c", &opcao);

    // Verificar se foi digitado #
    if (opcao == '#')
    {
        char continuar;
        printf("Deseja continuar respondendo perguntas? (S/N): ");
        scanf(" %c", &continuar);

        // Converter para maiúsculas para facilitar a comparação
        continuar = toupper(continuar);

        // Se não deseja continuar, verificar a senha
        if (continuar != 'S')
        {
            char senha[20];

            printf("Digite a senha para encerrar o programa: ");
            scanf("%s", senha);

            // Verificar a senha
            if (strcmp(senha, SENHA_CORRETA) == 0)
            {
                exit(0); // Encerrar o programa
            }
            else
            {
                printf("Senha incorreta. Continuando...\n");
            }
        }
    }

    // Armazenar no arquivo CSV
    fprintf(arquivo, "Questão %d; Resposta:; %c;\n", numeroQuestao, opcao);

    // Armazenar no arquivo binário
    fwrite(&numeroQuestao, sizeof(int), 1, binario);
    fwrite(&opcao, sizeof(char), 1, binario);

    printf("\n");
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *arquivo, *binario;
    Pergunta perguntas[NUM_PERGUNTAS];

    do
    {
        arquivo = fopen("respostas.csv", "a");
        binario = fopen("binario.bin", "ab");

        if (arquivo == NULL || binario == NULL)
        {
            perror("Erro ao abrir o arquivo de saída");
            return 1;
        }

        FILE *perguntasFile = fopen("perguntas.txt", "r");
        if (perguntasFile == NULL)
        {
            perror("Erro ao abrir o arquivo de perguntas");
            fclose(arquivo);
            fclose(binario);
            return 1;
        }

        // Iterar sobre as perguntas
        for (int i = 0; i < NUM_PERGUNTAS; i++)
        {
            // Ler texto da pergunta
            fscanf(perguntasFile, " %[^\n]%*c", perguntas[i].pergunta);

            // Ler opções de resposta
            for (int j = 0; j < 4; j++)
            {
                fscanf(perguntasFile, " %[^\n]%*c", perguntas[i].opcoes[j]);
            }

            // Ler resposta correta
            fscanf(perguntasFile, " %c%*c", &perguntas[i].resposta);
        }

        for (int i = 0; i < NUM_PERGUNTAS; i++)
        {
            printf("Bem-vindo ao Museu Multitemático!!! \n");
            printf("   ______________________________   \n");
            printf("  /                             /\\ \n");
            printf(" /_____________________________/  \\\n");
            printf("|                              |   |\n");
            printf("|  [ ]                    [ ]  |   |\n");
            printf("|              [ ]             |   |\n");
            printf("|  [ ]                    [ ]  |   |\n");
            printf("|              [ ]             |   |\n");
            printf("|  [ ]                    [ ]  |   |\n");
            printf("|______________________________|   |\n");
            printf("|          MUSEU               |   |\n");
            printf("|       MULTITEMATICO          |   |\n");
            printf("|______________________________|   |\n");
            printf("|          |    | |            |   |\n");
            printf("|          |    | |            |   |\n");
            printf("|__________|____|_|____________|___|\n\n");
            apresentarPergunta(perguntas[i], arquivo, binario, i + 1);
            system("pause");
            system("cls");
        }

        // Adicionar uma quebra de linha no final de cada conjunto de respostas
        fprintf(arquivo, "\n");

        // Fechar arquivos
        fclose(arquivo);
        fclose(binario);
        fclose(perguntasFile);

        system("cls");
        printf("\nDados exportados para o arquivo 'relatorio_vendas.csv' e 'relatorio_vendas.bin'.\n\n");
        printf("  ****  ****  \n");
        printf(" ****** ***** \n");
        printf("  *********** \n");
        printf("   *********  \n");
        printf("    *******   \n");
        printf("     *****    \n");
        printf("      ***     \n");
        printf("       *      \n\n");
        system("pause");
        system("cls");

    } while (1);

    return 0;
}
