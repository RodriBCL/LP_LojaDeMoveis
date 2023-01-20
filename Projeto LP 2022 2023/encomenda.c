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

#include "encomenda.h"
#include "cliente.h"
#include "produto.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void registarEncomenda(Encomendas *encomendas, Clientes listaClientes, ProdutoList produtos) {

    if ((*encomendas).totalEncomendas == 0) {
        (*encomendas).encomendas = (Encomenda*) malloc(sizeof (Encomenda));
    } else {
        (*encomendas).encomendas = (Encomenda*) realloc((*encomendas).encomendas, ((*encomendas).totalEncomendas + 1) * sizeof (Encomenda));
    }

    listarClientes(listaClientes);

    int idCliente, idProduto;

    printf("Encomenda nº %d:\n", encomendas->totalEncomendas + 1);
    idCliente = obterInt("Id Cliente: ");

    int indiceCliente = procurarCliente(listaClientes, idCliente);

    if (indiceCliente == -1) {
        printf("Cliente não existe!!\n");

    } else if (listaClientes.clientes[indiceCliente].estado == 0) {
        printf("Cliente está desativado!!\n");

    } else {
        printListaProdutos(produtos);

        idProduto = obterInt("Que produto deseja comprar(escreva só o último numero do produto): ");

        if (idProduto > produtos.totalProdutos || idProduto <= 0) {
            printf("Produto não existe!!");

        } else {

            (*encomendas).encomendas[(*encomendas).totalEncomendas].quantidade = obterInt("Quantas unidades deseja comprar: ");
            (*encomendas).encomendas[(*encomendas).totalEncomendas].totalPagar = (*encomendas).encomendas[(*encomendas).totalEncomendas].quantidade * produtos.produtos[idProduto - 1].preco;

            (*encomendas).encomendas[(*encomendas).totalEncomendas].data.dia = obterInt("Dia: ");
            (*encomendas).encomendas[(*encomendas).totalEncomendas].data.mes = obterInt("Mes: ");
            (*encomendas).encomendas[(*encomendas).totalEncomendas].data.ano = obterInt("Ano: ");

            (*encomendas).encomendas[(*encomendas).totalEncomendas].idCliente = idCliente;

            (*encomendas).encomendas[(*encomendas).totalEncomendas].idProduto = idProduto;

            (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente = (char*) malloc((strlen(listaClientes.clientes[indiceCliente].nome) + 1) * sizeof (char));
            strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente, listaClientes.clientes[indiceCliente].nome);

            (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeProduto = (char*) malloc((strlen(produtos.produtos[idProduto - 1].nome) + 1) * sizeof (char));
            strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeProduto, produtos.produtos[idProduto - 1].nome);

            encomendas->totalEncomendas++;

            (*encomendas).encomendas[((*encomendas).totalEncomendas) - 1].id = encomendas->totalEncomendas;

            imprimirEncomendaCliente(*encomendas, listaClientes, idCliente);

        }
    }

}

void imprimirEncomendas(Encomendas listaEncomendas) {
    int i;
    for (i = 0; i < listaEncomendas.totalEncomendas; i++) {
        printf("Encomenda nº: %d\nID Cliente: %d----Cliente: %s\nProduto: %s---Preço: %f---Qunatidade: %d\nData: %d/%d/%d\n",
                listaEncomendas.encomendas[i].id,
                listaEncomendas.encomendas[i].idCliente,
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
    int i, k;

    if (id == -1) {
        idCliente = obterInt("Id Cliente: ");
    } else {
        idCliente = id;
    }

    if (procurarCliente(listaClientes, idCliente) == -1) {
        puts("Cliente não encontrado");
        return;
    }

    for (i = 0; i < listaEncomendas.totalEncomendas; i++) {
        if (listaEncomendas.encomendas[i].idCliente == idCliente) {
            printf("Encomenda nº: %d\nID Cliente: %d----Cliente: %s\nProduto: %s---Preço: %f---Qunatidade: %d\nData: %d/%d/%d\n",
                    listaEncomendas.encomendas[i].id,
                    listaEncomendas.encomendas[i].idCliente,
                    listaEncomendas.encomendas[i].nomeCliente,
                    listaEncomendas.encomendas[i].nomeProduto,
                    listaEncomendas.encomendas[i].totalPagar,
                    listaEncomendas.encomendas[i].quantidade,
                    listaEncomendas.encomendas[i].data.dia,
                    listaEncomendas.encomendas[i].data.mes,
                    listaEncomendas.encomendas[i].data.ano);
            k++;
        }
    }
    if (k == 0) {
        puts("Cliente não tem encomendas");
    }
}

void writeEncomendas(Encomendas encomendas) {
    FILE *fp;
    int i;
    fp = fopen("Lista_Encomendas.csv", "w");
    if (fp == NULL) {
        printf("Erro ao abrir um ficheiro!!\n");
        return;
    }
    fprintf(fp, "idEncomenda;idCliente;nomeCliente;nomeProduto;totalPagar;quantidade;dataDia;dataMes;dataAno");
    for (i = 0; i < encomendas.totalEncomendas; i++) {
        fprintf(fp, "\n%d;%d;%d;%s;%s;%f;%d;%d;%d;%d",
                encomendas.encomendas[i].id,
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


    char buffer[1024];
    while (fgets(buffer, 1024, fp)) {



        dados = (char**) malloc(sizeof (char*) * 10);
        dados[0] = NULL;
        dados[1] = NULL;
        dados[2] = NULL;
        dados[3] = NULL;
        dados[4] = NULL;
        dados[5] = NULL;
        dados[6] = NULL;
        dados[7] = NULL;
        dados[8] = NULL;
        dados[9] = NULL;


        char *column = strtok(buffer, ";");
        int k = 0;

        while (column) {
            dados[k++] = column;
            column = strtok(NULL, ";");
        }
        if (i != 0) {

            if (dados[9] != NULL) {

                if ((*encomendas).totalEncomendas == 0) {
                    (*encomendas).encomendas = (Encomenda*) malloc(sizeof (Encomenda));
                } else {
                    (*encomendas).encomendas = (Encomenda*) realloc((*encomendas).encomendas, ((*encomendas).totalEncomendas + 1) * sizeof (Encomenda));
                }

                (*encomendas).encomendas[(*encomendas).totalEncomendas].idCliente = atoi(dados[1]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].idProduto = atoi(dados[2]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente = (char*) malloc((strlen(dados[3]) + 1) * sizeof (char));
                strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente, dados[3]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeProduto = (char*) malloc((strlen(dados[4]) + 1) * sizeof (char));
                strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeProduto, dados[4]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].quantidade = atoi(dados[5]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].totalPagar = atof(dados[6]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.dia = atoi(dados[7]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.mes = atoi(dados[8]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.ano = atoi(dados[9]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].id = atoi(dados[0]);
                (*encomendas).totalEncomendas++;

            }

        }
        i++;
        free(dados);
    }
    fclose(fp);
}

void freeEncomendas(Encomendas *encomendas) {
    int i;

    if (encomendas->totalEncomendas > 0) {
        for (i = 0; i < encomendas->totalEncomendas; i++) {

            free(encomendas->encomendas[i].nomeCliente);
            free(encomendas->encomendas[i].nomeProduto);

        }
        free(encomendas->encomendas);

    } else {
        printf("Não existem encomendas criadas\n");
    }
}

void ListarClientePorEncomenda(Encomendas encomendas, Clientes listaClientes) {
    int i, j, temp;
    int repeticoes[listaClientes.total][2];

    for (i = 0; i < listaClientes.total - 1; i++) {
        repeticoes[i][0] = 0;
    }

    for (i = 0; i < listaClientes.total - 1; i++) {
        repeticoes[i][1] = listaClientes.clientes[i].id;
    }

    for (i = 0; i < encomendas.totalEncomendas; i++) {
        for (j = 0; j < listaClientes.total; j++) {
           if( encomendas.encomendas[i].idCliente == listaClientes.clientes[j].id ){
               repeticoes[j][0]++; 
           }
        }
    }
    for (i = 0; i < listaClientes.total - 1; i++) {
        for (j = 0; j < listaClientes.total - i - 1; j++) {
            if (repeticoes[j][0] < repeticoes[j + 1][0]) {
                temp = repeticoes[j][0];
                repeticoes[j][0] = repeticoes[j + 1][0];
                repeticoes[j + 1][0] = temp;
                temp = repeticoes[j][1];
                repeticoes[j][1] = repeticoes[j + 1][1];
                repeticoes[j + 1][1] = temp;
            }
        }
    }


    for (i = 0; i < listaClientes.total; i++) {
        temp = procurarCliente(listaClientes, repeticoes[i][1]);
        if (temp != -1) {
            imprimirCliente(listaClientes.clientes[temp]);
        }
    }
}

int procurarEncomenda(Encomendas encomendas, int id) {
    int i;

    for (i = 0; i < encomendas.totalEncomendas; i++) {
        if (encomendas.encomendas[i].id == id) {
            return i;
        }
    }
    return -1;
}

void printProdutoMaisEncomendado(ProdutoList produtos, Encomendas encomendas) {
    int contadorProduto[produtos.totalProdutos];
    int posicaoProdutoMaisEncomendado = 0;
    int vezesEncomendadas = 0;
    int i;

    for (i = 0; i < produtos.totalProdutos; i++) {
        contadorProduto[i] = 0;
    }

    for (i = 0; i < encomendas.totalEncomendas; i++) {

        contadorProduto[(encomendas.encomendas[i].idProduto) - 1] += encomendas.encomendas[i].quantidade;

    }

    for (i = 0; i < produtos.totalProdutos; i++) {
        if (contadorProduto[i] > vezesEncomendadas) {
            vezesEncomendadas = contadorProduto[i];
            posicaoProdutoMaisEncomendado = i;
        }
    }

    printf("Produto mais encomendado: %s\n", produtos.produtos[posicaoProdutoMaisEncomendado].nome);
    printf("Quantidade: %d\n", vezesEncomendadas);

}



