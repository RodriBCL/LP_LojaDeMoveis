/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   encomenda.h
 * Author: rodri
 *
 * Created on 7 de dezembro de 2022, 20:12
 */

#ifndef ENCOMENDA_H
#define ENCOMENDA_H



typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int id;
    int idCliente;
    int idProduto;
    char *nomeCliente;
    char *nomeProduto;
    int quantidade;
    float totalPagar;
    Data data;
} Encomenda;

typedef struct {
    Encomenda *encomendas;
    int totalEncomendas;
    int maxEncomendas;
} Encomendas;

#include "cliente.h"
#include "produto.h"

void registarEncomenda(Encomendas *encomendas, Clientes listaClientes, ProdutoList produtos);

void imprimirEncomendas(Encomendas listaEncomendas);

void imprimirEncomendaCliente(Encomendas listaEncomendas, Clientes listaClientes, int id);

void writeEncomendas(Encomendas encomendas);

void readEncomendas(Encomendas *encomendas);

void ListarClientePorEncomenda(Encomendas encomendas, Clientes listaClientes);

void freeEncomendas(Encomendas *encomendas);

void printProdutoMaisEncomendado(ProdutoList produtos, Encomendas encomendas);

#endif /* ENCOMENDA_H */