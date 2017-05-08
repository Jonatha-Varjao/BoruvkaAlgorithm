#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int eh_digrafo = 0;
    Grafo* gr = criaGrafo(9, 9, 1);

    insereAresta(gr, 0, 1, eh_digrafo,4);
    insereAresta(gr, 0, 7, eh_digrafo,8);   
    insereAresta(gr, 1, 2, eh_digrafo,8);
    insereAresta(gr, 1, 7, eh_digrafo,11);    
    insereAresta(gr, 7, 8, eh_digrafo,7);
    insereAresta(gr, 7, 6, eh_digrafo,1);
    insereAresta(gr, 6, 5, eh_digrafo,2);
    insereAresta(gr, 6, 8, eh_digrafo,6);
    insereAresta(gr, 5, 4, eh_digrafo,10);
    insereAresta(gr, 5, 2, eh_digrafo,4);
    insereAresta(gr, 4, 3, eh_digrafo,9);
    insereAresta(gr, 3, 2, eh_digrafo,7);
    insereAresta(gr, 2, 8, eh_digrafo,2);

    imprime_Grafo(gr);
    printf("\nBusca \n");
    
    int i,ant[13];
    float dist[13];
    menorCaminho_Grafo(gr, 0, ant, dist);
    for(i=0; i<13; i++)
        printf("%d: %d -> %f\n",i,ant[i],dist[i]);

    liberaGrafo(gr);
    
    
    return 0;
}