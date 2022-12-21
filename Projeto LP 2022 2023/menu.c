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
#include "menu.h"
#include "cliente.h"

#define MENU "+--------------------------+"

void menu(){
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
            menuAdmin();
            break;
        case 2:
            menuCliente();
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
            menu();
            break;
    };
}


void menuAdmin(){
    int escolha;
    Clientes clientes = {.total = 0};
    
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
    system("clear");

    switch(escolha){
        case 1:
           inserirCliente(&clientes);
            break;
        case 2:
            eliminarCliente(&clientes);
            break;
        case 3:
            editarCliente(&clientes);
            break;
        case 4:
            listarClientes(clientes);
            break;
        case 5:
            //listar produtos
            break;
        case 6:
            //editar produto
            break;
        case 7:
            //eliminar produto
            break;
        case 0:
            menu();
            break;
        default:
            printf("Opção inválida\n");
            printf("Prima ENTER para voltar ao menu\n");
            fflush(stdin);
            getchar();
            system("clear");
            menu();
            break;
    };
    menuAdmin();
}


void menuCliente(){
    int escolha;

    puts(MENU);
    printf("  Gestão de loja de moveis  \n");
    puts(MENU);

    puts(MENU);
    printf("|         Menu             |\n");
    puts(MENU);

    printf("1- Registar Encomenda\n");
    printf("2- Remover encomenda\n");
    printf("3- Alterar Encomenda\n");
    printf("4- Listar Encomendas\n");
    printf("0- Voltar\n");

    puts(MENU);
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    system("clear");

    switch(escolha){
        case 1:
            //criar encomenda
            break;
        case 2:
            //remover encomenda
            break;
        case 3:
            //alterar encomenda
            break;
        case 4:
            //listar encomendas
            break;
        case 0:
            menu();
            break;
        default:
            printf("Opção inválida\n");
            printf("Prima ENTER para voltar ao menu\n");
            fflush(stdin);
            getchar();
            system("clear");
            menu();
            break;
    };
    menuCliente();
}


void sairPrograma(){
    printf("Obrigado por utilizar o programa\n");
    printf("Prima ENTER para sair\n");
    fflush(stdin);
    getchar();
    exit(0);
}