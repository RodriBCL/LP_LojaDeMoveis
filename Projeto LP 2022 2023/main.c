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

#define MENU "+--------------------------+"

/*
 * 
 */
int main(int argc, char** argv) {
  
    Clientes clientes;
    

    menu(clientes);


/*
    Clientes clientes;
    
    inserirCliente(&clientes);
    inserirCliente(&clientes);
    printf("Prints:\n");
    listarClientes(clientes);
    editarCliente(&clientes);
    eliminarCliente(&clientes);
    printf("Novos prints:\n");
    listarClientes(clientes);
    
*/

    return (EXIT_SUCCESS);
}

