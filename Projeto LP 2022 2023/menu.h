/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   menu.h
 * @Author: Rodrigo
 *@Author: Manuel
 *@Author: Mara
 * Created on 5 de dezembro de 2022, 12:16
 */

#ifndef MENU_H
#define MENU_H
#include "cliente.h"
#include "encomenda.h"
#include "produto.h"

/**
 * @brief exibe o menu principal e permite acessar as funcionalidades do sistema.
 * @param clientes apontador para a estrutura de clientes.
 * @param encomenda apontador para a estrutura de encomendas
 * @param produto apontador para a estrutura de produtos.
 */
void menu(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto);

/**
 * @brief Esta função exibe o menu para o administrador do programa de gerenciamento de loja de móveis.
 * O menu permite que o administrador realize várias ações, como criar novos clientes, remover clientes existentes,
 * alterar as informações do cliente, listar clientes, listar produtos, listar clientes por compra, excluir produtos,
 * listar encomendas e listar o produto mais encomendado.
 * @param clientes apontador para a estrutura de clientes.
 * @param encomenda apontador para a estrutura de encomendas
 * @param produto apontador para a estrutura de produtos.
 */
void menuAdmin(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto);

/**
 *@brief Esta função exibe o menu para o cliente do programa de gerenciamento de loja de móveis.
 * O menu permite que o cliente realize várias ações, como registar uma nova encomenda e ver as encomendas registadas anteriormente.
 * @param clientes apontador para a estrutura de clientes.
 * @param encomenda apontador para a estrutura de encomendas
 * @param produto apontador para a estrutura de produtos.
 */
void menuCliente(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto);

/**
* @brief Esta função é responsável por encerrar o programa, guardando as alterações feitas pelo usuário.
*/
void sairPrograma();


#endif /* MENU_H */
