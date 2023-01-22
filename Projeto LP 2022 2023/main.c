/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: Rodrigo
 *Author: Manuel
 *Author: Mara
 * Created on 5 de dezembro de 2022, 12:16
 */

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "encomenda.h"
#include "produto.h"
#include "input.h"

#define MENU "+--------------------------+"

/*
 * 
 */
int main(int argc, char** argv) {
    
/**
 * @brief Definimos três variáveis - clientes, produto e encomenda.
 * @var estas invocam estruturas que são usadas para armazenar informações sobre clientes, produto e encomenda.
 *  
 */
    Clientes clientes;
    ProdutoList produto;
    Encomendas encomenda;
    
/**
 *@brief Inicializam o comtador de produto, cliente, encomenda com zero.
 */
    produto.totalProdutos = 0;
    clientes.total = 0;
    encomenda.totalEncomendas = 0;
    
 /**
  *@brief Define o número máximo de produto, cliente e encomenda máximo.
  */   
    produto.maxProdutos = 3;
    clientes.maxClientes = 10;
    encomenda.maxEncomendas = 10;
    
  /**
   * @brief Alocam memória para armazenar o array de encomenda, clientes e produto.
   */  
    encomenda.encomendas = (Encomenda*) malloc(sizeof (Encomenda) * (encomenda).maxEncomendas);
    clientes.clientes = (Cliente*) malloc(sizeof (Cliente) * (clientes).maxClientes);
    produto.produtos = (Produto*) malloc(sizeof (Produto) * (produto).maxProdutos);
    
/**
 * @brief lê a lista de produtos do sistema e armazena em produto.
 * @param produto apontador para a estrutura de produtos. 
 */
    readListaProdutos(&produto);
    
 /**
  * @brief lê a lista de clientes do sistema e armazena em clientes.
  * @param clientes apontador para a estrutura de clientes.
  */
    
    readClientes(&clientes);
    
/**
 * @brief lê a lista de encomendas do sistema e armazena em encomenda
 * @param encomenda apontador para a estrutura de encomendas.
 */
    readEncomendas(&encomenda);

/**
 * @brief exibe o menu principal e permite acessar as funcionalidades do sistema.
 * @param clientes apontador para a estrutura de clientes.
 * @param encomenda apontador para a estrutura de encomendas
 * @param produto apontador para a estrutura de produtos.
 */
    menu(&clientes, &encomenda, &produto);

    return (EXIT_SUCCESS);
}

