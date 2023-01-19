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
    /*
    
     */
    produto.totalProdutos = 0;
    clientes.total = 0;
    encomenda.totalEncomendas = 0;

    /*


            readListaProdutos(&produto);
            readClientes(&clientes);

            adicionarCliente(&clientes);
            listarClientes(clientes);
            eliminarCliente(&clientes, encomenda);
            listarClientes(clientes);
            writeClientes(clientes);
        
           registarEncomenda(&encomenda, clientes, produto);
    
           libertarMemcliente(&clientes);

        
     */



    /*
        readListaProdutos(&produto);
        registarEncomenda(&encomenda, clientes, produto);
        imprimirEncomendaCliente(encomenda, clientes);
     */




            

    readListaProdutos(&produto);
    readClientes(&clientes);

    menu(&clientes, &encomenda, &produto);






    return (EXIT_SUCCESS);
}

