/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   produto.c
 * Author: rodri
 * 
 * Created on 20 de dezembro de 2022, 16:01
 */

#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	ret = malloc(sizeof(char) * (len + 1));
	if (!s || !ret)
		return (NULL);
	i = start;
	j = 0;
	while (i < strlen(s) && j < len)
	{
		ret[j++] = s[i++];
	}
	ret[j] = '\0';
	return (ret);
}

static int	check_num_strings(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
	}
	return (j + 1);
}

static int	less_lines(char const *s, char c, char **ret)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			ret[k++] = ft_substr(s, j, i - j);
		}
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	j;
	size_t	k;

	k = 0;
	if (!s)
		return (NULL);
	j = check_num_strings(s, c);
	ret = (char **)malloc(sizeof(char *) * (j + 1));
	if (!ret)
		return (NULL);
	k = less_lines(s, c, ret);
	ret[k] = NULL;
	return (ret);
}


void readListaProdutos(ProdutoList *lista){
    FILE *fp;
    Produto produto;
    Componentes componentes; 
    char **dados;
    size_t len = 500;
    ssize_t lido = 0;
    char *linha = NULL;
    fp = fopen("Tabela_Ficha_Tecnica.csv", "r");

    if(fp == NULL){
        puts("Erro ao abrir o ficheiro");
        return;
    }
    int i = 0;
    int j = 0;
        
    char *c1  ;
    char *c2 ;
    char *c3 ;
    char *c4 ;
    char *c5 ;
    char *c6 ;
    char *c7 ;
    char *c8 ;
        
    
    while ((lido = getline(&linha, &len, fp)) != -1){
        
         dados = ft_split(linha, ';');
        
        
        if(i != 0){
            
            if(dados[7] != NULL){
                c1 = dados[0];
                c2 = dados[1];
                c3 = dados[2];
                c4 = dados[3];
                c5 = dados[4];
                c6 = dados[5];
                c7 = dados[6];
                c8 = dados[7];
               
                j = 0;
                (*lista).totalProdutos++;
                produto.id = malloc(sizeof(char)*strlen(c1));
                strcpy(produto.id, c1);
                produto.nome = malloc(sizeof(char)*strlen(c2));
                strcpy(produto.nome, c2);
                produto.dimensoes = malloc(sizeof(char)*strlen(c3));
                strcpy(produto.dimensoes, c3);
                produto.preco = atof(c4);
                produto.componentesUsados = (Componentes*)malloc(sizeof(Componentes));
                
                
                
            }else{
                c5 = dados[0];
                c6 = dados[1];
                c7 = dados[2];
                c8 = dados[3];
                
            }
             printf("%s %s",c5,c8);  
            componentes.codMaterial = malloc(sizeof(char)*strlen(c5));
            strcpy(componentes.codMaterial, c5);
            componentes.descricao = malloc(sizeof(char)*strlen(c6));
            strcpy(componentes.descricao, c6);
            componentes.quantidade = atoi (c7);
            componentes.unidade = malloc(sizeof(char)*strlen(c8));
            strcpy(componentes.unidade, c8);
            produto.componentesUsados = realloc(produto.componentesUsados, sizeof(Componentes)*j);
            produto.componentesUsados[j] = componentes;
            j++;
            
        }
        i++;
    }
    printf("%s %s %s %f %s %s %i %s", produto.id, produto.nome, produto.dimensoes, produto.preco, produto.componentesUsados[2].codMaterial, produto.componentesUsados[2].descricao, produto.componentesUsados[2].quantidade, produto.componentesUsados[2].unidade);
    fclose(fp);
}

void printListaProdutos(ProdutoList *lista){
    int i;
    printf("Em loja exixtem:\n");
    for(i = 0; i < lista->totalProdutos; i++){
        printf("%s %s %f\n", lista->produtos[i].id, lista->produtos[i].nome, lista->produtos[i].preco);
    }
}


void writeListaProdutos(ProdutoList *lista){
    FILE *fp;
    Produto produto;
    int i;
    fp = fopen("Tabela_Ficha_Tecnica.csv", "w");

    if(fp == NULL){
        puts("Erro ao abrir o ficheiro");
        return;
    }

    for(i = 0; i < lista->totalProdutos; i++){
        fprintf(fp, "%d %s %f", lista->produtos[i].id, lista->produtos[i].nome, lista->produtos[i].preco);
    }
    fclose(fp);
}


