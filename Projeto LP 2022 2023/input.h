/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   input.h
 * Author: rodri
 *
 * Created on 16 de dezembro de 2022, 10:00
 */

#ifndef INPUT_H
#define INPUT_H

int obterInt(char *msg);

float obterFloat(float minValor, float maxValor, char *msg);

double obterDouble(double minValor, double maxValor, char *msg);

char obterCahr(char *msg);

void lerString(char *string, unsigned int tamanho, char *msg);

void cleanInputBuffer();


#endif /* INPUT_H */
