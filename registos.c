//registos.c

#include "registos.h"
#include <stdio.h>
#include <string.h>

// Registra a presença de um cliente, validando se o cliente existe
void registar_presenca(Registo *registos, int *qtd_registos, const Cliente *clientes, int qtd_clientes, const char *nome) {
    int cliente_existe = 0;

    // Verifica se o cliente existe
    for (int i = 0; i < qtd_clientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            cliente_existe = 1;
            break;
        }
    }

    if (!cliente_existe) {
        printf("Cliente %s nao encontrado na lista de clientes.\n", nome);
        return;
    }

    // Procura o registro de presença para o cliente
    int pos = -1;
    for (int i = 0; i < *qtd_registos; i++) {
        if (strcmp(registos[i].nome_cliente, nome) == 0) {
            pos = i;
            break;
        }
    }

    // Se não encontrar, adiciona um novo registro
    if (pos == -1) {
        if (*qtd_registos >= MAX_REGISTOS) {
            printf("Limite de registos atingido.\n");
            return;
        }

        strcpy(registos[*qtd_registos].nome_cliente, nome);
        registos[*qtd_registos].presencas = 1;
        (*qtd_registos)++;
    } else {
        registos[pos].presencas++;
    }

    printf("Presenca registrada para %s.\n", nome);
    printf("****************************\n");
}


// Função para mostrar o número de sessões frequentadas por um cliente
void mostrar_sessoes_frequentadas(Registo *registos, int qtd_registos) {
    for (int i = 0; i < qtd_registos; i++) {
        printf("Cliente: %s, Presencas: %d\n", registos[i].nome_cliente, registos[i].presencas);
    }
    printf("****************************\n");
}
