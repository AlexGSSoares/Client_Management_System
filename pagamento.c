//pagamento.c

#include "pagamento.h"
#include "config.h"
#include <stdio.h>
#include <string.h>



// Função para calcular o pagamento mensal
void calcular_pagamento(Cliente *clientes, int qtd_clientes, Registo *registos, int qtd_registos) {
    for (int i = 0; i < qtd_clientes; i++) {
        int custo_plano;
        int limite_sessoes;
        int custo_extra = 0;

        if (strcmp(clientes[i].plano_treino, "A") == 0) {
            custo_plano = PLANO_A;
            limite_sessoes = SESSAO_A;
        } else if (strcmp(clientes[i].plano_treino, "B") == 0) {
            custo_plano = PLANO_B;
            limite_sessoes = SESSAO_B;
        } else {
            custo_plano = PLANO_C;
            limite_sessoes = SESSAO_C;
        }

        int presencas = 0;

        for (int j = 0; j < qtd_registos; j++) {
            if (strcmp(registos[j].nome_cliente, clientes[i].nome) == 0) {
                presencas = registos[j].presencas;
                break;
            }
        }

        if (presencas > limite_sessoes) {
            custo_extra = (presencas - limite_sessoes) * CUSTO_EXTRA;
        }

        int custo_total = custo_plano + custo_extra;

        printf("Cliente: %s, Plano: %s, Custo Total: %d euros\n", clientes[i].nome, clientes[i].plano_treino, custo_total);
    }
    printf("****************************\n");
}
