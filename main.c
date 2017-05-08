#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int a;
    Grafo *gr;
    gr = criaGrafo(10,7,0);
    insereAresta(gr,0,1,0,0);
    liberaGrafo(gr);
    return 0;
}