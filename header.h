//Lista de Adjacência

typedef struct grafo
{
    int eh_ponderado;
    int nro_Vertice;
    int grau_Max; //Quantas arestas posso ter pra um vértice
    int **arestas;
    float **pesos;
    int *grau; //Pra quantas arestas o vertice já possui
} Grafo;

Grafo *criaGrafo(int nro_Vertice, int grau_Max, int eh_ponderado)
{
    Grafo *gr = (Grafo *)malloc(sizeof(Grafo));
    if (gr != NULL)
    {
        int i;
        gr->nro_Vertice = nro_Vertice;
        gr->grau_Max = grau_Max;
        gr->eh_ponderado = eh_ponderado;
        gr->grau = (int *)calloc(nro_Vertice, sizeof(int));
        gr->arestas = (int **)malloc(nro_Vertice * sizeof(int *));
        for (i = 0; i < nro_Vertice; i++)
            gr->arestas[i] = (int *)malloc(grau_Max * sizeof(int));
        if (gr->eh_ponderado)
        {
            gr->pesos = (float **)malloc(nro_Vertice * sizeof(float *));
            for (i = 0; i < nro_Vertice; i++)
                gr->pesos[i] = (float *)malloc(grau_Max * sizeof(float));
        }
    }
    return gr;
}

int insereAresta(Grafo *gr, int orig, int dest, int eh_digrafo, float peso)
{
    if (gr == NULL)
        return 0;
    if (orig < 0 || orig >= gr->nro_Vertice)
        return 0;
    if (dest < 0 || dest >= gr->nro_Vertice)
        return 0;
    gr->arestas[orig][gr->grau[orig]] = dest;
    if (gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if (eh_digrafo == 0)
        insereAresta(gr, dest, orig, 1, peso);
    return 1;
}
int removeAresta(Grafo *gr, int orig, int dest, int eh_digrafo)
{
    if (gr == NULL)
        return 0;
    if (orig < 0 || orig >= gr->nro_Vertice)
        return 0;
    if (dest < 0 || dest >= gr->nro_Vertice)
        return 0;
    int i =0;
    while(i<gr->grau[orig]  && gr->arestas[orig][i]!= dest )
        i++;
    if(i == gr->grau[orig])//aresta nao existe no grafo
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        removeAresta(gr,dest,orig,1);
    return 1;
}

void liberaGrafo(Grafo *gr)
{
    if (gr != NULL)
    {
        int i;
        //LIBERA MATRIZ ARESTAS
        for (i = 0; i < gr->nro_Vertice; i++)
            free(gr->arestas[i]);
        free(gr->arestas);
        if (gr->eh_ponderado)
        {
            for (i = 0; i < gr->nro_Vertice; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}