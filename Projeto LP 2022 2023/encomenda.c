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
#include "produto.h"
#include "cliente.h"
#include "input.h"
#include <stdio.h>
#include <string.h>

void registarEncomenda(Encomendas *encomendas, Clientes listaClientes, ProdutoList produtos){
    
    if((*encomendas).totalEncomendas == 0){
        (*encomendas).encomendas = (Encomendas*)malloc(sizeof(Encomendas));
    }else{
        (*encomendas).encomendas = (Encomendas*)realloc((*encomendas).encomendas, (*encomendas).totalEncomendas + 1 * sizeof(Encomendas));
    }
    
    listarClientes(listaClientes);
    
    int idCliente, idProduto;
    
    idCliente = obterInt("Id Cliente: ");
    
    if(procurarCliente(listaClientes, idCliente) == -1){
        printf("Cliente não existe!!\n");
    }else{
        printListaProdutos(produtos);
    
        idProduto = obterInt("Que produto deseja comprar(escreva só o último numero do produto): ");
    
        if(idProduto > produtos.totalProdutos || idProduto <= 0){
            printf("Produto não existe!!");
        
        }else{
            encomendas->encomendas[encomendas->totalEncomendas].quantidade = obterInt("Quanto deseja comprar: ");
            encomendas->encomendas[encomendas->totalEncomendas].totalPagar = encomendas->encomendas[encomendas->totalEncomendas].quantidade * produtos.produtos[idProduto - 1].preco;
            
            encomendas->encomendas[encomendas->totalEncomendas].data.dia = obterInt("Dia: ");
            encomendas->encomendas[encomendas->totalEncomendas].data.mes = obterInt("Mes: ");
            encomendas->encomendas[encomendas->totalEncomendas].data.ano = obterInt("Ano: ");
            
            encomendas->encomendas[encomendas->totalEncomendas].idCliente = idCliente;
            
            encomendas->encomendas->nomeProduto = (Encomendas*)malloc(sizeof(Encomendas));
            encomendas->encomendas->nomeCliete = (Encomendas*)malloc(sizeof(Encomendas));
            
            encomendas->encomendas[encomendas->totalEncomendas].nomeProduto = produtos.produtos[idProduto - 1].nome;
            encomendas->encomendas[encomendas->totalEncomendas].nomeCliete = listaClientes.clientes[idCliente - 1].nome;
         
            encomendas->totalEncomendas++;
        }
        
    }
} 
    
    
 


void imprimirEncomendas(Encomendas listaEncomendas){
    int i;
    for(i = 0; i < listaEncomendas.totalEncomendas; i++){
        printf("Id: %d----Cliente: %s----Produto: %s---Preço: %f---Qunatidade: %d----Data: %d/%d/%d",  listaEncomendas.encomendas[i].idCliente, 
                                                                                                        listaEncomendas.encomendas[i].nomeCliete, 
                                                                                                        listaEncomendas.encomendas[i].nomeProduto, 
                                                                                                        listaEncomendas.encomendas[i].totalPagar,
                                                                                                        listaEncomendas.encomendas[i].quantidade,
                                                                                                        listaEncomendas.encomendas[i].data.dia, 
                                                                                                        listaEncomendas.encomendas[i].data.mes, 
                                                                                                        listaEncomendas.encomendas[i].data.ano);
    }
}



void imprimirEncomendaCliente(Encomendas listaEncomendas, Clientes listaClientes){
    int idCliente;
    int i;
    
    idCliente = obterInt("Id: ");
    
    if(procurarCliente(listaClientes, idCliente) == -1){
        puts("Cliente não encontrado");
        return;
    }
    
    for(i = 0; i < listaEncomendas.totalEncomendas; i++){
        if(listaEncomendas.encomendas[i].idCliente == idCliente){
            printf("Id: %d----Cliente: %s----Produto: %s---Preço: %f---Qunatidade: %d----Data: %d/%d/%d",  listaEncomendas.encomendas[i].idCliente, 
                                                                                                        listaEncomendas.encomendas[i].nomeCliete, 
                                                                                                        listaEncomendas.encomendas[i].nomeProduto, 
                                                                                                        listaEncomendas.encomendas[i].totalPagar,
                                                                                                        listaEncomendas.encomendas[i].quantidade,
                                                                                                        listaEncomendas.encomendas[i].data.dia, 
                                                                                                        listaEncomendas.encomendas[i].data.mes, 
                                                                                                        listaEncomendas.encomendas[i].data.ano);
        }else{
            puts("Cliente não tem encomendas");
        }
    }
}


void writeEncomendas(Encomendas encomendas){
    FILE *fp;
    
    fp = fopen("Lista_Encomendas.txt", "w");
    if(fp == NULL){
        printf("Erro ao abrir um ficheiro!!\n");
        return;
    }
    
    for(int i = 0; i < encomendas.totalEncomendas; i++){
        fprintf(fp, "Id: %d\n", encomendas.encomendas[i].idCliente);
        fprintf(fp, "Cliente: %s\n", encomendas.encomendas[i].nomeCliete);
        fprintf(fp, "Poduto: %s\n", encomendas.encomendas[i].nomeProduto);
        fprintf(fp, "Peço: %f\n", encomendas.encomendas[i].totalPagar);
        fprintf(fp, "Quantidade: %d\n", encomendas.encomendas[i].quantidade);
        fprintf(fp, "Data: %d-%d-%d\n", encomendas.encomendas[i].data.dia, encomendas.encomendas[i].data.mes, encomendas.encomendas[i].data.mes);
        fprintf(fp, "\n\n");
    }
    fclose(fp);
}
