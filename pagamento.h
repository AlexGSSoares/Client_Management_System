//pagamento.h

#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include "registos.h"
#include "clientes.h"

void calcular_pagamento(Cliente *clientes, int qtd_clientes, Registo *registos, int qtd_registos);

#endif