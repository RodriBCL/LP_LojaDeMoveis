/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   menu.h
 * Author: rodri
 *
 * Created on 7 de dezembro de 2022, 20:12
 */

#ifndef MENU_H
#define MENU_H
#include "cliente.h"
#include "encomenda.h"
#include "produto.h"

void menu(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto);
void menuAdmin(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto);
void menuCliente(Clientes *clientes, Encomendas *encomenda, ProdutoList *produto);
void sairPrograma();


#endif /* MENU_H */
