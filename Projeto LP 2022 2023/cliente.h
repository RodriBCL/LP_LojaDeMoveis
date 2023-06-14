/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   cliente.h
 * @Author: Rodrigo
 *@Author: Manuel
 *@Author: Mara
 * Created on 5 de dezembro de 2022, 12:16
 */


#ifndef CLIENTE_H
#define CLIENTE_H

#define SIZE_BUFFER 100

typedef struct 
{
    int id;
    char *nome;
    char *nif;
    char *morada;
    char *telefone;
    char *email;
    char *pais;
    int estado;
} Cliente;


typedef struct 
{
    Cliente *clientes;
    int total;
    int maxClientes;
} Clientes;

#include "encomenda.h"


/**
 *@brief  Esta função procura um cliente em uma matriz de clientes por seu ID.
 * @param clientes contem um array de clientes e um inteiro "total" que representa o número de clientes no array.
 * @param id representa o ID do cliente que está a ser procurado.
 * @return -1
 */
int procurarCliente(Clientes clientes, int id);


/**
 *@brief Esta função adiciona um novo cliente ao array clientes.
 * @param clientes, contem o array clientes, "total" que representa o numero de clientes no array e um inteiro "maxClientes" que representa o número maximo de clientes que podem ser armazenados no array.
 * Se o numero atual de clientes no array é igual ao numero maxumo de clientes que podem ser armazenados,a função aumenta o numero maximo de clientes em 3 e realoca a memoria para o array de clientes.
 */
void adicionarCliente(Clientes *clientes);

/**
 *@brief Esta função liberta memoria alocada para um array de clientes.
 * Verifica se o campo "total" da struct é maior que 0, e indica que existem clientes no array. Se houver a funçao usa um loop for para percorrer a matriz e liberta a memoria alocada para os campos.
 * Liberta a memoria alocada para o proprio array de clientes.
 * @param clientes, contem um array de clientes, um inteiro "total" que representa o numero de clientes no array e um inteiro "maxClientes" que representa o numero maximo de clientes que podem ser rmazenados no array.
 */
void libertarMemcliente(Clientes *clientes);

/**
 *@brief Liberta emoria alocada para um array clientes.
 *Verifica se o campo "total" da struct é maior que 0, e indica que existem clientes no array.
 * Se houver usa um loop for para percorrer a matriz e liberta memoria alocada para os campos.
 * Liberta a memoria alocada para o proprio array de clientes.
 * @param cliente é um apontador para uma etsrutura do tipo "Clientes" que contem um array de clientes, um inteiro "total" que representa o numero de clientes no array e um inteiro "maxClinetes" que representa o numero maximo de clientes que podem ser armazenados no array.
 */
void imprimirCliente(Cliente cliente);

/**
 *@brief Lista todos os clientes numa matriz de clientes.
 * Verifica se o campo "total" da struct é maior que 0, e indica que existem clientes no array.
 * Se houver, a função usa um loop for para iterar pelo array e chama a função "imprimirCliente" para exibir as informações de cada cliente.
 * @param clientes contem um array de clientes.
 */
void listarClientes(Clientes clientes);

/**
 *@brief Esta função atualiza as informações de um único cliente.
 * Para cada opção, usa a função "lerString" para ler o novo valor do campo e a funçao "realloc" para realocar a memoria do campo para armazenar o novo valor
 * Usa a função "strcpy" para copiar o novo valor no campo da estrutura do cliente.
 * @param cliente, contem o array de vendedores.
 */
void atualizarDadosCliente(Cliente *cliente);


/**
 *@brief Esta função edita os dados de um cliente.
 * É pedido ao usuario o id do cliente, se este nao existir, recebe uma mensagem como o cliente não existe.
 * @param clientes
 */
void editarCliente(Clientes *clientes);


/**
 *@brief Verifica se o cliente ja realizou ou nao encomendas.
 * Se ja realizou encomendas atualiza o estado para 0, se não fez elimina o cliente.
 * @param clientes
 * @param encomenda
 */
void eliminarCliente(Clientes *clientes, Encomendas encomenda);


/**
 *@brief Abre o ficheiro "Lista_Clientes.csv, caso nao consiga abrir imprime a mensagem.
 * Se conseguir abrir o ficheiro, mostra todos os campos dos clientes.
 * @param clientes
 */
void writeClientes(Clientes clientes);


/**
  * @brief lê a lista de clientes do sistema e armazena em clientes.
  * @param clientes apontador para a estrutura de clientes.
  */
void readClientes(Clientes *clientes);


/**
 * @brief Serve para calcular o cliente que mais gastos teve na loja.
 * totalGasto[i] inicializa a 0.
 * @param clientes
 * @param encomendas
 */
void clienteMaisGastador(Clientes clientes, Encomendas encomendas);

#endif /* CLIENTE_H */
