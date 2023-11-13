#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define Psanto 10.0
#define Pjogos 15.0
#define Parte 20.0
#define Pbit 30.0
#define SENHA_CORRETA "banana"

FILE *csv_file; // Declaração global
FILE *binario_file; // Declaração global
int vendas();
int main();

int main()
{
    FILE *csv_file = fopen("relatorio_vendas.csv", "a");
    char senha[20];
    printf("Digite a senha:\n");
    scanf("%s", senha);

    csv_file = fopen("relatorio_vendas.csv", "a"); //Arquivo CSV
    binario_file = fopen("relatorio_vendas.bin", "ab"); //Arquivo binario

    if (csv_file == NULL && binario_file == NULL)
    {
        printf("Erro ao criar o arquivo CSV e BIN.\n");
    }
    else
    {
        if (strcmp(senha, SENHA_CORRETA) == 0)
        {
            vendas();
        }
        else
        {
            printf("Acesso negado\n");
        }
    }

    fclose(csv_file);
    fclose(binario_file);

    return 4;
}

int vendas()
{
    extern FILE *csv_file;
    extern FILE *binario_file;
    setlocale(LC_ALL, "portuguese");
    int Esanto = 0, Ejogos = 0, Earte = 0, Ebit = 0;
    int inteiras = 0, meias = 0, isentas = 0;
    int ultima_venda_opcao = 0; // Armazena a opção da última venda
    int idade;
    char meia;
    float total_arrecadado = 0.0;
    float Dsanto = 0.0, Djogos = 0.0, Darte = 0.0, Dbit = 0.0;  // Declare as variáveis aqui

    printf("Bem-vindo ao Museu Multitemático!!!\n");
    printf("   ______________________________  \n");
    printf("  /                             /\\ \n");
    printf(" /_____________________________/  \\ \n");
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
    system("pause");
    system("cls");

    while (1)
    {
        int opcao;
        int opcao_anterior = 0;
        printf("\nEscolha a opção:\n\n");
        printf("   1. Santos Dumont (R$ %.2f)\n\n", Psanto);
        printf("   2. Jogos Olímpicos de Paris 2024 (R$ %.2f)\n\n", Pjogos);
        printf("   3. 100 anos da Semana de Arte Moderna (R$ %.2f)\n\n", Parte);
        printf("   4. História do real ao bitcoin (R$ %.2f)\n\n", Pbit);
        printf("9. Encerrar venda\n");
        printf("10. Cancelar venda\n");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            // Verificação de direito à meia-entrada
            printf("\nPossui direito à meia-entrada? Digite 's' se sim, ou qualquer outro caractere se não:");
            scanf(" %c", &meia); // Utilize %c para ler um caractere

            // Coleta da idade do cliente
            printf("\nDigite sua idade:");
            scanf("%d", &idade);

            if (idade <= 10)
            {
                Esanto++;
                isentas++;
                opcao_anterior = 1;
                printf("\nIsento\n");
            }
            else if (meia == 's' || meia == 'S') // Use == para comparação, não =
            {
                // Entrada meia
                Esanto++;
                meias++;
                total_arrecadado += Psanto / 2.0; // Meia entrada
                Dsanto += Psanto / 2.0;
                opcao_anterior = 1;
                printf("\nCompra efetuada com meia entrada\n");
            }
            else
            {
                Esanto++;
                inteiras++;
                total_arrecadado += Psanto;
                Dsanto += Psanto;
                opcao_anterior = 1;
                printf("\nCompra efetuada\n");
            }

            ultima_venda_opcao = 1; // Armazena a opção da última venda
            system("pause");
            system("cls");

        }
        else if (opcao == 2)
        {
            // Verificação de direito à meia-entrada
            printf("\nPossui direito à meia-entrada? Digite 's' se sim, ou qualquer outro caractere se não:");
            scanf(" %c", &meia); // Utilize %c para ler um caractere

            // Coleta da idade do cliente
            printf("\nDigite sua idade:");
            scanf("%d", &idade);

            if (idade <= 10)
            {
                Ejogos++;
                isentas++;
                opcao_anterior = 1;
                printf("\nIsento\n");
            }
            else if (meia == 's' || meia == 'S')
            {
                // Entrada meia
                Ejogos++;
                meias++;
                total_arrecadado += Pjogos / 2.0; // Meia entrada
                Djogos += Pjogos / 2.0;
                opcao_anterior = 1;
                printf("\nCompra efetuada com meia entrada\n");
            }
            else
            {
                Ejogos++;
                inteiras++;
                total_arrecadado += Pjogos;
                Djogos += Pjogos;
                opcao_anterior = 1;
                printf("\nCompra efetuada\n");
            }

            ultima_venda_opcao = 2; // Armazena a opção da última venda
            system("pause");
            system("cls");
        }
        else if (opcao == 3)
        {

            // Verificação de direito à meia-entrada
            printf("\nPossui direito à meia-entrada? Digite 's' se sim, ou qualquer outro caractere se não:");
            scanf(" %c", &meia);

            // Coleta da idade do cliente
            printf("\nDigite sua idade:");
            scanf("%d", &idade);

            if (idade <= 10)
            {
                Earte++;
                isentas++;
                opcao_anterior = 1;
                printf("\nIsento\n");
            }
            else if (meia == 's' || meia == 'S')
            {
                // Entrada meia
                Earte++;
                meias++;
                total_arrecadado += Parte / 2.0; // Meia entrada
                Darte += Parte / 2.0;
                opcao_anterior = 1;
                printf("\nCompra efetuada com meia entrada\n");
            }
            else
            {
                Earte++;
                inteiras++;
                total_arrecadado += Parte;
                Darte += Parte;
                opcao_anterior = 1;
                printf("\nCompra efetuada\n");
            }

            ultima_venda_opcao = 3; // Armazena a opção da última venda
            system("pause");
            system("cls");
        }
        else if (opcao == 4)
        {
            // Verificação de direito à meia-entrada
            printf("\nPossui direito à meia-entrada? Digite 's' se sim, ou qualquer outro caractere se não:");
            scanf(" %c", &meia);

            // Coleta da idade do cliente
            printf("\nDigite sua idade:");
            scanf("%d", &idade);

            if (idade <= 10)
            {
                Ebit++;
                isentas++;
                opcao_anterior = 1;
                printf("\nIsento\n");
            }
            else if (meia == 's' || meia == 'S')
            {
                // Entrada meia
                Ebit++;
                meias++;
                total_arrecadado += Pbit / 2.0; // Meia entrada
                Dbit += Pbit / 2.0;
                opcao_anterior = 1;
                printf("\nCompra efetuada com meia entrada\n");
            }
            else
            {
                Ebit++;
                inteiras++;
                total_arrecadado += Pbit;
                Dbit += Pbit;
                opcao_anterior = 1;
                printf("\nCompra efetuada\n");
            }

            ultima_venda_opcao = 4; // Armazena a opção da última venda
            system("pause");
            system("cls");
        }
        else if (opcao == 9)
        {
            break; // Encerra a venda
        }
        else if (opcao == 10)
        {

// Cancelar a última venda

            if (ultima_venda_opcao == 1)
            {
                if (idade < 10)
                {
                    // Se a entrada era isenta, não subtrai do total_arrecadado
                    Esanto--;
                    isentas--;
                    printf("\nVenda cancelada (entrada isenta)\n");
                }
                else if (opcao_anterior == 1)
                {
                    // Se a entrada era meia, subtrai do total_arrecadado
                    Esanto--;
                    meias--;
                    total_arrecadado -= (Psanto / 2);
                    Dsanto -= Psanto / 2.0;
                    printf("\nVenda cancelada (meia entrada)\n");
                }
                else
                {
                    Esanto--;
                    inteiras--;
                    total_arrecadado -= Psanto;
                    Dsanto -= Psanto;
                    printf("\nVenda cancelada\n");
                }
                system("pause");
                system("cls");
            }
            else if (ultima_venda_opcao == 2)
            {
                if (idade < 10)
                {
                    // Se a entrada era isenta, não subtrai do total_arrecadado
                    Ejogos--;
                    isentas--;
                    printf("\nVenda cancelada (entrada isenta)\n");
                }
                else if (opcao_anterior == 1)
                {
                    // Se a entrada era meia, subtrai do total_arrecadado
                    Ejogos--;
                    meias--;
                    total_arrecadado -= (Pjogos / 2);
                    Djogos -= Pjogos / 2.0;
                    printf("\nVenda cancelada (meia entrada)\n");
                }
                else
                {
                    Ejogos--;
                    inteiras--;
                    total_arrecadado -= Pjogos;
                    Djogos -= Pjogos;
                    printf("\nVenda cancelada\n");
                }
                system("pause");
                system("cls");
            }
            else if (ultima_venda_opcao == 3)
            {
                if (idade < 10)
                {
                    // Se a entrada era isenta, não subtrai do total_arrecadado
                    Earte--;
                    isentas--;
                    printf("\nVenda cancelada (entrada isenta)\n");
                }
                else if (opcao_anterior == 1)
                {
                    // Se a entrada era meia, subtrai do total_arrecadado
                    Earte--;
                    meias--;
                    total_arrecadado -= (Parte / 2);
                    Darte -= Parte / 2.0;
                    printf("\nVenda cancelada (meia entrada)\n");
                }
                else
                {
                    Earte--;
                    inteiras--;
                    total_arrecadado -= Parte;
                    Darte -= Parte;
                    printf("\nVenda cancelada\n");
                }
                system("pause");
                system("cls");
            }
            else if (ultima_venda_opcao == 4)
            {
                if (idade < 10)
                {
                    // Se a entrada era isenta, não subtrai do total_arrecadado
                    Ebit--;
                    isentas--;
                    printf("\nVenda cancelada (entrada isenta)\n");
                }
                else if (opcao_anterior == 1)
                {
                    // Se a entrada era meia, subtrai do total_arrecadado
                    Ebit--;
                    meias--;
                    total_arrecadado -= (Pbit / 2);
                    Dbit -= Pbit / 2.0;
                    printf("\nVenda cancelada (meia entrada)\n");
                }
                else
                {
                    Ebit--;
                    inteiras--;
                    total_arrecadado -= Pbit;
                    Dbit -= Pbit;
                    printf("\nVenda cancelada\n");
                }
                system("pause");
                system("cls");
            }
            else
            {
                printf("\nNenhuma venda anterior para cancelar.\n");
                system("pause");
                system("cls");
            }
        }
        else
        {
            printf("\nOpção inválida! Escolha novamente.\n");
            system("pause");
            system("cls");
        }
    }
    printf("\nRelatório de Vendas:\n");
    printf("Entradas para Santos Dumont: %d\n", Esanto);
    printf("Entradas para Jogos Olímpicos Paris 2024: %d\n", Ejogos);
    printf("Entradas para 100 anos da Semana de Arte Moderna: %d\n", Earte);
    printf("Entradas para História do real ao bitcoin: %d\n", Ebit);
    printf("Total Arrecadado Aproximado: R$ %.2f\n", total_arrecadado);
    printf("inteiras: %d meias: %d isentas: %d\n", inteiras, meias, isentas);
    csv_file = fopen("relatorio_vendas.csv", "a");
    if (csv_file == NULL)
    {
        printf("Erro ao criar o arquivo CSV.\n");
        return 1;
    }
    fprintf(csv_file, "\nTEMA EXPOSIÇÃO; ENTRADAS; VALOR TOTAL\n");
    fprintf(csv_file, "Santos Dumont; Pessoas: %d; Dinheiro: R$ %.2f\n", Esanto, Dsanto);
    fprintf(csv_file, "Jogos Olímpicos Paris 2024; Pessoas: %d; Dinheiro: R$ %.2f\n", Ejogos, Djogos);
    fprintf(csv_file, "100 anos da Semana de Arte Moderna; Pessoas: %d; Dinheiro: R$ %.2f\n", Earte, Darte);
    fprintf(csv_file, "História do real ao bitcoin; Pessoas: %d; Dinheiro: R$ %.2f\n", Ebit, Dbit);
    fprintf(csv_file, "Total Arrecadado Aproximado:; R$ %.2f\n", total_arrecadado);
    fprintf(csv_file, "inteiras: %d; meias: %d; isentas: %d\n", inteiras, meias, isentas);
    fclose(csv_file);
    if (binario_file == NULL)
    {
        printf("Erro ao criar o arquivo CSV.\n");
        return 1;
    }
    fwrite(&Esanto, sizeof(int), 1, binario_file);
    fwrite(&Ejogos, sizeof(int), 1, binario_file);
    fwrite(&Earte, sizeof(int), 1, binario_file);
    fwrite(&Ebit, sizeof(int), 1, binario_file);
    fwrite(&Dsanto, sizeof(float), 1, binario_file);
    fwrite(&Djogos, sizeof(float), 1, binario_file);
    fwrite(&Darte, sizeof(float), 1, binario_file);
    fwrite(&Dbit, sizeof(float), 1, binario_file);
    fwrite(&total_arrecadado, sizeof(float), 1, binario_file);
    fwrite(&inteiras, sizeof(int), 1, binario_file);
    fwrite(&meias, sizeof(int), 1, binario_file);
    fwrite(&isentas, sizeof(int), 1, binario_file);
    fclose(binario_file);
    printf("\nDados exportados para o arquivo 'relatorio_vendas.csv' e 'relatorio_vendas.bin'.\n\n");
    printf("  ****  ****  \n");
    printf(" ****** ***** \n");
    printf("  *********** \n");
    printf("   *********  \n");
    printf("    *******   \n");
    printf("     *****    \n");
    printf("      ***     \n");
    printf("       *      \n");

    return 0;
}
