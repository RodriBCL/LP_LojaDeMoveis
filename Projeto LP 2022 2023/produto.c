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

void remove_newline(char *s)
{
    char t[100];
    int i, j;
    for (i = 0, j = 0; i < strlen(s); i++)
    {
        if (s[i] != '\n')
        {
            t[j] = s[i];
            j++;
        }
    }
    t[j] = '\0';
    strcpy(s, t);
}

void readListaProdutos(ProdutoList *lista){
    FILE *fp;
    Produto *produto;
    Componentes componentes; 
    char **dados;
    size_t len = 500;
    ssize_t lido = 0;
    char *linha = NULL;
    fp = fopen("Tabela_Ficha_Tecnica.csv", "r");

    if(fp == NULL){
        puts("Erro ao abrir o ficheiro");
        return;
    }
    int i = 0;
    int j = 0;
        
    char *c1;
    char *c2;
    char *c3;
    char *c4;
    char *c5;
    char *c6;
    char *c7;
    char *c8;
    (*lista).produtos = malloc (sizeof(ProdutoList)); 
    
    char buffer[1024];
    while (fgets(buffer, 1024, fp))
    {
        dados = malloc(sizeof(char*) * 8);
        char *column = strtok(buffer, ";");
        int k = 0;
        while (column)
        {
            dados [k++] = column;
            column = strtok(NULL, ";");
        }
  
        if(i != 0){
            if(dados[7] != NULL){
                c1 = dados[0];
                c2 = dados[1];
                c3 = dados[2];
                c4 = dados[3];
                c5 = dados[4];
                c6 = dados[5];
                c7 = dados[6];
                c8 = dados[7];        
                j = 0;
                (*lista).totalProdutos++;
                
                produto.id = malloc(sizeof(char)*(strlen(c1)+ 1));
                strcpy(produto.id, c1);
                produto.nome = malloc(sizeof(char)*(strlen(c2)+ 1));
                strcpy(produto.nome, c2);
                produto.dimensoes = malloc(sizeof(char)*(strlen(c3)+ 1));
                strcpy(produto.dimensoes, c3);
                produto.preco = atof(c4);
                produto.componentesUsados = (Componentes*)malloc(sizeof(Componentes));
                (*lista).produtos = realloc ((*lista).produtos,sizeof(Produto)*((*lista).totalProdutos + 1));
                (*lista).produtos[(*lista).totalProdutos - 1] = produto; 
                //printf("%d %s \n",(*lista).totalProdutos, dados[7]);
                
                
            }else{
                c5 = dados[0];
                c6 = dados[1];
                c7 = dados[2];
                c8 = dados[3];
            }
   
            componentes.codMaterial = malloc(sizeof(char)*(strlen(c5)+ 1));
            strcpy(componentes.codMaterial, c5);
            componentes.descricao = malloc(sizeof(char)*(strlen(c6)+ 1));
            strcpy(componentes.descricao, c6);
            componentes.quantidade = atoi (c7);
            componentes.unidade = malloc(sizeof(char)*(strlen(c8)+ 1));
            strcpy(componentes.unidade, c8);
            produto.componentesUsados = (Componentes*)realloc(produto.componentesUsados, sizeof(Componentes)*(j + 1));
            produto.componentesUsados[j] = componentes;
            
            printf("%s %d %s %s\n", produto.id, (*lista).produtos[i].n_componentes, produto.componentesUsados[j].descricao, componentes.descricao);
            (*lista).produtos[i].n_componentes = j++;
        }
        
        //Depois disto n.componentes = 0
        i++;

        dados [0] = NULL;
        dados [1] = NULL;
        dados [2] = NULL;
        dados [3] = NULL;
        dados [4] = NULL;
        dados [5] = NULL;
        dados [6] = NULL;
        dados [7] = NULL;

        free(dados); 
    }
    printListaProdutos(lista);
    fclose(fp);
}


void printListaProdutos(ProdutoList *lista){
    int i, j;
 
    printf("Em loja exixtem:\n");
    for(i = 0; i < lista->totalProdutos; i++){
        printf("\n%s %s %s %f\n", lista->produtos[i].id, lista->produtos[i].nome, lista->produtos[i].dimensoes, lista->produtos[i].preco);
        printf("%d", lista->produtos[i].n_componentes);

        for(j = 0; j < lista->produtos[i].n_componentes; j++){
            printf("PUTA");
            printf("%s ", lista->produtos[i].componentesUsados[j].codMaterial);
        }

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

    for(i = 0; i < lista->totalProdutos; i++){
        fprintf(fp, "%s %s %f", lista->produtos[i].id, lista->produtos[i].nome, lista->produtos[i].preco);
    }
    fclose(fp);
}


