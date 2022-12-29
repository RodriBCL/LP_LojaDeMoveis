/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   cliente.c
 * Author: rodri
 * 
 * Created on 7 de dezembro de 2022, 20:12
 */

#include "cliente.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int procurarCliente(Clientes clientes, int id){
    int i;
    
    for(i = 0; i < clientes.total; i++){
        if(clientes.clientes[i].id == id){
        return i;
        }
    }
    return -1;
}


int adicionarCliente(Clientes *clientes){

    if((*clientes).total == 0){
        (*clientes).clientes = (Cliente*)malloc(sizeof(Clientes));
    }else{
        (*clientes).clientes = (Cliente*)realloc((*clientes).clientes, ((*clientes).total + 1) * sizeof(Clientes));
    }

    
    int id = obterInt("Id: ");
    
    if(procurarCliente(*clientes, id) == -1){
         
        (*clientes).clientes[(*clientes).total].id = id;
         
        lerString((*clientes).clientes[(*clientes).total].nome, SIZE_NOME, "Nome: ");
         
        lerString((*clientes).clientes[(*clientes).total].nif, SIZE_NIF, "Nif: ");
         
        lerString((*clientes).clientes[(*clientes).total].morada, SIZE_MORADA, "Morada: ");
         
        lerString((*clientes).clientes[(*clientes).total].telefone, SIZE_TELEFONE, "Telefone: ");
         
        lerString((*clientes).clientes[(*clientes).total].email, SIZE_EMAIL, "Email: ");
         
        lerString((*clientes).clientes[(*clientes).total].pais, SIZE_PAIS, "País: ");
        
        

        return clientes->total++;
    }
    return -1;
}


void imprimirCliente(Cliente cliente){
    printf("Id:%d\nNome:%s\nNif:%s\nMorada:%s\nTelefone:%s\nEmai:%s\nPaís:%s\n",cliente.id, cliente.nome, 
                                                                              cliente.nif, cliente.morada, 
                                                                              cliente.telefone, cliente.email,
                                                                              cliente.pais);
}


void listarClientes(Clientes clientes){
    int i;
    
    if(clientes.total > 0){
        for(i = 0; i < clientes.total; i++){
            imprimirCliente(clientes.clientes[i]);
        }
    }else{
        printf("Não existem clientes criados!!\n");
    }
}


void atualizarDadosCliente(Cliente *cliente){
     lerString((*cliente).nome, SIZE_NOME, "Nome: ");
     lerString((*cliente).nif, SIZE_NIF, "Nif: ");        
     lerString((*cliente).morada, SIZE_MORADA, "Morada: ");        
     lerString((*cliente).telefone, SIZE_TELEFONE, "Telefone: ");        
     lerString((*cliente).email, SIZE_EMAIL, "Email: ");        
     lerString((*cliente).pais, SIZE_PAIS, "País: ");
}


void editarCliente(Clientes *clientes){
    int id = procurarCliente(*clientes, obterInt("Id: "));
    
    if(id != -1){
       atualizarDadosCliente(&(*clientes).clientes[id]);
        
    }else{
        printf("Cliente não existe!!\n");
    }
}


void apagarDadosCliente(Cliente *cliente){
    cliente->id = 0;
    strcpy(cliente->nome, "");
    strcpy(cliente->nif, "");
    strcpy(cliente->morada, "");
    strcpy(cliente->telefone, "");
    strcpy(cliente->email, "");
    strcpy(cliente->pais, "");
}


void eliminarCliente(Clientes *clientes){
    int i;
    int id = procurarCliente(*clientes, obterInt("Id: "));
    
    if(id != -1){
        for(i = id; i < clientes->total - 1; i++){
            clientes->clientes[i] = clientes->clientes[i + 1];
        }
        apagarDadosCliente(&clientes->clientes[i]);
        
        clientes->total--;
        
    }else{
        printf("Cliente não existe!!\n");
    }
}




void inserirCliente(Clientes *clientes){
    if(clientes->total < 100){
        if(adicionarCliente(clientes) == -1){
            printf("O cliente já existe\n");   
        }
        
    }else{
        printf("Erro a lista de clietes está cheia\n");
        printf("%d", clientes->total);
    }
}



