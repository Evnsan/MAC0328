#include "matrixGraph.h"
#include "graph.h"
#include <stdio.h>


/****Declaracoes****/

static int lbl[maxV], parnt[maxV];
void pathR1(Digraph G, Vertex v);
int pathR2(Digraph G, Vertex v, Vertex t);
int pathR(Digraph G, Vertex v, Vertex t);


/****Fim Declaracoes****/


/****Implementacoes****/

/*Func que cria a matriz de adjacencia*/
int **MATRIXint(int r, int c, int val){
    Vertex i,j;
    int **m=malloc(r*sizeof(int*));
    for(i=0; i<r; i++)
        m[i]=malloc(c*sizeof(int));
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            m[i][j]=val;
    return m;
}

/*Func criadora de um digrafo*/
Digraph DIGRAPHinit(int v){
    Digraph G=malloc(sizeof(G));
    G->V=v;
    G->A=0;
    G->adj=MATRIXint(v,v,0);
    return G;
}

/*Func que insere um arco v-w no digrafo G*/
void DIGRAPHinsert(Digraph G, Vertex v, Vertex w){
    if(v != w && !G->adj[v][w]){
        G->adj[v][w]=1;
        G->A++;
    }
}

/*Func que remove  o arco v-w do digrafo G*/
void DIGRAPHremove(Digraph G, Vertex v, Vertex w){
    if(G->adj[v][w]){
        G->adj[v][w]=0;
        G->A--;
    }
}

/*Func que mostra os arcos digrafo G*/
void DIGRAPHshow(Digraph G){
    Vertex v, w;
    for(v=0; v<G->V; v++){
        printf("%d: ", v);
        for(w=0; w<G->V; w++)
            if(G->adj[v][w])
                printf("%d ", w);
        printf("\n");
    }
}

/*Func que insere aresta v-w no grafo G*/
void GRAPHinsert(Graph G, Vertex v, Vertex w){
    DIGRAPHinsert(G, v, w);
    DIGRAPHinsert(G, w, v);
}

/*Func que remove aresta v-w no grafo G*/
void GRAPHremove(Graph G, Vertex v, Vertex w){
    DIGRAPHremove(G, v, w);
    DIGRAPHremove(G, w, v);
}

/*Func que procura caminho de v-->w */
int DIGRAPHpath(Digraph G, Vertex s, Vertex t){
    Vertex v;
    for(v=0; v<G->V; v++){
        lbl[v]=0;
        parnt[v]=-1;
    }
/*        lbl[v]=-1;
    pathR(G,s);
    return lbl[t]!=-1;*/
    parnt[s] = s;
    return pathR(G,s,t);
}

/*Func interna para formatar o vetor lbl com 0 para os vertices que se pode chegar a partir de s, dado o digrafo G. i.e. lbl[w]=0 se existe caminho de v --> w*/
void pathR1(Digraph G, Vertex v){
    Vertex w;
    lbl[v] = 0;
    for(w = 0; w<G->V; w++)
        if(G->adj[v][w] && lbl[w]==-1)
               pathR1(G, w);
}

/*Func interna que devolve 0 caso encontre caminho para t*/
int pathR2(Digraph G, Vertex v, Vertex t){
    Vertex w;
    lbl[v] = 0;
    for(w = 0; w<G->V; w++)
        if(G->adj[v][w] && lbl[w]==-1){
            if(w==t)
                return 1;
            else if (pathR2(G, w, t))
                return 1;
        }
    return 0;
}

/*Resolucao do professor para pathR parando ao encontrar t*/
int pathR(Digraph G, Vertex v, Vertex t){
    Vertex w;
    lbl[v] = 1;
    if(v==t) return 1;
    for(w = 0; w<G->V; w++)
        if(G->adj[v][w] && !lbl[w]){
            parnt[w] = v;
            if (pathR(G, w, t))
                return 1;
        }
    return 0;
}

/*Devolve 1 se S={v:lbl[v]=1} T={v:lbl[v]=0} formam um st-corte com todo arco tem ponta inicial em T e final em S ou 0 cc*/
int stCorte(Digraph G, Vertex s, Vertex t){
    Vertex v, w;
    if(!lbl[s] || lbl[t])
        return 0;
    for(v=0; v<G->V; v++)
        for(w=0; w<G->V; w++)
            if(G->adj[v][w] && lbl[v] && !lbl[w])
                return 0;
    return 1;
}

/*Recebe um digrafo G, vertice s e t e o vetor parnt. Devolve 1 se t-->parnt[t]-->parnt[parnt[t]]-->... é o reverso do caminho de s a t em G ou 0 cc.*/
int stCaminho(Digraph G, Vertex s, Vertex t){
    Vertex v, w;
    if(parnt[t]==-1 || parnt[s]!=s)
        return 0;
    for(w=t; w!=s; w=v){
        v=parnt[w];
        if(!G->adj[v][w]) return 0;
    }
    return 1;
}
/****Fim Implementacoes****/
