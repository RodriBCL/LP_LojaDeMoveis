/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   input.c
 * Author: rodri
 * 
 * Created on 16 de dezembro de 2022, 10:00
 */

#include "input.h"
#include <stdio.h>
#include <string.h>

#define VALOR_INVALIDO "O valor inserido é invalido"

void cleanInputBuffer(){
    char ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}


int obterInt(char *msg){
    int valor;
    
   
    
    printf("%s", msg);
    scanf("%d", &valor);
    
    cleanInputBuffer();
    
    return valor;
}


float obterFloat(float minValor, float maxValor, char *msg){
    float valor;
    
    printf("%s",msg);
    
    while(scanf("%f", &valor) != 1 || valor < minValor || valor > maxValor){
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf("%s",msg);
    }
    cleanInputBuffer();
    return valor;
}


double obterDouble(double minValor, double maxValor, char *msg){
    double valor;
    
    printf("%s",msg);
    
    while(scanf("%lf", &valor) != 1 || valor < minValor || valor > maxValor){
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf("%s",msg);
    }
    cleanInputBuffer();
    return valor;
}


char obterChar(char *msg){
    char valor;
    
    printf("%s",msg);
    valor = getchar();
    cleanInputBuffer();
    return valor;
}


void lerString(char *string, unsigned int tamanho, char *msg){
    fflush(stdin);
    printf("%s",msg);
    if(fgets(string, tamanho, stdin) != NULL){
        unsigned int len = strlen(string) - 1;
        if(string[len] == '\n'){
            string[len] = '\0';
            
        }else{
            cleanInputBuffer();
        }
    }
}
