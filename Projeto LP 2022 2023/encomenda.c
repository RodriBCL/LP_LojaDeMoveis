/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   encomenda.c
 * Author: rodri
 * 
 * Created on 7 de dezembro de 2022, 20:12
 */

#include "cliente.h"
#include "encomenda.h"
#include "produto.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void registarEncomenda(Encomendas *encomendas, Clientes listaClientes, ProdutoList produtos) {

    if ((*encomendas).totalEncomendas == 0) {
        (*encomendas).encomendas = (Encomenda*) malloc(sizeof (Encomenda));
    } else {
        (*encomendas).encomendas = (Encomenda*) realloc((*encomendas).encomendas, (*encomendas).totalEncomendas + 1 * sizeof (Encomenda));
    }

    listarClientes(listaClientes);

    int idCliente, idProduto;

    idCliente = obterInt("Id Cliente: ");
    
    int indiceCliente = procurarCliente(listaClientes, idCliente);
    
    if (indiceCliente == -1) {
        printf("Cliente não existe!!\n");

    } else if (listaClientes.clientes[indiceCliente].estado == 0) {
        printf("Cliente está desativado\n");
        
    } else {
        printListaProdutos(produtos);

        idProduto = obterInt("Que produto deseja comprar(escreva só o último numero do produto): ");

        if (idProduto > produtos.totalProdutos || idProduto <= 0) {
            printf("Produto não existe!!");

        } else {
            encomendas->encomendas[encomendas->totalEncomendas].quantidade = obterInt("Quanto deseja comprar: ");
            encomendas->encomendas[encomendas->totalEncomendas].totalPagar = encomendas->encomendas[encomendas->totalEncomendas].quantidade * produtos.produtos[idProduto - 1].preco;

            encomendas->encomendas[encomendas->totalEncomendas].data.dia = obterInt("Dia: ");
            encomendas->encomendas[encomendas->totalEncomendas].data.mes = obterInt("Mes: ");
            encomendas->encomendas[encomendas->totalEncomendas].data.ano = obterInt("Ano: ");

            encomendas->encomendas[encomendas->totalEncomendas].idCliente = idCliente;

            (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente = malloc((strlen(listaClientes.clientes[idCliente - 1].nome) + 1) * sizeof (char));
            strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente, listaClientes.clientes[idCliente - 1].nome);

            (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeProduto = malloc((strlen(produtos.produtos[idProduto - 1].nome) + 1) * sizeof (char));
            strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeProduto, produtos.produtos[idProduto - 1].nome);

            encomendas->totalEncomendas++;
           
            imprimirEncomendaCliente(*encomendas, listaClientes, idCliente);
        }
    }
    
}

void imprimirEncomendas(Encomendas listaEncomendas) {
    int i;
    for (i = 0; i < listaEncomendas.totalEncomendas; i++) {
        printf("Id: %d----Cliente: %s----Produto: %s---Preço: %f---Qunatidade: %d----Data: %d/%d/%d", listaEncomendas.encomendas[i].idCliente,
                listaEncomendas.encomendas[i].nomeCliente,
                listaEncomendas.encomendas[i].nomeProduto,
                listaEncomendas.encomendas[i].totalPagar,
                listaEncomendas.encomendas[i].quantidade,
                listaEncomendas.encomendas[i].data.dia,
                listaEncomendas.encomendas[i].data.mes,
                listaEncomendas.encomendas[i].data.ano);
    }
}

void imprimirEncomendaCliente(Encomendas listaEncomendas, Clientes listaClientes, int id) {
    int idCliente;
    int i;
    
    if(id == -1){
    idCliente = obterInt("Id: ");
    }else{
        idCliente = id;
    }

    if (procurarCliente(listaClientes, idCliente) == -1) {
        puts("Cliente não encontrado");
        return;
    }

    for (i = 0; i < listaEncomendas.totalEncomendas; i++) {
        if (listaEncomendas.encomendas[i].idCliente == idCliente) {
            printf("Id: %d----Cliente: %s----Produto: %s---Preço: %f---Qunatidade: %d----Data: %d/%d/%d", listaEncomendas.encomendas[i].idCliente,
                    listaEncomendas.encomendas[i].nomeCliente,
                    listaEncomendas.encomendas[i].nomeProduto,
                    listaEncomendas.encomendas[i].totalPagar,
                    listaEncomendas.encomendas[i].quantidade,
                    listaEncomendas.encomendas[i].data.dia,
                    listaEncomendas.encomendas[i].data.mes,
                    listaEncomendas.encomendas[i].data.ano);
        } else {
            puts("Cliente não tem encomendas");
        }
    }
}

void writeEncomendas(Encomendas encomendas) {
    FILE *fp;

    fp = fopen("Lista_Encomendas.csv", "w");
    if (fp == NULL) {
        printf("Erro ao abrir um ficheiro!!\n");
        return;
    }
    fprintf(fp, "idCliente;nomeCliente;nomeProduto;totalPagar;quantidade;datadia;datames;dataano\n");
    for (int i = 0; i < encomendas.totalEncomendas; i++) {
        fprintf(fp, "%d;%d;%s;%s;%d;%f;%d;%d;%d\n",
                encomendas.encomendas[i].idCliente,
                encomendas.encomendas[i].idProduto,
                encomendas.encomendas[i].nomeCliente,
                encomendas.encomendas[i].nomeProduto,
                encomendas.encomendas[i].totalPagar,
                encomendas.encomendas[i].quantidade,
                encomendas.encomendas[i].data.dia,
                encomendas.encomendas[i].data.mes,
                encomendas.encomendas[i].data.ano);
    }
    fclose(fp);
}

void readEncomendas(Encomendas *encomendas) {
    FILE *fp;
    char **dados;

    fp = fopen("Lista_Clientes.csv", "r");

    if (fp == NULL) {
        puts("Erro ao abrir o ficheiro");
        return;
    }

    int i = 0;

    if ((*encomendas).totalEncomendas == 0) {
        (*encomendas).encomendas = (Encomenda*) malloc(sizeof (Encomenda));
    } else {
        (*encomendas).encomendas = (Encomenda*) realloc((*encomendas).encomendas, ((*encomendas).totalEncomendas + 1) * sizeof (Encomenda));
    }
    char buffer[1024];
    while (fgets(buffer, 1024, fp)) {

        dados = (char**) malloc(sizeof (char*) * 9);
        dados[0] = NULL;
        dados[1] = NULL;
        dados[2] = NULL;
        dados[3] = NULL;
        dados[4] = NULL;
        dados[5] = NULL;
        dados[6] = NULL;
        dados[7] = NULL;
        dados[8] = NULL;


        char *column = strtok(buffer, ";");
        int k = 0;

        while (column) {
            dados[k++] = column;
            column = strtok(NULL, ";");
        }
        if (i != 0) {

            if (dados[6] != NULL) {
                (*encomendas).encomendas[(*encomendas).totalEncomendas].idCliente = atoi(dados[0]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].idProduto = atoi(dados[1]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente = malloc((strlen(dados[2]) + 1) * sizeof (char));
                strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente, dados[2]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente = malloc((strlen(dados[2]) + 1) * sizeof (char));
                strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeProduto, dados[3]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].quantidade = atoi(dados[4]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].totalPagar = atof(dados[5]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.dia = atoi(dados[6]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.mes = atoi(dados[7]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.ano = atoi(dados[8]);
            }

        }
        i++;
        free(dados);
    }
    fclose(fp);
}

int procurarEncomenda(Encomendas encomendas, int id) {
    int i;

    for (i = 0; i < encomendas.totalEncomendas; i++) {
        if (encomendas.encomendas[i].idProduto == id) {
            return i;
        }
    }
    return -1;
}



