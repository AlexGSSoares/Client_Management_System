//relatorios.h

#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "clientes.h"
#include "registos.h"

void mostrar_planos_preferidos(Cliente *clientes, int qtd_clientes);
void mostrar_clientes_com_mais_presencas(Registo *registos, int qtd_registos);
void mostrar_clientes_com_mais_sessoes_que_plano(Cliente *clientes, Registo *registos, int qtd_clientes, int qtd_registos);

#endif