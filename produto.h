/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   produto.h
 * Author: rodri
 *
 * Created on 20 de dezembro de 2022, 16:01
 */

#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct{
    char descricao[100];
    int quantidade;
}Componentes;

typedef struct{
    int id;
    char nome[50];
    float preco;
    Componentes componentesUsados;
}Produto;

typedef struct{
    Produto produtos[10];
    int totalProdutos;
}ProdutoList;

int procurarProduto(ProdutoList *lista, int id);

void readListaProdutos(ProdutoList *lista);

void printListaProdutos(ProdutoList *lista);

void writeListaProdutos(ProdutoList *lista);

#endif /* PRODUTO_H */
