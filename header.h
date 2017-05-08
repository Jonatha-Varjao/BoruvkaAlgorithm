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
    int i = 0;
    while (i < gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if (i == gr->grau[orig]) //aresta nao existe no grafo
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if (gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if (eh_digrafo == 0)
        removeAresta(gr, dest, orig, 1);
    return 1;
}

int procuraMenorDistancia(float *dist, int *visitado, int NV)
{
    int i, menor = -1, primeiro = 1;
    for (i = 0; i < NV; i++)
    {
        if (dist[i] >= 0 && visitado[i] == 0)
        {
            if (primeiro)
            {
                menor = i;
                primeiro = 0;
            }
            else
            {
                if (dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}

void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont)
{
    int i;
    visitado[ini] = cont;
    for (i = 0; i < gr->grau[ini]; i++)
    {
        if (!visitado[gr->arestas[ini][i]])
            buscaProfundidade(gr, gr->arestas[ini][i], visitado, cont + 1);
    }
}

//INTERFACE COM USUARIO
void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado)
{
    int i, cont = 1;
    for (i = 0; i < gr->nro_Vertice; i++)
        visitado[i] = 0;
    buscaProfundidade(gr, ini, visitado, cont);

    for (i = 0; i < gr->nro_Vertice; i++)
        printf("%d -> %d\n", i, visitado[i]);
}

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado)
{
    int i, vert, NV, cont = 1;
    int *fila, IF = 0, FF = 0;
    for (i = 0; i < gr->nro_Vertice; i++)
        visitado[i] = 0;

    NV = gr->nro_Vertice;
    fila = (int *)malloc(NV * sizeof(int));
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;
    while (IF != FF)
    {
        IF = (IF + 1) % NV;
        vert = fila[IF];
        cont++;
        for (i = 0; i < gr->grau[vert]; i++)
        {
            if (!visitado[gr->arestas[vert][i]])
            {
                FF = (FF + 1) % NV;
                fila[FF] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
    for (i = 0; i < gr->nro_Vertice; i++)
        printf("%d -> %d\n", i, visitado[i]);
}
void imprime_Grafo(Grafo *gr)
{
    if (gr == NULL)
        return;

    int i, j;
    for (i = 0; i < gr->nro_Vertice; i++)
    {
        printf("%d: ", i);
        for (j = 0; j < gr->grau[i]; j++)
        {
            if (gr->eh_ponderado)
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n");
    }
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

void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist){
    int i, cont, NV, ind, *visitado, vert;
    cont = NV = gr->nro_Vertice;
    visitado = (int*) malloc(NV * sizeof(int));
    for(i=0; i < NV; i++){
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    dist[ini] = 0;
    while(cont > 0){
        vert = procuraMenorDistancia(dist, visitado, NV);
        //printf("u = %d\n",u);
        if(vert == -1)
            break;

        visitado[vert] = 1;
        cont--;
        for(i=0; i<gr->grau[vert]; i++){
            ind = gr->arestas[vert][i];
            if(dist[ind] < 0){
               dist[ind] = dist[vert] + 1;//ou peso da aresta
               ant[ind] = vert;
            }else{
                if(dist[ind] > dist[vert] + 1){
                    dist[ind] = dist[vert] + 1;//ou peso da aresta
                    ant[ind] = vert;
                }
            }
        }
    }

    free(visitado);
}
