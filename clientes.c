//clientes.c

#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Função para adicionar um cliente
void adicionar_cliente(Cliente *clientes, int *qtd_clientes) {
    if (*qtd_clientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    Cliente novo_cliente;

    printf("Nome do cliente: ");
    scanf("%s", novo_cliente.nome);

    printf("Idade do cliente: ");
    scanf("%d", &novo_cliente.idade);

    printf("Genero do cliente: ");
    scanf("%s", novo_cliente.genero);

    printf("Plano de treino do cliente (A/B/C): ");
    scanf("%s", novo_cliente.plano_treino);

    clientes[*qtd_clientes] = novo_cliente;
    (*qtd_clientes)++;

    printf("Cliente adicionado com sucesso!\n");
    printf("*******************************\n");
}

// Função para remover um cliente
void remover_cliente(Cliente *clientes, int *qtd_clientes, const char *nome) {
    int pos = -1;

    for (int i = 0; i < *qtd_clientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    // Remover o cliente e reordenar a lista
    for (int i = pos; i < *qtd_clientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }

    (*qtd_clientes)--;
    printf("Cliente removido com sucesso.\n");
    printf("*****************************\n");
}

// Função para editar um cliente
void editar_cliente(Cliente *clientes, int qtd_clientes, const char *nome) {
    int pos = -1;

    for (int i = 0; i < qtd_clientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    printf("Editar cliente: %s\n", clientes[pos].nome);

    printf("Novo nome do cliente: ");
    scanf("%s", clientes[pos].nome);

    printf("Nova idade do cliente: ");
    scanf("%d", &clientes[pos].idade);

    printf("Novo genero do cliente: ");
    scanf("%s", clientes[pos].genero);

    printf("Novo plano de treino do cliente (A/B/C): ");
    scanf("%s", clientes[pos].plano_treino);

    printf("Cliente editado com sucesso!\n");
    printf("****************************\n");
}

// Função para procurar clientes
void buscar_cliente(Cliente *clientes, int qtd_clientes, Registo *registos, int qtd_registos, int opcao, const char *parametro) {
    int encontrou = 0;

    for (int i = 0; i < qtd_clientes; i++) {
        int presencas = 0;

        // Encontrar as presenças do cliente
        for (int j = 0; j < qtd_registos; j++) {
            if (strcmp(registos[j].nome_cliente, clientes[i].nome) == 0) {
                presencas = registos[j].presencas;
                break;
            }
        }
        if ((opcao == 1 && strcmp(clientes[i].nome, parametro) == 0) ||
            (opcao == 2 && clientes[i].idade == atoi(parametro)) ||
            (opcao == 3 && strcmp(clientes[i].plano_treino, parametro) == 0)) {
            printf("****************************\n");
            printf("Cliente encontrado:\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("Idade: %d\n", clientes[i].idade);
            printf("Genero: %s\n", clientes[i].genero);
            printf("Plano de Treino: %s\n", clientes[i].plano_treino);
            printf("Sessoes Frequentadas: %d\n", presencas);
            printf("****************************\n");
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Cliente nao encontrado.\n");
    }
}
