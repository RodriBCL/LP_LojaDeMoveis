/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   cliente.h
 * Author: rodri
 *
 * Created on 7 de dezembro de 2022, 20:12
 */


#ifndef CLIENTE_H
#define CLIENTE_H

#define SIZE_BUFFER 100

typedef struct 
{
    int id;
    char *nome;
    char *nif;
    char *morada;
    char *telefone;
    char *email;
    char *pais;
    int estado;
} Cliente;


typedef struct 
{
    Cliente *clientes;
    int total;
    int maxClientes;
} Clientes;

#include "encomenda.h"

int procurarCliente(Clientes clientes, int id);

void adicionarCliente(Clientes *clientes);

void libertarMemcliente(Clientes *clientes);

void imprimirCliente(Cliente cliente);

void listarClientes(Clientes clientes);

void atualizarDadosCliente(Cliente *cliente);

void editarCliente(Clientes *clientes);

void eliminarCliente(Clientes *clientes, Encomendas encomenda);

void writeClientes(Clientes clientes);

void readClientes(Clientes *clientes);

#endif /* CLIENTE_H */
