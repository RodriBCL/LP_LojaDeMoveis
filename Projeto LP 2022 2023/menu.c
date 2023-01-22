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
#include "input.h"
#include "produto.h"
#include "log.h"

#define MENU "+--------------------------+"
#define CODE 3500

void menu(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto) {
    int escolha;





    /**
     * Este é o menu principal do programa de gestão de loja de móveis.
     * Ele permite ao usuário escolher entre acesso de administrador, acesso de cliente e sair do programa.
     */

    printf("\n");
    puts(MENU);
    printf("  Gestão de loja de moveis  \n");
    puts(MENU);

    puts(MENU);
    printf("|         Menu             |\n");
    puts(MENU);

    printf("1- Acesso de administrador\n");
    printf("2- Acesso de cliente\n");
    printf("0- Sair do programa e guardar alterações\n");

    puts(MENU);
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    system("clear");

    /**
     * Este é o switch case que gerencia as opções escolhidas pelo usuário no menu principal.
     * De acordo com o valor da variável "escolha", diferentes ações serão tomadas.
     */
    switch (escolha) {
        case 1:
            logMsg("Menu Admin");
            //int cod = obterInt("Insira o codigo de administração: ");
            //if (cod == CODE) {
            menuAdmin(clientes, encomenda, produto);
            //} else {
            //  printf("Codigo incorreto...\n");
            //menu(clientes, encomenda, produto);
            //}
            break;
        case 2:
            logMsg("Menu Cliente");
            menuCliente(clientes, encomenda, produto);
            break;
        case 0:
            logMsg("Sair do programa");

            writeClientes(*clientes);
            writeEncomendas(*encomenda);
            writeListaProdutos(*produto);

            freeEncomendas(encomenda);
            libertarMemcliente(clientes);
            freeProdutos(produto);

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

/**
 * Esta função exibe o menu para o administrador do programa de gerenciamento de loja de móveis.
 * O menu permite que o administrador realize várias ações, como criar novos clientes, remover clientes existentes,
 * alterar as informações do cliente, listar clientes, listar produtos, listar clientes por compra, excluir produtos,
 * listar encomendas e listar o produto mais encomendado.
 */
void menuAdmin(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto) {
    int escolha;

    printf("\n");
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
    printf("6- Listar clientes por compra\n");
    printf("7- Eliminar Produto\n");
    printf("8- Listar encomendas\n");
    printf("9- Listar produto mais encomendado\n");
    printf("10- Listar mês com mais encomendas\n");
    printf("11- Mostrar o cliente que mais gastou\n");
    printf("12- Mostrar componentes por semana\n");
    printf("13- Apagar encomenda\n");
    printf("0- Voltar\n");

    puts(MENU);
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);


    /**
     * Este é o comando switch que gerencia a escolha do usuário no menu do administrador. 
     * Dependendo do valor da variável "escolha", diferentes ações serão tomadas.
     */
    switch (escolha) {
        case 1:
            adicionarCliente(clientes);
            logMsg("Criar Clinte");
            break;
        case 2:
            eliminarCliente(clientes, *encomenda);
            logMsg("Remover Cliente");
            break;
        case 3:
            editarCliente(clientes);
            logMsg("Alterar Cliente");
            break;
        case 4:
            listarClientes(*clientes);
            logMsg("Listar de Clientes");
            break;
        case 5:
            printListaProdutos(*produto);
            logMsg("Listar Produtos");
            break;
        case 6:
            ListarClientePorEncomenda(*encomenda, *clientes);
            logMsg("Listar clientes por compra");
            break;
        case 7:
            eleminarProduto(produto, *encomenda);
            logMsg("Eliminar Produto");
            break;
        case 8:
            imprimirEncomendas(*encomenda);
            logMsg("Listar encomendas");
            break;
        case 9:
            printProdutoMaisEncomendado(*produto, *encomenda);
            logMsg("Listar produto mais encomendado");
            break;
        case 10:
            printMesMaisEncomendas(*encomenda);
            logMsg("Listar mês com mais encomendas");
            break;
        case 11:
            clienteMaisGastador(*clientes, *encomenda);
            logMsg("Mostrar o cliente que mais gastou");
        case 12:
            listarComponentesPorSemana(*encomenda, *produto);
            logMsg("Mostrar componentes por semana");
            break;
        case 13:
            apagarEncomenda(encomenda);
            logMsg("Apagar encomenda");
            break;
        case 0:
            logMsg("Voltar");
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

/**
 * Esta função exibe o menu para o cliente do programa de gerenciamento de loja de móveis.
 * O menu permite que o cliente realize várias ações, como registar uma nova encomenda e ver as encomendas registadas anteriormente.
 */
void menuCliente(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto) {
    int escolha, idCliente;

    printf("\n");
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

    switch (escolha) {
        case 1:
            registarEncomenda(encomenda, *clientes, *produto);
            logMsg("Registar Encomenda");
            break;
        case 2:
            listarClientes(*clientes);
            idCliente = obterInt("Id Cliente: ");
            imprimirEncomendaCliente(*encomenda, *clientes, idCliente);
            logMsg("Listar Encomendas");
            break;
        case 0:
            logMsg("Voltar");
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

/**
 Esta função é responsável por encerrar o programa, guardando as alterações feitas pelo usuário.
 */
void sairPrograma() {
    printf("Guardar alterações....\n");
    printf("Obrigado por utilizar o programa\n");
    fflush(stdin);
    getchar();
    exit(0);
}