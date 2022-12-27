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

void registarEncomenda(Encomendas *Encomendas, Clientes *listaClientes){
    Encomenda encomenda;
    int idCliente;
    
    encomenda.id = Encomendas->totalEncomendas + 1;
    
    idCliente = obterInt("Insira o id do cliente: ");
    
    if(procurarCliente(*listaClientes, idCliente) == -1){
        puts("Cliente não encontrado");
        return;
    }
    
    encomenda.idCliente = idCliente;
    strcpy(encomenda.nomeCliete, listaClientes->clientes[listaClientes->total].nome);
    
    printf("Insira o nome do produto: ");
    fgets(encomenda.nomeProduto, 50, stdin);
    
    encomenda.quantidade = obterInt("Insira a quantidade: ");
    
    encomenda.data.dia = obterInt("Insira o dia: ");
    encomenda.data.mes = obterInt("Insira o mes: ");
    encomenda.data.ano = obterInt("Insira o ano: ");
    
    Encomendas->encomendas[Encomendas->totalEncomendas] = encomenda;
    Encomendas->totalEncomendas++;
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
