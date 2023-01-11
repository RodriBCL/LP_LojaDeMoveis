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

void registarEncomenda(Encomendas *Encomendas, Clientes listaClientes, ProdutoList produtos){
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
            Encomendas->encomendas[Encomendas->totalEncomendas].quantidade = obterInt("Quanto deseja comprar: ");
            Encomendas->encomendas[Encomendas->totalEncomendas].totalPagar = Encomendas->encomendas[Encomendas->totalEncomendas].quantidade * produtos.produtos[idProduto - 1].preco;
            Encomendas->encomendas[Encomendas->totalEncomendas].data.dia = obterInt("Dia: ");
            Encomendas->encomendas[Encomendas->totalEncomendas].data.mes = obterInt("Mes: ");
            Encomendas->encomendas[Encomendas->totalEncomendas].data.ano = obterInt("Ano: ");
         
            Encomendas->totalEncomendas++;
        }
        
    }
} 
    
    
 


void imprimirEncomendas(Encomendas *listaEncomendas){
    int i;
    for(i = 0; i < listaEncomendas->totalEncomendas; i++){
        printf("Encomenda numero: %d----Cliente: %s----Id: %d----Produto: %s----Data: %d/%d/%d", listaEncomendas->encomendas[i].id, 
                                                                                            listaEncomendas->encomendas[i].nomeCliete, 
                                                                                            listaEncomendas->encomendas[i].idCliente, 
                                                                                            listaEncomendas->encomendas[i].nomeProduto, 
                                                                                            listaEncomendas->encomendas[i].data.dia, 
                                                                                            listaEncomendas->encomendas[i].data.mes, 
                                                                                            listaEncomendas->encomendas[i].data.ano);
    }
}


void imprimirEncomendaCliente(Encomendas *listaEncomendas, Clientes *listaClientes){
    int idCliente;
    int i;
    
    idCliente = obterInt("Id: ");
    
    if(procurarCliente(*listaClientes, idCliente) == -1){
        puts("Cliente não encontrado");
        return;
    }
    
    for(i = 0; i < listaEncomendas->totalEncomendas; i++){
        if(listaEncomendas->encomendas[i].idCliente == idCliente){
            printf("Encomenda numero: %d----Cliente: %s----Id: %d----Produto: %s----Data: %d/%d/%d", listaEncomendas->encomendas[i].id, 
                                                                                                listaEncomendas->encomendas[i].nomeCliete, 
                                                                                                listaEncomendas->encomendas[i].idCliente, 
                                                                                                listaEncomendas->encomendas[i].nomeProduto, 
                                                                                                listaEncomendas->encomendas[i].data.dia, 
                                                                                                listaEncomendas->encomendas[i].data.mes, 
                                                                                                listaEncomendas->encomendas[i].data.ano);
        }else{
            puts("Cliente não tem encomendas");
        }
    }
}
