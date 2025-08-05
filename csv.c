//csv.c

#include "csv.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lê dados de clientes do arquivo CSV
void ler_clientes_csv(Cliente *clientes, int *qtd_clientes) {
    FILE *arquivo = fopen("clientes.csv", "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo de clientes");
        return;
    }

    char linha[256];
    *qtd_clientes = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (*qtd_clientes >= MAX_CLIENTES) {
            break;
        }

        char *token = strtok(linha, ",");
        strcpy(clientes[*qtd_clientes].nome, token);

        token = strtok(NULL, ",");
        clientes[*qtd_clientes].idade = atoi(token);

        token = strtok(NULL, ",");
        strcpy(clientes[*qtd_clientes].genero, token);

        token = strtok(NULL, ",");
        strcpy(clientes[*qtd_clientes].plano_treino, token);

        // Remover espaços em branco ou caracteres extras no final do plano
        strtok(clientes[*qtd_clientes].plano_treino, "\n");
        strtok(clientes[*qtd_clientes].plano_treino, "\r");

        (*qtd_clientes)++;
    }

    fclose(arquivo);
}

// Salva dados de clientes no arquivo CSV
void salvar_clientes_csv(Cliente *clientes, int qtd_clientes) {
    FILE *arquivo = fopen("clientes.csv", "w");
    if (!arquivo) {
        perror("Erro ao abrir arquivo de clientes");
        return;
    }

    for (int i = 0; i < qtd_clientes; i++) {
        fprintf(arquivo, "%s,%d,%s,%s\n",
                clientes[i].nome,
                clientes[i].idade,
                clientes[i].genero,
                clientes[i].plano_treino);
    }

    fclose(arquivo);
}


// Função para ler registos de presença do arquivo CSV
void ler_registos_csv(Registo *registos, int *qtd_registos) {
    FILE *arquivo = fopen(ARQUIVO_REGISTOS, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de registos");
        return;
    }

    char linha[256];
    *qtd_registos = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (*qtd_registos >= MAX_REGISTOS) {
            break;
        }

        char *token = strtok(linha, ",");
        strcpy(registos[*qtd_registos].nome_cliente, token);

        token = strtok(NULL, ",");
        registos[*qtd_registos].presencas = atoi(token);

        (*qtd_registos)++;
    }

    fclose(arquivo);
}

// Função para salvar registos de presença no arquivo CSV
void salvar_registos_csv(Registo *registos, int qtd_registos) {
    FILE *arquivo = fopen(ARQUIVO_REGISTOS, "w");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de registos");
        return;
    }

    for (int i = 0; i < qtd_registos; i++) {
        fprintf(arquivo, "%s,%d\n",
                registos[i].nome_cliente,
                registos[i].presencas);
    }

    fclose(arquivo);
}
