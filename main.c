//*******************************************
//*****       UNIVERSIDADE ABERTA       *****
//Disciplina: Laboratório de Programação
//Professor: Nelson Russo
//Aluno: Alexandre Soares, nr: 2101521
//*******************************************
//*******************************************
// AF2 - Enunciado B - Academia

//main.c

#include <stdio.h>;
#include "config.h"
#include "clientes.h"
#include "registos.h"
#include "pagamento.h"
#include "relatorios.h"
#include "csv.h"


void mostrar_menu() {
    printf("Menu Principal:\n");
    printf("1 - Adicionar cliente\n");
    printf("2 - Remover cliente\n");
    printf("3 - Editar cliente\n");
    printf("4 - Pesquisar Cliente\n");
    printf("5 - Registos\n");
    printf("6 - Relatorios\n");
    printf("0 - Sair\n");
}

void submenu_pesquisar() {
    printf("Pesquisar Cliente:\n");
    printf("1 - Por Nome\n");
    printf("2 - Por Idade\n");
    printf("3 - Por Plano de Treino\n");
}

void submenu_registos() {
    printf("Menu de Registos:\n");
    printf("1 - Registar presenca\n");
    printf("2 - Sessoes frequentadas\n");
    printf("3 - Pagamento\n");
    printf("0 - Voltar ao menu principal\n");
}

void submenu_relatorios() {
    printf("Menu de Relatorios:\n");
    printf("1 - Planos preferidos dos clientes\n");
    printf("2 - Clientes com maior numero de sessoes/presencas\n");
    printf("3 - Clientes com mais sessoes do que o plano\n");
    printf("0 - Voltar ao menu principal\n");
}

int main() {
    Cliente clientes[MAX_CLIENTES];
    Registo registos[MAX_REGISTOS];
    int qtd_clientes = 0;
    int qtd_registos = 0;

    // Carregar dados dos clientes do arquivo CSV ao iniciar
    ler_clientes_csv(clientes, &qtd_clientes);

    // Carregar registos de presença do arquivo CSV ao iniciar
    ler_registos_csv(registos, &qtd_registos);

    int opcao_principal;
    int opcao_submenu;

    do {
        mostrar_menu();
        scanf("%d", &opcao_principal);

        switch (opcao_principal) {
            case 1:
                adicionar_cliente(clientes, &qtd_clientes);
                salvar_clientes_csv(clientes, qtd_clientes); // Salvar alterações
                break;
            case 2:
                printf("Nome do cliente para remover: ");
                char nome_remover[100];
                scanf("%s", nome_remover);
                remover_cliente(clientes, &qtd_clientes, nome_remover);
                salvar_clientes_csv(clientes, qtd_clientes); // Salvar alterações
                break;
            case 3:
                printf("Nome do cliente para editar: ");
                char nome_editar[100];
                scanf("%s", nome_editar);
                editar_cliente(clientes, qtd_clientes, nome_editar);
                salvar_clientes_csv(clientes, qtd_clientes); // Salvar alterações
                break;
            case 4:
                submenu_pesquisar();
                scanf("%d", &opcao_submenu);
                printf("Informe o parametro de pesquisa: ");
                char parametro[100];
                scanf("%s", parametro);
                buscar_cliente(clientes, qtd_clientes,registos,qtd_registos, opcao_submenu, parametro);
                break;
            case 5:
                submenu_registos();
                scanf("%d", &opcao_submenu);
                switch (opcao_submenu) {
                    case 1:
                        printf("Nome do cliente para registrar presença: ");
                        char nome_registar[100];
                        scanf(" %[^\n]", nome_registar); // Para capturar nomes compostos
                        registar_presenca(registos, &qtd_registos, clientes, qtd_clientes, nome_registar);
                        salvar_registos_csv(registos, qtd_registos); // Salvar alterações
                        break;
                    case 2:
                        mostrar_sessoes_frequentadas(registos, qtd_registos);
                        break;
                    case 3:
                        calcular_pagamento(clientes, qtd_clientes, registos, qtd_registos);
                        break;
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }
                break;
            case 6:
                submenu_relatorios();
                scanf("%d", &opcao_submenu);
                switch (opcao_submenu) {
                    case 1:
                        mostrar_planos_preferidos(clientes, qtd_clientes);
                        break;
                    case 2:
                        mostrar_clientes_com_mais_presencas(registos, qtd_registos);
                        break;
                    case 3:
                        mostrar_clientes_com_mais_sessoes_que_plano(clientes, registos, qtd_clientes, qtd_registos);
                        break;
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao_principal != 0);

    return 0;
}
