#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    char *pergunta;
    char *opcoes[4];
    char resposta;
} Pergunta;

void apresentarPergunta(Pergunta pergunta, FILE *arquivo)
{
    char opcao;
    printf("\n%s\n\n", pergunta.pergunta);

    for (int i = 0; i < 4; i++)
    {
        printf("%c) %s\n", 'A' + i, pergunta.opcoes[i]);
    }

    printf("\nSuas respostas serão salvas em um arquivo Excel.\n");
    scanf(" %c", &opcao);

    if (toupper(opcao) == pergunta.resposta)
    {
        fprintf(arquivo, "Questão: %s; Resposta: %c; Status: Acertou\n", pergunta.pergunta, opcao);
    }
    else
    {
        fprintf(arquivo, "Questão: %s; Resposta: %c; Status: Caso não for questínário de qualidade Errou\n", pergunta.pergunta, opcao);
    }
    printf("\n");

}

void questionario(FILE *arquivo, Pergunta perguntas[], int numPerguntas, const char *titulo)
{
    char opcao;
    printf("%s\n", titulo);
    fprintf(arquivo, "%s\n", titulo);

    for (int i = 0; i < numPerguntas; i++)
    {
        apresentarPergunta(perguntas[i], arquivo);
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    printf("Bem-vindo ao Museu Multitemático!\n");
    printf("              _______________  \n");
    printf("             /               \\\n");
    printf("            |  []        []   |\n");
    printf("            |                 |\n");
    printf("            |  []        []   |\n");
    printf("            |_________________|\n");
    printf("            |      MUSEU      |\n");
    printf("            |  MULTITEMÁTICO  |\n");
    printf("            |_________________|\n");
    printf("            |       | |       |\n");
    printf("            |       | |       |\n");
    printf("Escolha uma das opções abaixo:\n\n");
    printf("A. Sugestões e Opiniões sobre Santos Dumont\n");
    printf("1. Prova sobre Santos Dumont\n\n");
    printf("B. Sugestões e Opiniões sobre Jogos Olímpicos\n");
    printf("2. Prova sobre Jogos Olímpicos\n\n");
    printf("C. Sugestões e Opiniões sobre a Semana de Arte Moderna\n");
    printf("3. Prova sobre a Semana de Arte Moderna\n\n");
    printf("D. Sugestões e Opiniões sobre a História do Real ao Bitcoin\n");
    printf("4. Prova sobre a História do Real ao Bitcoin\n\n");

    char escolha;
    scanf("%c", &escolha);

    FILE *arquivo;
    Pergunta perguntas[5];

    if (escolha == '1')
    {
        system("cls");
        arquivo = fopen("SantosDumont.csv", "w");

        Pergunta perguntasSantosDumont[] =
        {
            {
                "1. Qual foi a primeira invenção de Santos Dumont?", {
                    "Balão cilíndrico inflado a hidrogênio.",
                    "Modelo de aeroplano.",
                    "Motor movido por combustível.",
                    "A primeira asa de avião do mundo."
                },
                'A'
            },
            {
                "2. Em qual estado do Brasil nasceu Santos Dumont?", {
                    "Distrito Federal.",
                    "Mato Grosso.",
                    "São Paulo.",
                    "Minas Gerais."
                },
                'D'
            },
            {
                "3. Quais eram as profissões de Dumont?", {
                    "Inventor.",
                    "Cientista.",
                    "Aeronauta e inventor.",
                    "Aeronalta."
                },
                'C'
            },
            {
                "4. Quando foi realizado o primeiro voo do avião 14-Bis?", {
                    "23 de outubro de 1906 em Paris.",
                    "5 de maio de 1907 em Belo Horizonte.",
                    "15 de dezembro de 1903 em Kitty Hawk.",
                    "17 de dezembro de 1903 em Paris."
                },
                'A'
            },
            {
                "5. Com quantos anos morreu Santos Dumont?", {
                    "50 anos.",
                    "59 anos.",
                    "68 anos.",
                    "72 anos."
                },
                'B'
            }
        };

        for (int i = 0; i < 5; i++)
        {
            perguntas[i] = perguntasSantosDumont[i];
        }
    }
    else if (escolha == '2')
    {
        system("cls");
        arquivo = fopen("OlimpiadasParis2024.csv", "w");

        Pergunta perguntasOlimpiadas[] =
        {
            {
                "1. Quais são as duas novas modalidades que entraram nessas edições das Olimpíadas?", {
                    "Skateboarding e escalada esportiva.",
                    "BMX e natação artística.",
                    "Breaking e canoagem slalom extremo.",
                    "Tênis de mesa e esgrima."
                },
                'C'
            },
            {
                "2. Quais os anos em que Paris já foi sede dos Jogos Olímpicos?", {
                    "Nunca foi sede.",
                    "Apenas em 2024.",
                    "1800 e 1920 e agora em 2024.",
                    "1900 e 1924 e agora em 2024."
                },
                'D'
            },
            {
                "3. Quantas modalidades de esporte serão ao todo na edição inteira?", {
                    "O evento terá 58 modalidades e 32 esportes.",
                    "O evento terá 8 modalidades e 2 esportes.",
                    "O evento terá 48 modalidades e 32 esportes.",
                    "O evento terá 48 modalidades e 22 esportes."
                },
                'C'
            },
            {
                "4. Qual o nome do mascote desta edição?", {
                    "Phryges.",
                    "Bolinha.",
                    "Willie.",
                    "Footix."
                },
                'A'
            },
            {
                "5. Em qual dia será a abertura dos jogos?", {
                    "27 de julho.",
                    "26 de julho.",
                    "30 de janeiro.",
                    "31 de abril."
                },
                'B'
            }
        };

        for (int i = 0; i < 5; i++)
        {
            perguntas[i] = perguntasOlimpiadas[i];
        }

    }
    else if (escolha == '3')
    {
        system("cls");
        arquivo = fopen("SemanadeArteModerna.csv", "w");

        Pergunta perguntasArteModerna[] =
        {
            {
                "1. Qual foi o principal motivo da Semana da Arte Moderna?", {
                    "Criar uma identidade nacional dentro da arte brasileira.",
                    "Melhorar a arte brasileira.",
                    "O governo queria competir com indústrias de cinema estrangeiras.",
                    "Nenhuma das anteriores."
                },
                'A'
            },
            {
                "2. O que foi o Centenário da Arte Moderna de 1922?", {
                    "Intelectuais e a elite cafeicultora paulista se reuniram para romper os padrões artísticos.",
                    "Muitos artistas pouco reconhecidos se reuniram para fazer arte independente.",
                    "Estavam tentando desenvolver um Hollywood brasileiro.",
                    "Todas as anteriores."
                },
                'A'
            },
            {
                "3. Como a arte moderna chegou ao Brasil?", {
                    "Muitos artistas estrangeiros trouxeram artes exclusivas de suas terras.",
                    "Na verdade, era o Brasil que estava exportando arte.",
                    "Após as vanguardas europeias, na década de 20, com a Semana de Arte Moderna.",
                    "O Brasil estava procurando novos artistas para retratar o novo planalto."
                },
                'C'
            },
            {
                "4. Quais são as obras que marcaram o modernismo?", {
                    "Tarsila do Amaral: Abaporu (1928), Antropofagia (1929), Operários (1933).",
                    "Anita Malfatti: O homem amarelo (1915), A estudante (1915), O japonês (1915).",
                    "Oswald de Andrade: Manifesto Antropófago (1928), Serafim Ponte Grande (1933), Marco Zero (1943).",
                    "Cândido Portinari: Café (1935), O lavrador de café (1934), Guarani (1942)."
                },
                'A'
            },
            {
                "5. O que marcou a arte moderna no Brasil?", {
                    "O movimento Antropofágico, que propunha a incorporação e transformação de influências estrangeiras na arte brasileira.",
                    "A Semana de Arte Moderna de 1922, que trouxe uma ruptura com os padrões artísticos tradicionais.",
                    "A valorização da cultura popular e regional, com destaque para o folclore brasileiro.",
                    "A influência das vanguardas europeias, como o Cubismo e o Surrealismo, na produção artística brasileira."
                },
                'B'
            }
        };

        for (int i = 0; i < 5; i++)
        {
            perguntas[i] = perguntasArteModerna[i];
        }
    }
    else if (escolha == '4')
    {
        system("cls");
        arquivo = fopen("Real_Bitcoin.csv", "w");

        Pergunta perguntasBitcoin[] =
        {
            {
                "1. O que é o bitcoin?", {
                    "Uma criptomoeda descentralizada",
                    "Uma forma de pagamento como o pix",
                    "Uma forma de investimento",
                    "nenhuma das anteriores"
                },
                'A'
            },
            {
                "2. Quem criou o bitcoin e quando?", {
                    "Satoshi Nakamoto em 2008",
                    "Presidente da casa branca em 2008",
                    "Joel Biden em 2005",
                    "Lula em 2008"
                },
                'A'
            },
            {
                "3. Como as transações do bitcoin são registradas?", {
                    "Não há registro de transações no bitcoin.",
                    "Por meio de registros em bancos de dados centralizados.",
                    "As transações são registradas em um livro razão chamado blockchain.",
                    "Não há registro de transações no bitcoin."
                },
                'C'
            },
            {
                "4. Qual é a principal diferença do real para o bitcoin?", {
                    "O real é uma moeda regulamentada pelo governo, enquanto o bitcoin é uma moeda descentralizada.",
                    "O real é digital, mas o bitcoin é uma moeda física.",
                    "O real é mais seguro para transações online do que o bitcoin.",
                    "O real não pode ser usado para compras online."
                },
                'A'
            },
            {
                "5. Onde posso armazenar meus bitcoins?", {
                    "Em um cofre de um banco físico.",
                    "Em uma carteira virtual (wallet).",
                    "Em uma conta de banco tradicional.",
                    "Em um cartão de crédito."
                },
                'B'
            }
        };

        for (int i = 0; i < 5; i++)
        {
            perguntas[i] = perguntasBitcoin[i];
        }
    }

    else if (escolha == 'A' || escolha == 'a')
    {
        system("cls");
        arquivo = fopen("Qualidade_Santos.csv", "w");

        Pergunta perguntasQSantos[] =
        {
            {
                "1. Quais materiais Santos Dumont usou para construir o 14 Bis?", {
                    "14 Bis: Bambu, alumínio, 1 pessoa, 160kg, 30,8 km/h.",
                    "Cesta de balão para o piloto.",
                    "Rodas de bicicletas",
                    "10m comprimento, 4,8m altura, 160kg, 30,8 km/h"
                },
                'A'
            },
            {
                "2. Interatividade com o Software nas Exposicoes:", {
                    "INCRIVEL",
                    "BOA",
                    "RAZOAVEL",
                    "INSATISFATORIA"
                },
            },
            {
                "3. O software nas exposicoes facilitou sua interacao com as obras?", {
                    "SIM",
                    "NAO",
                    "TALVEZ",
                    "NAO VI NECESSIDADE"
                },
            },
            {
                "4. Qualidade do Software Desenvolvido em Linguagem C", {
                    "BOA",
                    "RAZOAVEL",
                    "RUIM",
                    "PESSIMA"
                },
            },
            {
                "5. Voce sentiu que contribuiu para o aprendizado ao interagir com o software no museu?", {
                    "CONCERTEZA",
                    "SIM",
                    "TALVEZ",
                    "NAO"
                },
            }
        };

        for (int i = 0; i < 5; i++)
        {
            perguntas[i] = perguntasQSantos[i];
        }
    }

    else if (escolha == 'B' || escolha == 'b')
    {
        system("cls");
        arquivo = fopen("Qualidade_paris24.csv", "w");

        Pergunta perguntasQparis24[] =
        {
            {
                "1. Qual são os dois esportes novos dessa olimpíadas?", {
                    "Breaking e canoagem slalom extremo",
                    "Basquete",
                    "Capoeira",
                    "volei"
                },
                'A'
            },
            {
                "2. Interatividade com o Software nas Exposicoes:", {
                    "INCRIVEL",
                    "BOA",
                    "RAZOAVEL",
                    "INSATISFATORIA"
                },
            },
            {
                "3. O software nas exposicoes facilitou sua interacao com as obras?", {
                    "SIM",
                    "NAO",
                    "TALVEZ",
                    "NAO VI NECESSIDADE"
                },
            },
            {
                "4. Qualidade do Software Desenvolvido em Linguagem C", {
                    "BOA",
                    "RAZOAVEL",
                    "RUIM",
                    "PESSIMA"
                },
            },
            {
                "5. Voce sentiu que contribuiu para o aprendizado ao interagir com o software no museu?", {
                    "CONCERTEZA",
                    "SIM",
                    "TALVEZ",
                    "NAO"
                },
            }
        };

        for (int i = 0; i < 5; i++)
        {
            perguntas[i] = perguntasQparis24[i];
        }
    }

    else if (escolha == 'C' || escolha == 'c')
    {
        system("cls");
        arquivo = fopen("Qualidade_artemoderna.csv", "w");

        Pergunta perguntasQartemoderna[] =
        {
            {
                "1. O que representa os 100 anos da arte moderna?", {
                    "Em fevereiro de 1922, artistas se reuniram em um evento onde gerou uma inovação intelectual no Brasil.",
                    "Inovação",
                    "Aumento no preço das artes brasileiras",
                    "Padronizar o estilo de arte mundial"
                },
                'A'
            },
            {
                "2. Interatividade com o Software nas Exposicoes:", {
                    "INCRIVEL",
                    "BOA",
                    "RAZOAVEL",
                    "INSATISFATORIA"
                },
            },
            {
                "3. O software nas exposicoes facilitou sua interacao com as obras?", {
                    "SIM",
                    "NAO",
                    "TALVEZ",
                    "NAO VI NECESSIDADE"
                },
            },
            {
                "4. Qualidade do Software Desenvolvido em Linguagem C", {
                    "BOA",
                    "RAZOAVEL",
                    "RUIM",
                    "PESSIMA"
                },
            },
            {
                "5. Voce sentiu que contribuiu para o aprendizado ao interagir com o software no museu?", {
                    "CONCERTEZA",
                    "SIM",
                    "TALVEZ",
                    "NAO"
                },
            }
        };

        for (int i = 0; i < 5; i++)
        {
            perguntas[i] = perguntasQartemoderna[i];
        }

    }

    else if (escolha == 'D' || escolha == 'd')
    {
        system("cls");
        arquivo = fopen("Qualidade_RealBitcoin.csv", "w");

        Pergunta perguntasQRealBitcoin[] =
        {
            {
                "1. Onde posso armazenar meus bitcoins?", {
                    "Em um cofre de um banco físico.",
                    "Em uma carteira virtual (wallet).",
                    "Em uma conta de banco tradicional.",
                    "Em um cartão de crédito."
                },
                'A'
            },
            {
                "2. Interatividade com o Software nas Exposicoes:", {
                    "INCRIVEL",
                    "BOA",
                    "RAZOAVEL",
                    "INSATISFATORIA"
                },
            },
            {
                "3. O software nas exposicoes facilitou sua interacao com as obras?", {
                    "SIM",
                    "NAO",
                    "TALVEZ",
                    "NAO VI NECESSIDADE"
                },
            },
            {
                "4. Qualidade do Software Desenvolvido em Linguagem C", {
                    "BOA",
                    "RAZOAVEL",
                    "RUIM",
                    "PESSIMA"
                },
            },
            {
                "5. Voce sentiu que contribuiu para o aprendizado ao interagir com o software no museu?", {
                    "CONCERTEZA",
                    "SIM",
                    "TALVEZ",
                    "NAO"
                },
            }
        };

        for (int i = 0; i < 5; i++)
        {
            perguntas[i] = perguntasQRealBitcoin[i];
        }


    }
    else
    {
        printf("Opção inválida.\n");
        return 1;
    }

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    const char *titulo = (escolha == '1') ? "\nQuestionário Santos Dumont\n" :
                         (escolha == '2') ? "\nQuestionário Olimpíadas Paris 2024\n" :
                         (escolha == '3') ? "\nQuestionário Semana de Arte Moderna\n" :
                         (escolha == '4') ? "\nQuestionário Do real ao bitcoin\n" :
                         (escolha == 'A' || escolha == 'a') ? "\nQualidade Santos Dumont\n" :
                         (escolha == 'B' || escolha == 'b') ? "\nQualidade Olimpíadas Paris 2024\n" :
                         (escolha == 'C' || escolha == 'c') ? "\nQualidade Semana de Arte Moderna\n" :
                         (escolha == 'D' || escolha == 'd') ? "\nQualidade Do real ao bitcoin\n" : "";


    questionario(arquivo, perguntas, 5, titulo);

    fclose(arquivo);
    return 0;
}
