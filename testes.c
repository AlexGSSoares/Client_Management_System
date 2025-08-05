//testes.c

#include "testes.h"
#include "clientes.h"
#include "registos.h"
#include "pagamento.h"
#include <stdio.h>
#include <string.h>
#include "config.h"

// Testes para adicionar cliente
void teste_adicionar_cliente() {
    Cliente clientes[MAX_CLIENTES];
    int qtd_clientes = 0;

    adicionar_cliente(clientes, &qtd_clientes);
    if (qtd_clientes > 0) {
        printf("Teste de adicionar cliente: SUCESSO\n");
    } else {
        printf("Teste de adicionar cliente: FALHA\n");
    }
}

// Testes para remover cliente
void teste_remover_cliente() {
    Cliente clientes[MAX_CLIENTES];
    int qtd_clientes = 1;

    strcpy(clientes[0].nome, "Cliente1");

    remover_cliente(clientes, &qtd_clientes, "Cliente1");

    if (qtd_clientes == 0) {
        printf("Teste de remover cliente: SUCESSO\n");
    } else {
        printf("Teste de remover cliente: FALHA\n");
    }
}

// Testes para editar cliente
void teste_editar_cliente() {
    Cliente clientes[MAX_CLIENTES];
    int qtd_clientes = 1;

    strcpy(clientes[0].nome, "Cliente1");

    editar_cliente(clientes, qtd_clientes, "Cliente1");

    if (strcmp(clientes[0].nome, "Cliente1") != 0) {
        printf("Teste de editar cliente: SUCESSO\n");
    } else {
        printf("Teste de editar cliente: FALHA\n");
    }
}

// Testes para registrar presença
void teste_registar_presenca() {
    Registo registos[MAX_REGISTOS];
    int qtd_registos = 0;

    registar_presenca(registos, &qtd_registos, "Cliente1");

    if (registos[0].presencas == 1) {
        printf("Teste de registar presenca: SUCESSO\n");
    } else {
        printf("Teste de registar presenca: FALHA\n");
    }
}

// Testes para calcular pagamento
void teste_calcular_pagamento() {
    Cliente clientes[MAX_CLIENTES];
    Registo registos[MAX_REGISTOS];
    int qtd_clientes = 1;
    int qtd_registos = 1;

    strcpy(clientes[0].nome, "Cliente1");
    strcpy(clientes[0].plano_treino, "A");
    strcpy(registos[0].nome_cliente, "Cliente1");
    registos[0].presencas = 10;

    calcular_pagamento(clientes, qtd_clientes, registos, qtd_registos);

    // Testes básicos para validar resultados
    printf("Teste de calcular pagamento: Verificar saida manualmente.\n");
}
