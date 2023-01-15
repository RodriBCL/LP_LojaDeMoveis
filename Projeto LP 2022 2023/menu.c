/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   menu.c
 * Author: rodri
 * 
 * Created on 7 de dezembro de 2022, 20:12
 */

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "encomenda.h"

#define MENU "+--------------------------+"

void menu(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto){
    int escolha;

    puts(MENU);
    printf("  Gestão de loja de moveis  \n");
    puts(MENU);

    puts(MENU);
    printf("|         Menu             |\n");
    puts(MENU);

    printf("1- Acesso de administrador\n");
    printf("2- Acesso de cliente\n");
    printf("0- Sair do programa\n");

    puts(MENU);
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    system("clear");

    switch(escolha){
        case 1:
            menuAdmin(clientes, encomenda, produto);
            break;
        case 2:
            menuCliente(clientes, encomenda, produto);
            break;
        case 0:
            sairPrograma();
            break;
        default:
            printf("Opção inválida\n");
            printf("Prima ENTER para voltar ao menu\n");
            fflush(stdin);
            getchar();
            system("clear");
            menu(clientes, encomenda, produto);
            break;
    };
}


void menuAdmin(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto){
    int escolha;
    
    puts(MENU);
    printf("  Gestão de loja de moveis  \n");
    puts(MENU);

    puts(MENU);
    printf("|         Menu             |\n");
    puts(MENU);

    printf("1- Criar Clinte\n");
    printf("2- Remover Cliente\n");
    printf("3- Alterar Cliente\n");
    printf("4- Listar de Clientes\n");
    printf("5- Listar Produtos\n");
    printf("6- Editar Produto\n");
    printf("7- Eliminar Produto\n");
    printf("10- Listar encomendas\n");
    printf("0- Voltar\n");

    puts(MENU);
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    

    switch(escolha){
        case 1:
           inserirCliente(clientes);
            break;
        case 2:
            eliminarCliente(clientes, *encomenda);
            break;
        case 3:
            editarCliente(clientes);
            break;
        case 4:
            listarClientes(*clientes);
            break;
        case 5:
/*
            imprimirEncomendas(&encomendas);
*/
            break;
        case 6:
            //editar produto
            break;
        case 7:
            //eliminar produto
            break;
        case 0:
            menu(clientes, encomenda, produto);
            break;
        default:
            printf("Opção inválida\n");
            printf("Prima ENTER para voltar ao menu\n");
            fflush(stdin);
            getchar();
            system("clear");
            menu(clientes, encomenda, produto);
            break;
    };
    menuAdmin(clientes, encomenda, produto);
}



void menuCliente(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto){
    int escolha;

    puts(MENU);
    printf("  Gestão de loja de moveis  \n");
    puts(MENU);

    puts(MENU);
    printf("|         Menu             |\n");
    puts(MENU);

    printf("1- Registar Encomenda\n");
    printf("2- Listar Encomendas\n");
    printf("0- Voltar\n");

    puts(MENU);
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    system("clear");

    switch(escolha){
        case 1:
/*
            registarEncomenda(encomenda, *clientes, *produto);
*/
            break;
        case 2:
/*
            imprimirEncomendaCliente(*encomenda, *clientes);
*/
            break;
        case 0:
            menu(clientes, encomenda, produto);
            break;
        default:
            printf("Opção inválida\n");
            printf("Prima ENTER para voltar ao menu\n");
            fflush(stdin);
            getchar();
            system("clear");
            menu(clientes, encomenda, produto);
            break;
    };
    menuCliente(clientes, encomenda, produto);
}



void sairPrograma(){
    printf("Obrigado por utilizar o programa\n");
    printf("Prima ENTER para sair\n");
    fflush(stdin);
    getchar();
    exit(0);
}