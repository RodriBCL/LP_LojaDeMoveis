/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   produto.h
 *@Author: Rodrigo
 *@Author: Manuel
 *@Author: Mara
 * Created on 5 de dezembro de 2022, 12:16
 */

#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct{
    char *descricao;
    int quantidade;
    char *codMaterial;
    char *unidade;
}Componentes;

typedef struct{
    char *id;
    char *nome;
    char *dimensoes;
    float preco;
    int n_componentes;
    Componentes *componentesUsados;
    int estado;
}Produto;

typedef struct{
    Produto *produtos;
    int totalProdutos;
    int maxProdutos;
}ProdutoList;

#include "encomenda.h"

/**
 * @brief Esta função procura um produto na lista de produtos.
 * @param produtos struct chamado ProdutoList, contem informações sobre os produtos.
 * @param id do produto, para uma string (char*), este está a ser procurado.Se o ID for encontrado, a função retorna o ID do produto encontrado.
 * @return strinh "NULL", que indica o produto não foi encontrado na lista.
 */
char* procurarProduto(ProdutoList produtos, char *idProduto);

/**
 * @brief Esta função procura o índice de um produto na lista de produtos.
 * @param ProdutoList, contem informações sobre os produtos
 * @param id, apontador para uma string (char*), contem o ID do produto que está a ser procurado.
 * A função procura na lista de produtos, e compara cada ID do produto com o Id fornecido.
 * @return o índice do produro que é encontrado na lista de produtos, se o ID não for encontrado. Caso contrario, a função retorna -1, que indica que o produto não foi encontrado na lista.
 */
int procurarProdutoIndice(ProdutoList produtos, char *id);
/**
 *@brief lê a lista de produtos do sistema e armazena em produto.
 * @param lista apontador para a lista de produtos.
 */
void readListaProdutos(ProdutoList *lista);

/**
 *@brief Este  código é responsável por imprimir a lista de produtos armazenada na estrutura.
 * Ele usa um loop duplo para percorrer a lista e imprimir as informações dos produtos e seus componentes. 
 * @param lista de produtos.
 */
void printListaProdutos(ProdutoList lista);

/**
 *@brief Esta função tem como objetivo escrever a lista de produtos num arquivo CSV.
 * @param ProdutoList contem a lista de prdoutos.
 * Em repetição, é percorrida a lista de produtos e são escritos os dados de cada produto no arquivo, incluindo os componentes usados. 
 */
void writeListaProdutos(ProdutoList lista);

/**
 * @brief Esta função exclui um produto da lista de produtos.
 * @param produtos um apontador para a struct ProdutoList, que contem as informações sobre os produtos.
 * @param encomendas apontador para a struct Encomendas que contem as informações sobre as encomendas.
 * A função primeiro pede ao usuário para inserir o ID do produto que deseja exluir e, em seguida, usa
 * o ID fornecido para procurar o produto na lista. Se o produto for encontrado e não estiver sendo usado
 * em nenhuma encomenda, a função excluirá o produto da lista e copia o ultimo elemento da lista para a posição 
 * do elemento excluído e, em seguida, libera a memória alocada para o elemento exclúido. 
 * Se o produto for encontrado e estiver a ser usado numa encomenda, a função marca o produto como excluído, mas não o remove da lista.
 */
void eleminarProduto(ProdutoList *produtos, Encomendas encomendas);

/**
 *@brief  Esta função desaloca a memória alocada para produtos na lista de produtos.
 * @param produtos , contem informações sobre os produtos.
 * A função verifica primeiro se existem produtos na lista e, se houver, percorre cada produto e liberta a memória alocada para o seu nome, dimensões, Id e componentes usados.
 * Também liberta a memória alocada para o array de componentes usados pelo produto, Depois que todos os produtos foram processados, a função liberta a memória alocada para o array de produtos,
 * Se não houver produtos na lisa, a função impeimw uma mensagem que indica que não há produtos a libertar.
 */
void freeProdutos(ProdutoList *produtos);

/**
 * @brief É apresentado ao usuario as opçoes das alteraçoes que ele quer fazer.Caso escreva uma opção invalida dá a opçao de voltar novamente ao menu.
 * @param produto
 */
void atualizarDadosProduto(Produto *produto);

/**
 * @briefEdita os dados do produto.
 * @param produtos
 */
void editarProduto(ProdutoList *produtos);


#endif /* PRODUTO_H */
