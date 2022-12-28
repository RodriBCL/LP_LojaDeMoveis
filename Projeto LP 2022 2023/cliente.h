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

#define SIZE_NOME 100
#define SIZE_NIF 10
#define SIZE_MORADA 100
#define SIZE_TELEFONE 10
#define SIZE_EMAIL 100
#define SIZE_PAIS 100

typedef struct 
{
    int id;
    char nome[SIZE_NOME];
    char nif[SIZE_NIF];
    char morada[SIZE_MORADA];
    char telefone[SIZE_TELEFONE];
    char email[SIZE_EMAIL];
    char pais[SIZE_PAIS];
} Cliente;


typedef struct 
{
    Cliente clientes[100];
    int total;
} Clientes;

int procurarCliente(Clientes clientes, int id);

int adicionarCliente(Clientes *clientes);

void imprimirCliente(Cliente cliente);

void listarClientes(Clientes clientes);

void atualizarDadosCliente(Cliente *cliente);

void editarCliente(Clientes *clientes);

void apagarDadosCliente(Cliente *cliente);

void eliminarCliente(Clientes *clientes);

void inserirCliente(Clientes *clientes);


#endif /* CLIENTE_H */
