//relatorios.c

#include "relatorios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para mostrar os planos preferidos dos clientes
void mostrar_planos_preferidos(Cliente *clientes, int qtd_clientes) {
    int cont_A = 0;
    int cont_B = 0;
    int cont_C = 0;

    for (int i = 0; i < qtd_clientes; i++) {
        if (strcmp(clientes[i].plano_treino, "A") == 0) {
            cont_A++;
        } else if (strcmp(clientes[i].plano_treino, "B") == 0) {
            cont_B++;
        } else {
            cont_C++;
        }
    }

    printf("Planos preferidos:\n");
    printf("Plano A: %d clientes\n", cont_A);
    printf("Plano B: %d clientes\n", cont_B);
    printf("Plano C: %d clientes\n", cont_C);
    printf("****************************\n");
}

// Comparador para ordenar registros por número de presenças
int comparador_presencas(const void *a, const void *b) {
    Registo *reg1 = (Registo *)a;
    Registo *reg2 = (Registo *)b;
    return reg2->presencas - reg1->presencas; // Ordem decrescente
}

// Função para encontrar os clientes com mais presenças
void mostrar_clientes_com_mais_presencas(Registo *registos, int qtd_registos) {
    // Ordenar os registros por número de presenças em ordem decrescente
    qsort(registos, qtd_registos, sizeof(Registo), comparador_presencas);

    printf("Os clientes com maior numero de presencas:\n");

    // Exibir os 5 clientes com mais presenças
    int limite = (qtd_registos < 5) ? qtd_registos : 5;
    for (int i = 0; i < limite; i++) {
        printf("Cliente: %s, Presencas: %d\n", registos[i].nome_cliente, registos[i].presencas);
    }

    printf("****************************\n");
}

// Função para mostrar clientes com mais sessões do que as do plano
void mostrar_clientes_com_mais_sessoes_que_plano(Cliente *clientes, Registo *registos, int qtd_clientes, int qtd_registos) {
    printf("Clientes com mais sessoes do que o plano:\n");

    for (int i = 0; i < qtd_clientes; i++) {
        int limite_sessoes = 0;

        if (strcmp(clientes[i].plano_treino, "A") == 0) {
            limite_sessoes = 5;
        } else if (strcmp(clientes[i].plano_treino, "B") == 0) {
            limite_sessoes = 15;
        } else {
            limite_sessoes = 30;
        }

        int presencas = 0;

        for (int j = 0; j < qtd_registos; j++) {
            if (strcmp(registos[j].nome_cliente, clientes[i].nome) == 0) {
                presencas = registos[j].presencas;
                break;
            }
        }

        if (presencas > limite_sessoes) {
            printf("Cliente: %s, Plano: %s, Presencas: %d\n", clientes[i].nome, clientes[i].plano_treino, presencas);
        }

    }
    printf("****************************\n");
}
