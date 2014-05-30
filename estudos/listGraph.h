#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef _LISTGRAPH_H_
#define _LISTGRAPH_H_


/*Lista de adjacencia: link = ponteiro para node; node vertice e link;*/
typedef struct node *link;
struct node{
    Vertex w;
    link next;
};

/*Estrutura de um digrafo*/
struct digraph{
    int V;
    int A;
    link *adj;
};

/*Digrafo*/
typedef struct digraph *Digraph;

/*Estrutura de um grafo*/
#define graph digraph

/*Grafo*/
#define Graph Digraph

#define maxV 1024

/*Func que verifica se esxite um arco de v-u*/
int isArc(Digraph G, Vertex v, Vertex u);

/*Func criadora de um digrafo*/
Digraph DIGRAPHinit(int V);

/*Func que insere um arco v-w no digrafo G*/
void DIGRAPHinsert(Digraph G, Vertex v, Vertex w);

/*Func que remove  o arco v-w do digrafo G*/
void DIGRAPHremove(Digraph G, Vertex v, Vertex w);

/*cria novo arco com o vertice u: x.w = u e x.next = next*/
link NEWv(Vertex u, link next);

/*Func que mostra os arcos digrafo G*/
void DIGRAPHshow(Digraph G);

/*Func que remove  o arco v-w do digrafo G*/
/*void DIGRAPHremove(Digraph G, Vertex v, Vertex w);*/

/*****Para Grafos******/
#define GRAPHinit DIGRAPHinit
#define GRAPHshow DIGRAPHshow

/*Func que insere aresta v-w no grafo G*/
void GRAPHinsert(Graph G, Vertex v, Vertex w);

/*Func que remove aresta v-w no grafo G*/
/*void GRAPHremove(Graph G, Vertex v, Vertex w);*/

/*Func que executa a busca em profundidade no grafo G*/
void DIGRAPHdfs(Digraph G);

/*Func que procura caminho de v-->w */
int DIGRAPHpath(Digraph G, Vertex s, Vertex t);

/*Devolve 1 se S={v:lbl[v]=1} T={v:lbl[v]=0} formam um st-corte com todo arco tendo ponta inicial em T e final em S ou 0 cc*/
int stCorte(Digraph G, Vertex s, Vertex t);

/*Recebe um digrafo G e vertice s e t, o vetor parnt, e devolve 1 se t-->parnt[t]-->parnt[parnt[t]]-->... é o reverso do caminho de s a t em G ou 0 cc.*/
int stCaminho(Digraph G, Vertex s, Vertex t);

/* Algoritmo Kosaraju: para descobrir componentes fortemente conexas - Devolve o numero de componentes e um vetor delas*/
/*int DIGRAPHsc(Digraph G);*/

/*Func que busca ciclos em um dado grafo*/
int DIGRAPHcycle(Digraph G);

/*Func que armazena em ts[0...i-1] uma permutacao de um subconjunto de vertices de G e devolve i: Se i = G->V entao ts[0...i-1] é uma ordenacao topologica*/
int DAGts1(Digraph G, Vertex ts[]);

/*Func que busca ciclos em um dado grafo*/
int DIGRAPHcycle(Digraph G);


#endif /*_LISTGRAPH_*/
