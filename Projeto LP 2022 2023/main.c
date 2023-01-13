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
    
    inserirCliente(&clientes);
    inserirCliente(&clientes);
    listarClientes(clientes);
    writeClientes(clientes);
   
/*
    readListaProdutos(&produto);
    registarEncomenda(&encomenda, clientes, produto);
    imprimirEncomendaCliente(encomenda, clientes);
*/
    
    
    
/*
    menu(&clientes);
*/

    return (EXIT_SUCCESS);
}

