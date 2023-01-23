/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   input.h
 *@Author: Rodrigo
 *@Author: Manuel
 *@Author: Mara
 * Created on 5 de dezembro de 2022, 12:16
 */

#ifndef INPUT_H
#define INPUT_H


/**
 * @brief Esta função solicita um valor inteiro, lê a entrada do usuário usando a função "scanf" e armazena-o na variável "valor". Em seguida chama a função "cleanImputBuffer" para limpar quaisquer caracteres extras do buffer de entrada.
 * @param msg mensagem que vai aparecer na consola
 * @return a variável "valor".
 * É usada para validar que a entrada do usuário é um inteiro e descartar quaisquer outros caracteres que o usuário possa ter digitado após o inteiro.
 */
int obterInt(char *msg);

/**
 * @brief Esta função solicita ao usuário um valor float, lê a entrada do usuário usando a função "scanf" e armazena-o na variável "valor.
 * Verifica se a entrada é válida, comparando o valor de "valor" com os valores mínimo e máximo fornecidos.
 * Se a entrada for inválida, a função exibe uma mensagem de erro.
 * Chama a função "cleanInputBuffer" para limpar caracteres extras do buffer de entrada e solicita novamente ao usuário. 
 * Continua até receber uma entrada válida.
 * @param minValor
 * @param maxValor
 * @param msg mensagem que vai aparecer na consola
 * @return retorna a variável "valor"
 */
float obterFloat(float minValor, float maxValor, char *msg);

/**
 * @brief Esta função solicita ao usuário um valor, lê a entrada do usuário e armazena-o na variável "valor".
 * Verifica se a entrada é válida, comparando o valor de "valor" com os valores mínimo e máximo fornecidos.
 * Se a entrada for inválida, a função exibe uma mensagem de erro, chama a função "cleanInputBuffer" para limpar quaisquer caracteres extras do buffer de entrada e solicita novamnete ao usuário.
 * Continua até receber uma entrada válida.
 * @param minValor.
 * @param maxValor
 * @msg mensagem que vai aparecer na consola
 * @return a variável "valor" 
 */
double obterDouble(double minValor, double maxValor, char *msg);

/**
 * @brief Esta função solicita ao usuário um caracter, lê a entrada do usuário usando a função "getchar" e armazena-o na variável "valor".
 * Chama a função "cleanInputBuffer" para limpar caracteres extras do buffer de entrada.
 * É usado para validar que a entrada do usuário é um caracter e descarta outros caracteres que o usuário possa ter digitado após o caracter.
 * @param msg mensagem que vai ser introduzida
 * @return a variável "valor"
 */
char obterChar(char *msg);


/**
 * Esta função pede ao usuário uma string, lê a entrada do usuário usando a função "fgets".
 * @param string, armazena aqui a função "fgets".
 * @param tamanho, limita o número máximo de caracteres que podem ser lidos.
 * Primeiro limpa o fluxo stdin, depois usa a função "fgets" para ler uma string de ate "tamanho" caracteres e armazená-la na variável "string".
 * Se o último caracter na string é um caracter de uma nova linha, substitui-o por um terminador nulo para que a string seja terminada corretamente.
 * Se não, chama a função "clenaInputBuffer" para impar caracteres extras do buffer de entrada.
 */
void lerString(char *string, unsigned int tamanho, char *msg);


/**
 *@brief Esta função é usada para limpar o buffer de entrada.
 * Lê todos os caracteres do buffer de entrada até atingir um caractere de nova linha ou fim do arquivo, e descarta todos os caracteres lidos.
 */
void cleanInputBuffer();


#endif /* INPUT_H */
