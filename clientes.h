// clientes.h

#ifndef CLIENTES_H
#define CLIENTES_H
#include "config.h"

// Funções para gerenciar de clientes
void adicionar_cliente(Cliente *clientes, int *qtd_clientes);
void remover_cliente(Cliente *clientes, int *qtd_clientes, const char *nome);
void editar_cliente(Cliente *clientes, int qtd_clientes, const char *nome);
void buscar_cliente(Cliente *clientes, int qtd_clientes, Registo *registos, int qtd_registos, int opcao, const char *parametro);

#endif