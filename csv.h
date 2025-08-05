//csv.h

#ifndef CSV_H
#define CSV_H

#include "clientes.h"
#include "registos.h"

// Funções para ler e escrever dados de clientes num arquivo CSV
void ler_clientes_csv(Cliente *clientes, int *qtd_clientes);
void salvar_clientes_csv(Cliente *clientes, int qtd_clientes);

// Funções para ler e escrever registos de presença num arquivo CSV
void ler_registos_csv(Registo *registos, int *qtd_registos);
void salvar_registos_csv(Registo *registos, int qtd_registos);

#endif
