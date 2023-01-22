/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   encomenda.c
 * Author: rodri
 * 
 * Created on 7 de dezembro de 2022, 20:12
 */

#include "encomenda.h"
#include "cliente.h"
#include "produto.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void registarEncomenda(Encomendas *encomendas, Clientes listaClientes, ProdutoList produtos) {
    char idProduto[7];
    int i;

    if ((*encomendas).totalEncomendas == (*encomendas).maxEncomendas) {
        (*encomendas).maxEncomendas += 3;
        (*encomendas).encomendas = (Encomenda*) realloc((*encomendas).encomendas, ((*encomendas).maxEncomendas) * sizeof (Encomenda));
    }

    listarClientes(listaClientes);

    int idCliente, indiceProduto = procurarProdutoIndice(produtos, idProduto);

    idCliente = obterInt("Id Cliente: ");

    int indiceCliente = procurarCliente(listaClientes, idCliente);

    if (indiceCliente == -1) {
        printf("Cliente não existe!!\n");

    } else if (listaClientes.clientes[indiceCliente].estado == 0) {
        printf("Cliente está desativado!!\n");

    } else {
        printListaProdutos(produtos);
        lerString(idProduto, 7, "Id do produto que deseja comprar: ");
        //indiceProduto = procurarProdutoIndice(produtos, idProduto);

        //for (i = 0; i < produtos.totalProdutos; i++) {
            if (procurarProduto(produtos, idProduto) == idProduto) {


                (*encomendas).encomendas[(*encomendas).totalEncomendas].quantidade = obterInt("Quantas unidades deseja comprar: ");
                (*encomendas).encomendas[(*encomendas).totalEncomendas].totalPagar = (*encomendas).encomendas[(*encomendas).totalEncomendas].quantidade * produtos.produtos[indiceProduto - 1].preco;

                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.dia = obterInt("Dia: ");
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.mes = obterInt("Mes: ");
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.ano = obterInt("Ano: ");

                
                printf("Testew1");

                (*encomendas).encomendas[(*encomendas).totalEncomendas].idCliente = idCliente;
                printf("Testew2");
                //(*encomendas).encomendas[(*encomendas).totalEncomendas].idProduto = (char*) malloc((strlen(produtos.produtos[indiceProduto - 1].id) + 1) * sizeof (char));
                strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].idProduto, idProduto);
                printf("Testew3");

                (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente = (char*) malloc((strlen(listaClientes.clientes[indiceCliente].nome) + 1) * sizeof (char));
                printf("Testew4");
                strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente, listaClientes.clientes[indiceCliente].nome);
                printf("Testew5");

                (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeProduto = (char*) malloc((strlen(produtos.produtos[indiceProduto - 1].nome) + 1) * sizeof (char));
                printf("Testew6");
                strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeProduto, produtos.produtos[indiceProduto - 1].nome);
                printf("Testew7");

                encomendas->totalEncomendas++;
                printf("Testew8");
                (*encomendas).encomendas[((*encomendas).totalEncomendas) - 1].id = encomendas->totalEncomendas;
                printf("Testew9");

            
                imprimirEncomendaCliente(*encomendas, listaClientes, idCliente);

                struct tm data_tm;
                char buffer[80];


                data_tm.tm_year = (*encomendas).encomendas->data.ano - 1900;
                data_tm.tm_mon = (*encomendas).encomendas->data.mes - 1; 
                data_tm.tm_mday = (*encomendas).encomendas->data.dia;

                mktime(&data_tm);
                strftime(buffer, sizeof (buffer), "%V", &data_tm);
                (*encomendas).encomendas->data.semana = atoi(buffer);
             
                
                return;

            } else {
                printf("Produto não existe!!");
            }
        //}
    }
}


void imprimirEncomendas(Encomendas listaEncomendas) {
    int i;
    for (i = 0; i < listaEncomendas.totalEncomendas; i++) {
        printf("Encomenda nº: %d\nID Cliente: %d----Cliente: %s\nProduto: %s---Preço: %f---Qunatidade: %d\nData: %d/%d/%d\n",
                listaEncomendas.encomendas[i].id,
                listaEncomendas.encomendas[i].idCliente,
                listaEncomendas.encomendas[i].nomeCliente,
                listaEncomendas.encomendas[i].nomeProduto,
                listaEncomendas.encomendas[i].totalPagar,
                listaEncomendas.encomendas[i].quantidade,
                listaEncomendas.encomendas[i].data.dia,
                listaEncomendas.encomendas[i].data.mes,
                listaEncomendas.encomendas[i].data.ano);
    }
}

void imprimirEncomendaCliente(Encomendas listaEncomendas, Clientes listaClientes, int id) {
    int idCliente;
    int i, k;

    if (id == -1) {
        idCliente = obterInt("Id Cliente: ");
    } else {
        idCliente = id;
    }

    if (procurarCliente(listaClientes, idCliente) == -1) {
        puts("Cliente não encontrado");
        return;
    }

    for (i = 0; i < listaEncomendas.totalEncomendas; i++) {
        if (listaEncomendas.encomendas[i].idCliente == idCliente) {
            printf("Encomenda nº: %d\nID Cliente: %d----Cliente: %s\nProduto: %s---Preço: %f---Qunatidade: %d\nData: %d/%d/%d\n",
                    listaEncomendas.encomendas[i].id,
                    listaEncomendas.encomendas[i].idCliente,
                    listaEncomendas.encomendas[i].nomeCliente,
                    listaEncomendas.encomendas[i].nomeProduto,
                    listaEncomendas.encomendas[i].totalPagar,
                    listaEncomendas.encomendas[i].quantidade,
                    listaEncomendas.encomendas[i].data.dia,
                    listaEncomendas.encomendas[i].data.mes,
                    listaEncomendas.encomendas[i].data.ano);
            k++;
        }
    }
    if (k == 0) {
        puts("Cliente não tem encomendas");
    }
}

void writeEncomendas(Encomendas encomendas) {
    FILE *fp;
    int i;
    fp = fopen("Lista_Encomendas.csv", "w");
    if (fp == NULL) {
        printf("Erro ao abrir um ficheiro!!\n");
        return;
    }
    fprintf(fp, "idEncomenda;idCliente;idProduto;nomeCliente;nomeProduto;totalPagar;quantidade;dataDia;dataMes;dataAno;dataSemana");
    for (i = 0; i < encomendas.totalEncomendas; i++) {
        fprintf(fp, "\n%d;%d;%s;%s;%s;%f;%d;%d;%d;%d;%d",
                encomendas.encomendas[i].id,
                encomendas.encomendas[i].idCliente,
                encomendas.encomendas[i].idProduto,
                encomendas.encomendas[i].nomeCliente,
                encomendas.encomendas[i].nomeProduto,
                encomendas.encomendas[i].totalPagar,
                encomendas.encomendas[i].quantidade,
                encomendas.encomendas[i].data.dia,
                encomendas.encomendas[i].data.mes,
                encomendas.encomendas[i].data.ano,
                encomendas.encomendas[i].data.semana);
    }
    fclose(fp);
}

void readEncomendas(Encomendas *encomendas) {
    FILE *fp;
    char **dados;
    fp = fopen("Lista_Encomendas.csv", "r");

    if (fp == NULL) {
        puts("Erro ao abrir o ficheiro");
        return;
    }
    int i = 0;


    char buffer[1024];
    dados = (char**) malloc(sizeof (char*) * 11);

    while (fgets(buffer, 1024, fp)) {


        dados[0] = NULL;
        dados[1] = NULL;
        dados[2] = NULL;
        dados[3] = NULL;
        dados[4] = NULL;
        dados[5] = NULL;
        dados[6] = NULL;
        dados[7] = NULL;
        dados[8] = NULL;
        dados[9] = NULL;
        dados[10] = NULL;


        char *column = strtok(buffer, ";");
        int k = 0;

        while (column) {
            dados[k++] = column;
            column = strtok(NULL, ";");
        }
        if (i != 0) {

            if (dados[9] != NULL) {

                if ((*encomendas).totalEncomendas == (*encomendas).maxEncomendas) {
                    (*encomendas).maxEncomendas += 3;
                    (*encomendas).encomendas = (Encomenda*) realloc((*encomendas).encomendas, ((*encomendas).maxEncomendas) * sizeof (Cliente));
                }

                (*encomendas).encomendas[(*encomendas).totalEncomendas].idCliente = atoi(dados[1]);
                strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].idProduto, dados[2]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente = (char*) malloc((strlen(dados[3]) + 1) * sizeof (char));
                strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeCliente, dados[3]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].nomeProduto = (char*) malloc((strlen(dados[4]) + 1) * sizeof (char));
                strcpy((*encomendas).encomendas[(*encomendas).totalEncomendas].nomeProduto, dados[4]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].quantidade = atoi(dados[5]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].totalPagar = atof(dados[6]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.dia = atoi(dados[7]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.mes = atoi(dados[8]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.ano = atoi(dados[9]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].id = atoi(dados[0]);
                (*encomendas).encomendas[(*encomendas).totalEncomendas].data.semana = atoi(dados[10]);

                (*encomendas).totalEncomendas++;
            }

        }
        i++;
    }
    free(dados);
    fclose(fp);
}

void freeEncomendas(Encomendas *encomendas) {
    int i;

    if (encomendas->totalEncomendas > 0) {
        for (i = 0; i < encomendas->totalEncomendas; i++) {

            free(encomendas->encomendas[i].nomeCliente);
            free(encomendas->encomendas[i].nomeProduto);

        }
        free(encomendas->encomendas);

    } else {
        printf("Não existem encomendas criadas\n");
    }
}

void ListarClientePorEncomenda(Encomendas encomendas, Clientes listaClientes) {
    int i, j, temp;
    int repeticoes[listaClientes.total][2];

    for (i = 0; i < listaClientes.total - 1; i++) {
        repeticoes[i][0] = 0;
    }

    for (i = 0; i < listaClientes.total - 1; i++) {
        repeticoes[i][1] = listaClientes.clientes[i].id;
    }

    for (i = 0; i < encomendas.totalEncomendas; i++) {
        for (j = 0; j < listaClientes.total; j++) {
            if (encomendas.encomendas[i].idCliente == listaClientes.clientes[j].id) {
                repeticoes[j][0]++;
            }
        }
    }
    for (i = 0; i < listaClientes.total - 1; i++) {
        for (j = 0; j < listaClientes.total - i - 1; j++) {
            if (repeticoes[j][0] < repeticoes[j + 1][0]) {
                temp = repeticoes[j][0];
                repeticoes[j][0] = repeticoes[j + 1][0];
                repeticoes[j + 1][0] = temp;
                temp = repeticoes[j][1];
                repeticoes[j][1] = repeticoes[j + 1][1];
                repeticoes[j + 1][1] = temp;
            }
        }
    }


    for (i = 0; i < listaClientes.total; i++) {
        temp = procurarCliente(listaClientes, repeticoes[i][1]);
        if (temp != -1) {
            printf("Posição:%d", i);
            printf("\nNúmero de encomendas:%d", repeticoes[i][0]);
            imprimirCliente(listaClientes.clientes[temp]);
        }
    }
}

int procurarEncomenda(Encomendas encomendas, int id) {
    int i;

    for (i = 0; i < encomendas.totalEncomendas; i++) {
        if (encomendas.encomendas[i].id == id) {
            return i;
        }
    }
    return -1;
}

void printProdutoMaisEncomendado(ProdutoList produtos, Encomendas encomendas) {
    int contadorProduto[produtos.totalProdutos];
    int posicaoProdutoMaisEncomendado = 0;
    int vezesEncomendadas = 0;
    int i;

    for (i = 0; i < produtos.totalProdutos; i++) {
        contadorProduto[i] = 0;
    }

    for (i = 0; i < encomendas.totalEncomendas; i++) {

        contadorProduto[(procurarProdutoIndice(produtos, encomendas.encomendas[i].idProduto)) - 1] += encomendas.encomendas[i].quantidade;

    }

    for (i = 0; i < produtos.totalProdutos; i++) {
        if (contadorProduto[i] > vezesEncomendadas) {
            vezesEncomendadas = contadorProduto[i];
            posicaoProdutoMaisEncomendado = i;
        }
    }

    printf("Produto mais encomendado: %s\n", produtos.produtos[posicaoProdutoMaisEncomendado].nome);
    printf("Quantidade: %d\n", vezesEncomendadas);

}

void apagarEncomenda(Encomendas *encomendas) {
    int i, k;
    imprimirEncomendas(*encomendas);

    printf("Eliminar Encomenda:\n");
    int id = procurarEncomenda(*encomendas, obterInt("Insira o Id da encomenda que pertende eliminar: "));

    if (id != -1) {

        strcpy(encomendas->encomendas[id].nomeCliente, encomendas->encomendas[encomendas->totalEncomendas - 1].nomeCliente);
        strcpy(encomendas->encomendas[id].nomeProduto, encomendas->encomendas[encomendas->totalEncomendas - 1].nomeProduto);
        strcpy(encomendas->encomendas[id].idProduto, encomendas->encomendas[encomendas->totalEncomendas - 1].idProduto);
        encomendas->encomendas[id].id = encomendas->encomendas[encomendas->totalEncomendas - 1].id;
        encomendas->encomendas[id].idCliente = encomendas->encomendas[encomendas->totalEncomendas - 1].idCliente;
        //encomendas->encomendas[id].idProduto = encomendas->encomendas[encomendas->totalEncomendas - 1].idProduto;
        encomendas->encomendas[id].quantidade = encomendas->encomendas[encomendas->totalEncomendas - 1].quantidade;
        encomendas->encomendas[id].totalPagar = encomendas->encomendas[encomendas->totalEncomendas - 1].totalPagar;
        encomendas->encomendas[id].data.dia = encomendas->encomendas[encomendas->totalEncomendas - 1].data.dia;
        encomendas->encomendas[id].data.mes = encomendas->encomendas[encomendas->totalEncomendas - 1].data.mes;
        encomendas->encomendas[id].data.ano = encomendas->encomendas[encomendas->totalEncomendas - 1].data.ano;
        encomendas->encomendas[id].data.ano = encomendas->encomendas[encomendas->totalEncomendas - 1].data.semana;

        //Dar free nos apontadores da encomenda
        encomendas->totalEncomendas--;

    } else {
        printf("Encomenda não existe!!\n");

    }
}

void printMesMaisEncomendas(Encomendas encomendas) {
    int encomendasMes[12];
    int i;
    int maisEncomendasMes = 0, maisEncomendas = 0;

    for (i = 0; i < 12; i++) {
        encomendasMes[i] = 0;
    }

    for (i = 0; i < encomendas.totalEncomendas; i++) {
        encomendasMes[(encomendas.encomendas[i].data.mes) - 1]++;
    }

    for (i = 0; i < 12; i++) {
        if (encomendasMes[i] > maisEncomendas) {
            maisEncomendas = encomendasMes[i];
            maisEncomendasMes = i;
        }
    }

    char *meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    printf("Mês com mais encomendas: %s\n", meses[maisEncomendasMes]);
    printf("Numero de encomendas: %d\n", maisEncomendas);
}

void listarComponentesPorSemana(Encomendas encomendas, int semana, ProdutoList produtos) {
    int i, j, quantidade, k, linasInicial = 20, l, linhas = 50, idProdutoint, componentesnum = 0, tamanho = 0;
    char idInteiro[5];
    char idProduto[6];

    int** componentes = (int**) malloc(linhas * sizeof (int*));
    for (int i = 0; i < linhas; i++) {
        componentes[i] = (int*) malloc(2 * sizeof (int));
    }

    for (i = 0; i < encomendas.totalEncomendas; i++) {
        if (encomendas.encomendas[i].data.semana == semana) {
            for (j = 0; j < produtos.totalProdutos; j++) {
                if (strcmp(encomendas.encomendas[i].nomeProduto, produtos.produtos[j].nome) == 0) {
                    for (k = 0; k < produtos.produtos[j].n_componentes; k++) {
                        quantidade = encomendas.encomendas[i].quantidade * produtos.produtos[j].componentesUsados[k].quantidade;
                        for (l = 0; l < linhas; l++) {
                            idProdutoint = codProdutoParaInt(produtos.produtos[j].componentesUsados[k].codMaterial);
                            if (idProdutoint == componentes[l][1]) {
                                componentes[l][0] += quantidade;
                                componentesnum++;
                            } else if (l == linhas - 1) {
                                linhas += 3;
                                componentes = (int**) realloc(componentes, linhas * sizeof (int*));
                                componentes[l + 1][1] = idProdutoint;
                                componentes[l + 1][0] += quantidade;
                                componentesnum++;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Componente----Quantidade\n");
    for (i = 0; i < componentesnum; i++) {
        sprintf(&idInteiro[0], "%d", componentes[i][1]);
        tamanho = strlen(idInteiro);
         strcpy(idProduto,"M0000");
        for (k = tamanho; k > 0; k--) {
            idProduto[5 - tamanho] = idInteiro [tamanho];
        }
        printf("%s       >     %d\n", idProduto, componentes[i][0]);
    }
}

int codProdutoParaInt(char* codigo) {
    int idProduto;
    codigo[0] = '0';
    idProduto = atoi(codigo);
    return idProduto;
}