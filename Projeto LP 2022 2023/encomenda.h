/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   encomenda.h
 *@Author: Rodrigo
 *@Author: Manuel
 *@Author: Mara
 * Created on 5 de dezembro de 2022, 12:16
 */

#ifndef ENCOMENDA_H
#define ENCOMENDA_H

typedef struct {
    int dia;
    int mes;
    int ano;
    int semana;
} Data;

typedef struct {
    int id;
    int idCliente;
    char idProduto[7];
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


/** 
 *@brief Esta função serve para registar uma encomenda.A função verifica se o número atual de encomendas é igual ao numero maximo de encomendas que podem ser armazenadas.
 * Se for, ele aumen ta o número maximo de encomendas em 3 e realoca memória para estrutura Encomendas para armazenar as encomendas adicionais.
 * Cria uma variável 'idProduto' que é um array de caracteres de 7 caracteres, para armazenar o id do produto. Também cria uma variável inteira 'i'.
 * @param encomendas
 * @param listaClientes
 * @param produtos
 */
void registarEncomenda(Encomendas *encomendas, Clientes listaClientes, ProdutoList produtos);


/**
 *@brief  Esta função tem um loop for que é usado ºara percorrer o array de encomendas na estrutura "listaEncomendas".
 * A data é acessada através da estrutura "data" dentro da estrutura "encomendas", que contem campos separados para dia, mês e ano.
 * @param listaEncomendas
 */

void imprimirEncomendas(Encomendas listaEncomendas);

/**
 *@brief Se o id fornecido nao for encontrado na lista de clientes a função imprime a mensagem e retorna. Se o cliente for encontrado a função percorre a lista de pedidos e encontra todos os pedidos que têm o mesmo id do cliente passado.
 * @param listaEncomendas
 * @param listaClientes
 * @param id for -1, solicita que o usuário insira um id para o cliente.
 */
void imprimirEncomendaCliente(Encomendas listaEncomendas, Clientes listaClientes, int id);


/**
 * @brief Esta função abre o arquivo chamado "Lista_Encomendas.csv", usando a função "fopen".
 * Verifica se o arquivo foi aberto com sucesso, caso contrário imprime uma mensagem de erro e sai.
 * A função usa a função "fprintf" para gravar o cabeçalho dp arquivo CSV, qie inclui os campos de Encomendas.
 * Usa um loop for para percorrer o array de encomendas na estrutura "encomendas2 e grava os dados de cada encomenda no arquivo CSV com a função "fprintf".
 * A função escreve os dados das encomendas no ficheiro. 
 * A função "fclose" é usada para fechar o arquivo.
 * @param encomendas
 */
void writeEncomendas(Encomendas encomendas);


/**
 *@brief  A função abre o arquivo e verifica se foi aberto com sucesso, caso contrario imprime uma mensgaem de erro e sai.
 * É usada a função "fgets" para ler o arquivo linha por linha e a função "strtok" para dividir a linha em colunas usando o ";" como delimitador.
 * É usado o while em loop para iterar pelo arquivo e para cada linha.
 * A função aloca a memória para a struct encomendas, e copia os dados do arquivo para a struct. Se o número de encomendas en+xceder o tamanho maximo, a função usa realloc para aumentar o tamanho do array de encomendas.
 * A função "free()" é usada para liberar memória alocada.
 * @param encomendas 
 */
void readEncomendas(Encomendas *encomendas);


/**
 *@brief  Inicia dois arrays, um chamado de "repeticoes" com duas colunas. A primeira, armazena o número de pedidos feitos por um cliente. A segunda armazena o ID do cliente.
 * O for interno itera pelo array de clientes, o externo pelo array de encomendas.
 * A cada iterção a função compara o id do cliente no array listaClientes. Se os ids coincidirem, aumenta o numero de pedidos feitos por aquele cliente no array repeticoes.
 * É usado um algoritmo para classificar a matriz de repetições com base no número de pedidos feitos pelo cliente em ordem decrescente.
 * É usado um novo loop for para percorrer o array repeticoes, para cada iteração ela usa a função "procurarCliente" para encontrar a posição dp cliente no array listaClientes.
 * Se a posição for encontrada, imprime a posição, o número de pedidos feitos pelo cliente e os dados do cliente com a função "imprimirCliente".
 * @param encomendas
 * @param listaClientes
 */
void ListarClientePorEncomenda(Encomendas encomendas, Clientes listaClientes);


/**
 * @brief A cada iteração a função usa a "free()" para desalocar a memória que foi previamente alocada para os campos nomeCliente e nomeProduto.
 * @param encomendas do tipo "Encomendas" como um apontador. este usa um loop for para percorrer o array de encomendas na estrutura "encomendas".
 * Se o totalEncomendas for maior que 0 usa a função free para desalocar memória que foi alocada anteriormente para o array encomendas. Caso contrario imprime uma mensagem.
 * Esta função é usada para evitar fugas de memória, que podem causar falhas ou mau funcionamento.
 */
void freeEncomendas(Encomendas *encomendas);


/**
 * @brief Tem como objetivo encontrar e imprimir o produto que foi pedido em maior numero de vezes na lista de encomendas
 * Inicializa um array "contadorProduto" com o tamanho de totalProdutos em ProdutoList e uma variável inteira "vezesEncomendadas" a 0.
 * Faz um loop pelas encomendas e aumneta a contagem do produto correspondente no array "contadorProduto" para encontar o produto com maior contagem e armazena a sua posição na variável "posicaoProdutomaisEncomendado" e imprime o nome e a contagem desse produto.
 * @param produtos
 * @param encomendas
 */

void printProdutoMaisEncomendado(ProdutoList produtos, Encomendas encomendas);

/**
 *@brief  A função recebe uma stuct chamada "Encomendas", que tem como objetivo encontrar o mês com mais pedidos.
 * Possui um array de strings chamado "meses" que mapeia o número do mês para o nome do mês correspondente em português.
 * Imprime o mês com mais pedidps e a quantidade de pedidps realizados naquele mÊs.
 * @param encomendas, inicializa um array chamado "encomendasMes" com todos os elementos definidos a 0, depois percorre todos os pedidos na estrutura e incrementa o elemento no array "encomendasMes" correspondente ao mês de cada pedido.
 * Percorre o array "encomendasMes" novamnete para encontar o valor mais alto, que representa o mês com mais oedidos.
 */
void printMesMaisEncomendas(Encomendas encomendas);


/**
 *@brief Recebe duas structs "Encomendas" e "ProdutoList". É usado para listar os componentes e as quantidades necessárias para uma semana específica em um ano específico.
 *Faz um loop por todos os pedidos e verifica se o pedido foi feito no ano e na semana de entrada, se sim,faz um loop por todos os produtos da estrutura "ProdutoList" e verifica se o nome do produto do pedidp corresponde ao nome de qualquer um dos produtos na estrutura "ProdutoList".
 * Se encontrar, percorre os componentes do produto e calcula a quantidade total de cada componente necessário multiplicando a quantidade do produto no pedido pela quantidade de cada componente usado no produto.
 * Se o componente ja tiver sido adicionado á lista, incrementa a quantidade desse componene, se nao estiver ele adicona á lista.
 * Imprime a lista de componentes e as suas quantidades.
 * @param encomendas
 * @param produtos
 */
void listarComponentesPorSemana(Encomendas encomendas, ProdutoList produtos);


/**
 *@brief  Recebe uma string chamada "codigo" como argumento.
 * @param codigo Inicializa uma variavel int chamada "idProduto" e copia a string "codigo" para um array de caracteres chamado "cod"
 * Altera o primeiro caracter da matriz "cod" para '0'.
 * usa a funçãi "atoi" para converter o array "cod" para um int e atribiu o resultado á variavel "idProduto".
 * @return idProduto.
 */
int codProdutoParaInt(char* codigo);


/**
 *@brief A função procura a ordem com o ID informado através da função "procurarEncomenda", e caso encontre copia as informações da ultima ordem do array para a posiçao da ordem apagada e reduz o numero total de ordens para 1.
 * Liberta memória alocada para o nome do pedido excluido e o nome do produto. Caso o pedido com o ID fornecido nao seja encontrado, a função imprime uma mensagem a informar que o pedido nao existe.
 * @param encomendas, imprime todos os pedidos atuais usando uma função chamada "imprimirEncomendas",de seguida solicita ao usuário um ID para um pedido a ser excluido.
 */
void apagarEncomenda(Encomendas *encomendas);


/**
 *@brief  A função itera através do array de encomendas na estrutura "encomendas" usando um loop for. A cada iteração compara o id da encomenda atual com o id de entrada.
 * @param encomendas
 * @param id
 * @return -1, caso o id nao seja encontrado, que indicca que a encomenda nao foi encontrada no array. se os ids forem iguais retorna o índice atual do array.
 */
int procurarEncomenda(Encomendas encomendas, int id);


/**
 * @brief É apresentado ao usuario as opçoes das alteraçoes que ele quer fazer.Caso escreva uma opção invalida dá a opçao de voltar novamente ao menu.
 * @param encomenda
 */
void atualizarDadosEncomenda(Encomenda *encomenda);


/**
 *@brief Edita os dados da encomenda.
 * Pede o id da encomenda, caso esta nao exista imprime a mensagem.Caso exista chama a função "atualizarDadosEncomenda".
 * @param encomendas
 */
void editarEncomenda(Encomendas *encomendas);

#endif /* ENCOMENDA_H */