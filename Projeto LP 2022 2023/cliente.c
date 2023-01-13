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
#include <assert.h>


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
        (*clientes).clientes = (Cliente*)malloc(sizeof(Cliente));
    }else{
        (*clientes).clientes = (Cliente*)realloc((*clientes).clientes, ((*clientes).total + 1) * sizeof(Cliente));
    }

    
    int id = obterInt("Id: ");
    
    if(procurarCliente(*clientes, id) == -1){
         
        (*clientes).clientes[(*clientes).total].id = id;
        
         char buffer[SIZE_BUFFER];
        
         lerString(buffer, SIZE_BUFFER, "Nome: ");
         (*clientes).clientes[(*clientes).total].nome = malloc((strlen(buffer) + 1) * sizeof(char));
         strcpy((*clientes).clientes[(*clientes).total].nome, buffer);

         lerString(buffer, SIZE_BUFFER, "Nif: ");
         (*clientes).clientes[(*clientes).total].nif = malloc((strlen(buffer) + 1) * sizeof(char));
         strcpy((*clientes).clientes[(*clientes).total].nif, buffer);
              
         lerString(buffer, SIZE_BUFFER, "Morada: ");
         (*clientes).clientes[(*clientes).total].morada = malloc((strlen(buffer) + 1) * sizeof(char));
         strcpy((*clientes).clientes[(*clientes).total].morada, buffer);
               
         lerString(buffer, SIZE_BUFFER, "Telefone: ");
         (*clientes).clientes[(*clientes).total].telefone = malloc((strlen(buffer) + 1) * sizeof(char));
         strcpy((*clientes).clientes[(*clientes).total].telefone, buffer);
             
         lerString(buffer, SIZE_BUFFER, "Email: ");
         (*clientes).clientes[(*clientes).total].email = malloc((strlen(buffer) +1 ) * sizeof(char));
         strcpy((*clientes).clientes[(*clientes).total].email, buffer);
       
         lerString(buffer, SIZE_BUFFER, "Pai­s: ");
         (*clientes).clientes[(*clientes).total].pais = malloc((strlen(buffer) +1 ) * sizeof(char));
         strcpy((*clientes).clientes[(*clientes).total].pais, buffer);
        
        return (*clientes).total++;
    }
    return -1;
}


void libertarMemcliente(Clientes *clientes){
    int i;
    
    if(clientes->total > 0){
     
        for(i = 0; i < clientes->total; i++){
            
            free(clientes->clientes[i].nome);
            free(clientes->clientes[i].nif);   
            free(clientes->clientes[i].morada);   
            free(clientes->clientes[i].telefone);   
            free(clientes->clientes[i].email);   
            free(clientes->clientes[i].pais); 
            
        }
        free(clientes->clientes);
        
    }else{
        printf("Não existem clientes criados!!\n");
    }
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
     
    char buffer[SIZE_BUFFER];
    
         lerString(buffer, SIZE_BUFFER, "Nome: ");
         cliente->nome = realloc(cliente->nome, (strlen(buffer) + 1) * sizeof(char));
         strcpy(cliente->nome, buffer);
         
         lerString(buffer, SIZE_BUFFER, "Nif: ");
         cliente->nif = realloc(cliente->nif, (strlen(buffer) + 1) * sizeof(char));
         strcpy(cliente->nif, buffer);
         
         lerString(buffer, SIZE_BUFFER, "Morada: ");
         cliente->morada = realloc(cliente->morada, (strlen(buffer) + 1) * sizeof(char));
         strcpy(cliente->morada, buffer);
         
         lerString(buffer, SIZE_BUFFER, "Telefone: ");
         cliente->telefone = realloc(cliente->telefone, (strlen(buffer) + 1) * sizeof(char));
         strcpy(cliente->telefone, buffer);
         
         lerString(buffer, SIZE_BUFFER, "Email: ");
         cliente->email = realloc(cliente->email, (strlen(buffer) + 1) * sizeof(char));
         strcpy(cliente->email, buffer);
         
         lerString(buffer, SIZE_BUFFER, "Pai­s: ");
         cliente->pais= realloc(cliente->pais, (strlen(buffer) + 1) * sizeof(char));
         strcpy(cliente->pais, buffer);
         
         
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

//Não esta a escrever no ficheiro
void writeClientes(Clientes clientes){
    FILE *fp;
    
    fp = fopen("Lista_Clientes.txt", "w");
    if(fp == NULL){
        printf("Erro ao abrir o ficheiro!!\n");
        return;
    }
    fprintf("id;nome;nif;morada;telefone;email;pais\n");
    for(int i = 0; i < clientes.total; i++){
        fprintf(fp,"%d;%s;%s;%s;%s;%s;%s\n" 
                                         ,clientes.clientes[i].id
                                         ,clientes.clientes[i].nome
                                         ,clientes.clientes[i].nif
                                         ,clientes.clientes[i].morada
                                         ,clientes.clientes[i].telefone
                                         ,clientes.clientes[i].email
                                         ,clientes.clientes[i].pais);        
        
    }
   fclose(fp); 
}



void readClientes(Clientes *clientes){
    FILE *fp;
    
    Cliente cliente;
    char **dados;
    size_t len = 500;
    ssize_t lido = 0;
    char *linha = NULL;
    
    int clientenum = 0;
    

    fp = fopen("Lista_Clientes.csv", "r");

    if(fp == NULL){
        puts("Erro ao abrir o ficheiro");
        } 
        return;
        int i = 0;
        
         if((*clientes).total == 0){
        (*clientes).clientes = (Cliente*)malloc(sizeof(Cliente));
         }else{
        (*clientes).clientes = (Cliente*)realloc((*clientes).clientes, ((*clientes).total + 1) * sizeof(Cliente));
         }
        char buffer[1024];
        while (fgets(buffer, 1024, fp)){
                
                dados =(char*) malloc(sizeof(char*) * 8);
                dados[0] = NULL;
                dados[1] = NULL;
                dados[2] = NULL;
                dados[3] = NULL;
                dados[4] = NULL;
                dados[5] = NULL;
                dados[6] = NULL;

                char *column = strtok(buffer, ";");
                int k = 0;
                
           while (column)
        {
            dados[k++] = column;
            column = strtok(NULL, ";");
        }
		if(i != 0){
        
            if(dados[6] != NULL){
                (*clientes).clientes[(*clientes).total].nome = malloc((strlen(dados) + 1) * sizeof(char));
    
    
          
    }else{
                
    }
              
    } 
      i++;
        free(dados);
    }
    fclose(fp);
    }