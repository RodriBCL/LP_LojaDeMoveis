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

#include "cliente.h"
#include "produto.h"

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    int id;
    int idCliente;
    int idProduto;
    char nomeCliete[50];
    char nomeProduto[50];
    int quantidade;
    float totalPagar;
    Data data;
}Encomenda;

typedef struct{
    Encomenda *encomendas;
    int totalEncomendas;
}Encomendas;

void registarEncomenda(Encomendas *Encomendas, Clientes listaClientes, ProdutoList produtos);

void imprimirEncomendas(Encomendas *listaEncomendas);

void imprimirEncomendaCliente(Encomendas *listaEncomendas, Clientes *listaClientes);

#endif /* ENCOMENDA_H */