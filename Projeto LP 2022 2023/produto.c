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
                strcpy((*lista).produtos[produto - 1].id, dados[0]);
                (*lista).produtos[produto - 1].nome = (char*) malloc(sizeof (char) * strlen(dados[1]));
                strcpy((*lista).produtos[produto - 1].nome, dados[1]);
                (*lista).produtos[produto - 1].dimensoes = (char*) malloc(sizeof (char) * strlen(dados[2]));
                strcpy((*lista).produtos[produto - 1].dimensoes, dados[2]);
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
            (*lista).produtos[produto - 1].componentesUsados = (Componentes *) realloc((*lista).produtos[produto - 1].componentesUsados, sizeof (Componentes) * (componentes + 1));
            (*lista).produtos[produto - 1].componentesUsados[componentes - 1].codMaterial = (char*) malloc(sizeof (char) * strlen(dados[4]));
            strcpy((*lista).produtos[produto - 1].componentesUsados[componentes - 1].codMaterial, dados[4]);
            (*lista).produtos[produto - 1].componentesUsados[componentes - 1].descricao = (char*) malloc(sizeof (char) * strlen(dados[5]));
            strcpy((*lista).produtos[produto - 1].componentesUsados[componentes - 1].descricao, dados[5]);
            (*lista).produtos[produto - 1].componentesUsados[componentes - 1].quantidade = atoi(dados[6]);
            //necessario remover quebra de linha do dados[7]
            (*lista).produtos[produto - 1].componentesUsados[componentes - 1].unidade = (char*) malloc(sizeof (char) * strlen(dados[7]));
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


/*
int procurarProduto(ProdutoList produtos, int id){
    
    for(int i = 0; i < produtos.totalProdutos; i++){
        if(id == produtos.produtos[i].id){
            return id;
        }
    }
    return -1;
}

 */