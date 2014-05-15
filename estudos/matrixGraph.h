#include "graph.h"
#include <stdlib.h>

#ifndef _MATRIXGRAPH_H_
#define _MATRIXGRAPH_H_

/*Estrutura de um digrafo*/
struct digraph{
    int V;
    int A;
    int **adj;
};

/*Digrafo*/
typedef struct digraph *Digraph;


/*Estrutura de um grafo*/
#define graph digraph

/*Grafo*/
#define Graph Digraph

#define maxV 1024

/*Func que cria a matriz de adjacencia*/
int **MATRIXint(int r, int c, int val);

/*Func criadora de um digrafo*/
Digraph DIGRAPHinit(int v);

/*Func que insere um arco v-w no digrafo G*/
void DIGRAPHinsert(Digraph G, Vertex v, Vertex w);

/*Func que remove  o arco v-w do digrafo G*/
void DIGRAPHremove(Digraph G, Vertex v, Vertex w);

/*Func que mostra os arcos digrafo G*/
void DIGRAPHshow(Digraph G);

/*Func que insere aresta v-w no grafo G*/
void GRAPHinsert(Graph G, Vertex v, Vertex w);

/*Func que remove aresta v-w no grafo G*/
void GRAPHremove(Graph G, Vertex v, Vertex w);

/*Func que procura caminho de v-->w */
int DIGRAPHpath(Digraph G, Vertex s, Vertex t);

/*Devolve 1 se S={v:lbl[v]=1} T={v:lbl[v]=0} formam um st-corte com todo arco tendo ponta inicial em T e final em S ou 0 cc*/
int stCorte(Digraph G, Vertex s, Vertex t);

/*Recebe um digrafo G e vertice s e t, o vetor parnt, e devolve 1 se t-->parnt[t]-->parnt[parnt[t]]-->... é o reverso do caminho de s a t em G ou 0 cc.*/
int stCaminho(Digraph G, Vertex s, Vertex t);
#endif /*_MATRIXGRAPH_H_*/
