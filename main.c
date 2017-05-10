#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int eh_digrafo = 0; // 0: N direcionado 1: Direcionado
    /*GRAFO 1
    Grafo* gr = criaGrafo(6, 6, 1);
    int pai[6];
    insereAresta(gr, 0, 1, eh_digrafo, 6);
    insereAresta(gr, 0, 2, eh_digrafo, 1);
    insereAresta(gr, 0, 3, eh_digrafo, 5);
    insereAresta(gr, 1, 2, eh_digrafo, 2);
    insereAresta(gr, 1, 4, eh_digrafo, 5);
    insereAresta(gr, 2, 3, eh_digrafo, 2);
    insereAresta(gr, 2, 4, eh_digrafo, 6);
    insereAresta(gr, 2, 5, eh_digrafo, 4);
    insereAresta(gr, 3, 5, eh_digrafo, 4);
    insereAresta(gr, 4, 5, eh_digrafo, 3);
    imprime_Grafo(gr);
    BoruvkaAlgorithm(gr,0,pai);
    liberaGrafo(gr);
    */
    /*GRAFO 2 
    Grafo *gr = criaGrafo(6, 6, 1);
    int pai[6];
    insereAresta(gr, 0, 1, eh_digrafo, 1);
    insereAresta(gr, 0, 2, eh_digrafo, 6);
    insereAresta(gr, 1, 3, eh_digrafo, 3);
    insereAresta(gr, 3, 4, eh_digrafo, 1);
    insereAresta(gr, 4, 5, eh_digrafo, 5);
    insereAresta(gr, 2, 5, eh_digrafo, 2);
    imprime_Grafo(gr);
    BoruvkaAlgorithm(gr, 0, pai);
    liberaGrafo(gr);
    */
    //GRAFO 3
    Grafo *gr = criaGrafo(5,3,1);
    int pai[5];
    insereAresta(gr, 0, 1, eh_digrafo, 2);
    insereAresta(gr, 0, 2, eh_digrafo, 4);
    insereAresta(gr, 0, 3, eh_digrafo, 4);
    insereAresta(gr, 1, 3, eh_digrafo, 3);
    insereAresta(gr, 1, 2, eh_digrafo, 6);
    insereAresta(gr, 3, 4, eh_digrafo, 2);
    imprime_Grafo(gr);
    BoruvkaAlgorithm(gr,0,pai);
    liberaGrafo(gr);
    

    return 0;
}