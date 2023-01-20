/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/*
 * File:   produto.c
 * Author: rodri
 *
 * Created on 20 de dezembro de 2022, 16:01
 */

#include "produto.h"
#include "encomenda.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void readListaProdutos(ProdutoList *lista) {
    FILE *fp;
    //ProdutoList (*lista);
    Produto produtos;
    char **dados;

    int produto = 0;
    int componentes = 0;

    fp = fopen("Tabela_Ficha_Tecnica.csv", "r");

    if (fp == NULL) {
        puts("Erro ao abrir o ficheiro");
        return;
    }
    int i = 0;
    (*lista).produtos = (Produto*) malloc(sizeof (Produto));
    char buffer[1024];
    dados = (char**) malloc(sizeof (char*) * 8);
    while (fgets(buffer, 1024, fp)) {

        dados[0] = NULL;
        dados[1] = NULL;
        dados[3] = NULL;
        dados[4] = NULL;
        dados[5] = NULL;
        dados[6] = NULL;
        dados[7] = NULL;
        char *column = strtok(buffer, ";");
        int k = 0;
        while (column) {
            dados[k++] = column;
            column = strtok(NULL, ";");
        }
        if (i != 0) {
            if (dados[7] != NULL) {
                (*lista).totalProdutos++;
                produto++;
                componentes = 0;
                (*lista).produtos = realloc((*lista).produtos, sizeof (Produto) * produto);
                (*lista).produtos[produto - 1].id = (char*) malloc(sizeof (char) * strlen(dados[0]));
                strncpy((*lista).produtos[produto - 1].id, dados[0], strlen(dados[0]));
                (*lista).produtos[produto - 1].nome = (char*) malloc(sizeof (char) * strlen(dados[1]));
                strncpy((*lista).produtos[produto - 1].nome, dados[1], strlen(dados[1]));
                (*lista).produtos[produto - 1].dimensoes = (char*) malloc(sizeof (char) * strlen(dados[2]));
                strncpy((*lista).produtos[produto - 1].dimensoes, dados[2], strlen(dados[2]));
                (*lista).produtos[produto - 1].preco = atof(dados[3]);
                (*lista).produtos[produto - 1].componentesUsados = (Componentes*) malloc(sizeof (Componentes) * (componentes + 1));
                (*lista).produtos[produto - 1].n_componentes = 0;
            } else {
                dados[4] = dados[0];
                dados[5] = dados[1];
                dados[6] = dados[2];
                dados[7] = dados[3];
            }
            componentes++;
            (*lista).produtos[produto - 1].n_componentes++;
            (*lista).produtos[produto - 1].componentesUsados = (Componentes *) realloc((*lista).produtos[produto - 1].componentesUsados, sizeof (Componentes) * (componentes + 5));
            (*lista).produtos[produto - 1].componentesUsados[componentes - 1].codMaterial = (char*) malloc(sizeof (char) * (strlen(dados[4]) + 1));
            strcpy((*lista).produtos[produto - 1].componentesUsados[componentes - 1].codMaterial, dados[4]);
            (*lista).produtos[produto - 1].componentesUsados[componentes - 1].descricao = (char*) malloc(sizeof (char) * (strlen(dados[5]) + 1));
            strcpy((*lista).produtos[produto - 1].componentesUsados[componentes - 1].descricao, dados[5]);
            (*lista).produtos[produto - 1].componentesUsados[componentes - 1].quantidade = atoi(dados[6]);
            //necessario remover quebra de linha do dados[7]
            (*lista).produtos[produto - 1].componentesUsados[componentes - 1].unidade = (char*) malloc(sizeof (char) * (strlen(dados[7]) + 1));
            strcpy((*lista).produtos[produto - 1].componentesUsados[componentes - 1].unidade, dados[7]);
        }
        i++;

    }
    free(dados);
    fclose(fp);
}

void printListaProdutos(ProdutoList lista) {
    int i, j;
    printf("Em loja exixtem %d produtos:\n", lista.totalProdutos);
    for (i = 0; i < lista.totalProdutos; i++) {
        printf("\n--%s %s %s %f Numero de componentes: %d\n", lista.produtos[i].id, lista.produtos[i].nome, lista.produtos[i].dimensoes, lista.produtos[i].preco, lista.produtos[i].n_componentes);
        for (j = 0; j < lista.produtos[i].n_componentes; j++) {
            printf("-%s %d %s %s", lista.produtos[i].componentesUsados[j].codMaterial, lista.produtos[i].componentesUsados[j].quantidade, lista.produtos[i].componentesUsados[j].descricao, lista.produtos[i].componentesUsados[j].unidade);
        }
    }
}

void writeListaProdutos(ProdutoList lista) {
    FILE *fp;
    //mudar nome do ficheiro
    fp = fopen("Tabela_Ficha_Tecnica1.csv", "w");
    if (fp == NULL) {
        puts("Erro ao abrir o ficheiro");
        return;
    }
    fprintf(fp, "Cod_Produto;Produto;Dimensoes;Pre�o;Cod_Material;Descri��o;Quantidade;Unidade\n");
    int i, j;
    for (i = 0; i < lista.totalProdutos; i++) {
        fprintf(fp, "%s;%s;%s;%f;%s;%s;%d;%s", lista.produtos[i].id, lista.produtos[i].nome, lista.produtos[i].dimensoes, lista.produtos[i].preco, lista.produtos[i].componentesUsados[0].codMaterial, lista.produtos[i].componentesUsados[0].descricao, lista.produtos[i].componentesUsados[0].quantidade, lista.produtos[i].componentesUsados[0].unidade);
        for (j = 1; j < lista.produtos[i].n_componentes; j++) {
            //necessario adicionar \n no fim do fprintf depois de remover o \n dos dados que vão para a lista
            fprintf(fp, "%s;%d;%s;%s", lista.produtos[i].componentesUsados[j].codMaterial, lista.produtos[i].componentesUsados[j].quantidade, lista.produtos[i].componentesUsados[j].descricao, lista.produtos[i].componentesUsados[j].unidade);
        }
    }
    fclose(fp);
}

void apagarDadosProduto(Produto *produto) {

    produto->estado = 0;
    produto->n_componentes = 0;
    produto->preco = 0;
    strcpy(produto->dimensoes, "");
    strcpy(produto->nome, "");
    strcpy(produto->id, "");

    produto->componentesUsados->quantidade = 0;
    strcpy(produto->componentesUsados->codMaterial, "");
    strcpy(produto->componentesUsados->descricao, "");
    strcpy(produto->componentesUsados->unidade, "");



}

void eleminarProduto(ProdutoList *produtos, Encomendas encomendas) {
    int i, k;
    int id = procurarProduto(*produtos, obterInt("Id Poduto: "));


    if (id != -1) {

        if (encomendas.totalEncomendas > 0) {
            for (i = 0; i < encomendas.totalEncomendas; i++) {
                if (*produtos->produtos[id].id == encomendas.encomendas[i].idProduto) {
                    produtos->produtos[id].estado = 0;
                    return;
                }
            }

            strcpy(produtos->produtos[id].nome, produtos->produtos[produtos->totalProdutos - 1].nome);
            strcpy(produtos->produtos[id].id, produtos->produtos[produtos->totalProdutos - 1].id);
            strcpy(produtos->produtos[id].dimensoes, produtos->produtos[produtos->totalProdutos - 1].dimensoes);
            produtos->produtos[id].n_componentes = produtos->produtos[produtos->totalProdutos - 1].n_componentes;
            produtos->produtos[id].estado = produtos->produtos[produtos->totalProdutos - 1].estado;

            strcpy(produtos->produtos[id].componentesUsados->codMaterial, produtos->produtos[produtos->totalProdutos - 1].componentesUsados->codMaterial);
            strcpy(produtos->produtos[id].componentesUsados->descricao, produtos->produtos[produtos->totalProdutos - 1].componentesUsados->descricao);
            strcpy(produtos->produtos[id].componentesUsados->unidade, produtos->produtos[produtos->totalProdutos - 1].componentesUsados->unidade);
            produtos->produtos[id].componentesUsados->quantidade = produtos->produtos[produtos->totalProdutos - 1].componentesUsados->quantidade;




            apagarDadosProduto(&produtos->produtos[produtos->totalProdutos - 1]);

            produtos->totalProdutos--;

        } else {
            printf("Produto não existe!!\n");
        }
    }
}

int procurarProduto(ProdutoList produtos, int id) {

    for (int i = 0; i < produtos.totalProdutos; i++) {
        if (id == *produtos.produtos[i].id) {
            return id;
        }
    }
    return -1;
}

void freeProdutos(ProdutoList *produtos) {
    int i, j;

    if (produtos->totalProdutos > 0) {

        for (i = 0; i < produtos->totalProdutos; i++) {

            free(produtos->produtos[i].nome);
            free(produtos->produtos[i].dimensoes);
            free(produtos->produtos[i].id);

            for (j = 0; j < produtos->produtos[i].n_componentes; j++) {

                free(produtos->produtos[i].componentesUsados->codMaterial);
                free(produtos->produtos[i].componentesUsados->descricao);
                free(produtos->produtos[i].componentesUsados->unidade);
            }
            free(produtos->produtos[i].componentesUsados);
        }

        free(produtos->produtos);

    } else {
        printf("Não existem produtos criados!!\n");
    }
}

