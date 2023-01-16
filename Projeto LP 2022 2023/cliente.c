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
#include "encomenda.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int procurarCliente(Clientes clientes, int id) {
    int i;

    for (i = 0; i < clientes.total; i++) {
        if (clientes.clientes[i].id == id) {
            return i;
        }
    }
    return -1;
}

void adicionarCliente(Clientes *clientes) {

    if ((*clientes).total == 0) {
        (*clientes).clientes = (Cliente*) malloc(sizeof (Cliente));
    } else {
        (*clientes).clientes = (Cliente*) realloc((*clientes).clientes, ((*clientes).total + 1) * sizeof (Cliente));
    }


    int id = obterInt("Id: ");

    if (procurarCliente(*clientes, id) == -1) {

        (*clientes).clientes[(*clientes).total].id = id;
        (*clientes).clientes[(*clientes).total].estado = 1;

        char buffer[SIZE_BUFFER];

        lerString(buffer, SIZE_BUFFER, "Nome: ");
        (*clientes).clientes[(*clientes).total].nome = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].nome, buffer);

        lerString(buffer, SIZE_BUFFER, "Nif: ");
        (*clientes).clientes[(*clientes).total].nif = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].nif, buffer);

        lerString(buffer, SIZE_BUFFER, "Morada: ");
        (*clientes).clientes[(*clientes).total].morada = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].morada, buffer);

        lerString(buffer, SIZE_BUFFER, "Telefone: ");
        (*clientes).clientes[(*clientes).total].telefone = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].telefone, buffer);

        lerString(buffer, SIZE_BUFFER, "Email: ");
        (*clientes).clientes[(*clientes).total].email = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].email, buffer);

        lerString(buffer, SIZE_BUFFER, "Pai­s: ");
        (*clientes).clientes[(*clientes).total].pais = malloc((strlen(buffer) + 1) * sizeof (char));
        strcpy((*clientes).clientes[(*clientes).total].pais, buffer);

        (*clientes).total++;
    }
}

void libertarMemcliente(Clientes *clientes) {
    int i;

    if (clientes->total > 0) {

        for (i = 0; i < clientes->total; i++) {

            free(clientes->clientes[i].nome);
            free(clientes->clientes[i].nif);
            free(clientes->clientes[i].morada);
            free(clientes->clientes[i].telefone);
            free(clientes->clientes[i].email);
            free(clientes->clientes[i].pais);

        }
        free(clientes->clientes);

    } else {
        printf("Não existem clientes criados!!\n");
    }
}

void imprimirCliente(Cliente cliente) {
    printf("\nId:%d\nNome:%s\nNif:%s\nMorada:%s\nTelefone:%s\nEmai:%s\nPaís:%s\n", cliente.id, cliente.nome,
            cliente.nif, cliente.morada,
            cliente.telefone, cliente.email,
            cliente.pais);
    if (cliente.estado == 1) {
        printf("Estado: ativo\n");
    } else if (cliente.estado == 0) {
        printf("Estado: desativo\n");
    }
}

void listarClientes(Clientes clientes) {
    int i;

    if (clientes.total > 0) {
        for (i = 0; i < clientes.total; i++) {
            imprimirCliente(clientes.clientes[i]);
        }
    } else {
        printf("Não existem clientes criados!!\n");
    }
}

void atualizarDadosCliente(Cliente *cliente) {

    char buffer[SIZE_BUFFER];

    lerString(buffer, SIZE_BUFFER, "Nome: ");
    cliente->nome = realloc(cliente->nome, (strlen(buffer) + 1) * sizeof (char));
    strcpy(cliente->nome, buffer);

    lerString(buffer, SIZE_BUFFER, "Nif: ");
    cliente->nif = realloc(cliente->nif, (strlen(buffer) + 1) * sizeof (char));
    strcpy(cliente->nif, buffer);

    lerString(buffer, SIZE_BUFFER, "Morada: ");
    cliente->morada = realloc(cliente->morada, (strlen(buffer) + 1) * sizeof (char));
    strcpy(cliente->morada, buffer);

    lerString(buffer, SIZE_BUFFER, "Telefone: ");
    cliente->telefone = realloc(cliente->telefone, (strlen(buffer) + 1) * sizeof (char));
    strcpy(cliente->telefone, buffer);

    lerString(buffer, SIZE_BUFFER, "Email: ");
    cliente->email = realloc(cliente->email, (strlen(buffer) + 1) * sizeof (char));
    strcpy(cliente->email, buffer);

    lerString(buffer, SIZE_BUFFER, "Pai­s: ");
    cliente->pais = realloc(cliente->pais, (strlen(buffer) + 1) * sizeof (char));
    strcpy(cliente->pais, buffer);


}

void editarCliente(Clientes *clientes) {
    int id = procurarCliente(*clientes, obterInt("Id: "));

    if (id != -1) {
        atualizarDadosCliente(&(*clientes).clientes[id]);

    } else {
        printf("Cliente não existe!!\n");
    }
}

void apagarDadosCliente(Cliente *cliente, Encomendas encomenda) {
int i;
    for (i = 0; i < encomenda.totalEncomendas; i++) {
        if (cliente->id == encomenda.encomendas[i].idCliente) {
            cliente->estado = 0;
            return;
        }
    }
    cliente->id = 0;
    strcpy(cliente->nome, "");
    strcpy(cliente->nif, "");
    strcpy(cliente->morada, "");
    strcpy(cliente->telefone, "");
    strcpy(cliente->email, "");
    strcpy(cliente->pais, "");
    cliente->estado = 0;
}

void eliminarCliente(Clientes *clientes, Encomendas encomenda) {
    int i, k;
    int id = procurarCliente(*clientes, obterInt("Id: "));

    if (id != -1) {
        for (i = id; i < clientes->total - 1; i++) {
            clientes->clientes[i] = clientes->clientes[i + 1];
        }
        apagarDadosCliente(&clientes->clientes[i], encomenda);
    } else {
        printf("Cliente não existe!!\n");
    }
}


//Não esta a escrever no ficheiro

void writeClientes(Clientes clientes) {
    FILE *fp;
int i;
    fp = fopen("Lista_Clientes.csv", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro!!\n");
        return;
    }
    fprintf(fp, "id;nome;nif;morada;telefone;email;pais;estado");
    for ( i = 0; i < clientes.total; i++) {
        fprintf(fp, "\n%d;%s;%s;%s;%s;%s;%s;%d"
                , clientes.clientes[i].id
                , clientes.clientes[i].nome
                , clientes.clientes[i].nif
                , clientes.clientes[i].morada
                , clientes.clientes[i].telefone
                , clientes.clientes[i].email
                , clientes.clientes[i].pais
                , clientes.clientes[i].estado);

    }
    fclose(fp);
}

void readClientes(Clientes *clientes) {
    FILE *fp;
    char **dados;
    fp = fopen("Lista_Clientes.csv", "r");

    if (fp == NULL) {
        puts("Erro ao abrir o ficheiro");
        return;
    }
    int i = 0;

    if ((*clientes).total == 0) {
        (*clientes).clientes = (Cliente*) malloc(sizeof (Cliente));
    } else {
        (*clientes).clientes = (Cliente*) realloc((*clientes).clientes, ((*clientes).total + 1) * sizeof (Cliente));
    }
    char buffer[1024];
    dados = (char**) malloc(sizeof (char*) * 8);

    while (fgets(buffer, 1024, fp)) {



        dados[0] = NULL;
        dados[1] = NULL;
        dados[2] = NULL;
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

                (*clientes).clientes[(*clientes).total].id = atoi(dados[0]);
                (*clientes).clientes[(*clientes).total].nome = malloc((strlen(dados[1]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].nome, dados[1]);
                (*clientes).clientes[(*clientes).total].nif = malloc((strlen(dados[2]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].nif, dados[2]);
                (*clientes).clientes[(*clientes).total].morada = malloc((strlen(dados[3]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].morada, dados[3]);
                (*clientes).clientes[(*clientes).total].telefone = malloc((strlen(dados[4]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].telefone, dados[4]);
                (*clientes).clientes[(*clientes).total].email = malloc((strlen(dados[5]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].email, dados[5]);
                (*clientes).clientes[(*clientes).total].pais = malloc((strlen(dados[6]) + 1) * sizeof (char));
                strcpy((*clientes).clientes[(*clientes).total].pais, dados[6]);
                (*clientes).clientes[(*clientes).total].estado = atoi(dados[7]);
                (*clientes).total++;
            }

        }
        i++;

    }
    free(dados);
    fclose(fp);
}
