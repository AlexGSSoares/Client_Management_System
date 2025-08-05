//config.h

#ifndef CONFIG_H
#define CONFIG_H

//estrutura para dados de clientes
typedef struct {
    char nome[100];
    int idade;
    char genero[10];
    char plano_treino[20];
} Cliente;

//Estrutura para contabilizar presenças
typedef struct {
    char nome_cliente[100];
    int presencas;
} Registo;

//Número máximo de clientes e Registos
#define MAX_CLIENTES 100
#define MAX_REGISTOS 100

//Preço dos planos
#define PLANO_A 10
#define PLANO_B 20
#define PLANO_C 30

//Quantidade de sessões incluída nos planos
#define SESSAO_A 5
#define SESSAO_B 15
#define SESSAO_C 30

//Custo extra de cada sessão
#define CUSTO_EXTRA 2

//Arquivos CSV
#define ARQUIVO_CLIENTES "clientes.csv"
#define ARQUIVO_REGISTOS "registos.csv"

#endif