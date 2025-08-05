// registos.h

#ifndef REGISTOS_H
#define REGISTOS_H

#include "config.h"
#include "clientes.h"

// Funções para gerenciar de registos
void registar_presenca(Registo *registos, int *qtd_registos, const Cliente *clientes, int qtd_clientes, const char *nome);
void mostrar_sessoes_frequentadas(Registo *registos, int qtd_registos);

#endif
