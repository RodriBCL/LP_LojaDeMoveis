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

#endif /* ENCOMENDA_H */

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    int id;
    int idCliente;
    char nomeCliete[50];
    char nomeProduto[50];
    int quantidade;
    Data data;
}Encomenda;

typedef struct{
    Encomenda *encomendas;
    int totalEncomendas;
}Encomendas;

void registarEncomenda(Encomendas *Encomendas, Clientes *listaClientes);

void imprimirEncomendas(Encomendas *listaEncomendas);

void imprimirEncomendaCliente(Encomendas *listaEncomendas, Clientes *listaClientes);