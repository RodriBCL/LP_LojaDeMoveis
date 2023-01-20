/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: rodri
 *
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

    Clientes clientes;
    ProdutoList produto;
    Encomendas encomenda;

    produto.totalProdutos = 0;
    clientes.total = 0;
    encomenda.totalEncomendas = 0;
    
    produto.maxProdutos = 3;
    clientes.maxClientes = 10;
    encomenda.maxEncomendas = 10;
    
    (*encomenda).encomendas = (Encomenda*) malloc(sizeof (Encomenda) * encomenda.maxEncomendas);
    (*clientes).clientes = (Cliente *) malloc(sizeof (Cliente) * clientes.maxClientes);
    (*produto).produtos = (Produto *) malloc(sizeof (Produto) * produto.maxProdutos);
     

    readListaProdutos(&produto);
    readClientes(&clientes);
    readEncomendas(&encomenda);

    menu(&clientes, &encomenda, &produto);

    return (EXIT_SUCCESS);
}

