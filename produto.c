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

int procurarProduto(ProdutoList *lista, int id){
    int i;
    for(i = 0; i < lista->totalProdutos; i++){
        if(lista->produtos[i].id == id){
            return i;
        }
    }
    return -1;
}

void readListaProdutos(ProdutoList *lista){
    FILE *fp;
    Produto produto;
    fp = fopen("Tabela_Ficha_Tecnica.csv", "r");

    if(fp == NULL){
        puts("Erro ao abrir o ficheiro");
        return;
    }

    while(fscanf(fp, "%d %s %f", &produto.id, produto.nome, &produto.preco) != EOF){
        lista->produtos[lista->totalProdutos] = produto;
        lista->totalProdutos++;
    }
    fclose(fp);
}

void printListaProdutos(ProdutoList *lista){
    int i;
    printf("Em loja exixtem:\n");
    for(i = 0; i < lista->totalProdutos; i++){
        printf("%d %s %f\n", lista->produtos[i].id, lista->produtos[i].nome, lista->produtos[i].preco);
    }
}


void writeListaProdutos(ProdutoList *lista){
    FILE *fp;
    Produto produto;
    int i;
    fp = fopen("Tabela_Ficha_Tecnica.csv", "w");

    if(fp == NULL){
        puts("Erro ao abrir o ficheiro");
        return;
    }

    for(int i = 0; i < lista->totalProdutos; i++){
        fprintf(fp, "%d %s %f", lista->produtos[i].id, lista->produtos[i].nome, lista->produtos[i].preco);
    }
    fclose(fp);
}