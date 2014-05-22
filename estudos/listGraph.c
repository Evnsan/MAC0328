#include "listGraph.h"
#include "graph.h"


/****Declaracoes****/
static int cnt, lbl[maxV], time, parnt[maxV], d[maxV], f[maxV];
void dfsR(Digraph G, Vertex v);
int pathR(Digraph G, Vertex v, Vertex t);
Digraph DIGRAPHreverse(Digraph G);
void dfsRsc(Digraph G, Vertex v, int id);
int cycleR(Digraph G, Vertex v);

/****Fim Declaracoes****/


/****Implementacoes****/

/*Func que verifica se esxite um arco de v-u*/
int isArc(Digraph G, Vertex v, Vertex u){
    link p = G->adj[v];
    while(p && p->w != u)
        p=p->next;
    return (int)p;
}

/*Func criadora de um digrafo*/
Digraph DIGRAPHinit(int V){
    Vertex v;
    Digraph G = malloc(sizeof(G));
    G->V = V;
    G->A = 0;
    G->adj = malloc(V*sizeof(link));
    for(v=0; v<V; v++)
        G->adj[v] = NULL;
    return G;
}

/*Func que insere um arco v-w no digrafo G.*/
void DIGRAPHinsert(Digraph G, Vertex v, Vertex w){
    if(v == w || isArc(G,v,w))
        return;
    G->adj[v] = NEWv(w, G->adj[v]);
    G->A++;
}

/*Func que remove  o arco v-w do digrafo G*/
void DIGRAPHremove(Digraph G, Vertex v, Vertex w){
    link p = G->adj[v];
    link q;
    if(p->w == w){
        G->adj[v] = p->next;
        free(p);
        printf("arco %2d->%2d removido!\n", v, w);
    }
    else{
        q = p->next;
        while(q){
            if(q->w == w){
                p->next=q->next;
                free(q);
                q = p;
                printf("arco %2d->%2d removido!\n", v, w);
            }
            p = q;
            q = q->next;
        }
     }        
}

/*cria novo arco com o vertice u: x.w = u e x.next = next*/
link NEWv(Vertex u, link next){
    link p = malloc(sizeof(p));
    p->w = u;
    p->next = next;
    return p;
}

/*Func que imprime as listas adj's do Grafo G*/
void DIGRAPHshow(Digraph G){
    Vertex v;
    link p;
    for(v=0; v < G->V; v++){
        printf("%2d: ",v);
        for(p=G->adj[v]; p != NULL; p = p->next)
            printf("%2d ", p->w);
        printf("\n");
    }
}

/*Func que insere aresta v-w no grafo G*/
void GRAPHinsert(Graph G, Vertex v, Vertex w){
    DIGRAPHinsert(G, v, w);
    DIGRAPHinsert(G, w, v);
}

/*Func que executa a busca em profundidade*/
void DIGRAPHdfs(Digraph G){
    Vertex v;
    time = 0;
    for(v = 0; v < G->V; v++)
        d[v] = f[v] = parnt[v] = lbl[v] = -1;
    for(v = 0; v < G->V; v++)
        if(d[v] == -1)
            dfsR(G, v);
}

/*Func recursiva de busca em profundidade que cria as arborescências no grafo G*/
void dfsR(Digraph G, Vertex v){
    link p;
    lbl[v] = cnt++;
    d[v] = time++;
    for(p = G->adj[v]; p != NULL; p = p->next)
        if(d[p->w] == -1){
            parnt[p->w] = v;
            dfsR(G, p->w);
        }
    f[v] = time++;
}

/*Func que verifica se há caminho de s-t */
int DIGRAPHpath(Digraph G, Vertex s, Vertex t){
    Vertex v;
    for(v = 0; v < G->V; v++){
        lbl[v] = 0;
        parnt[v] = -1;
    }
    parnt[s] = s;
    pathR(G, s, t);
    return lbl[t];
}

/*Func interna para formatar o vetor lbl com 1 para os vertices que se pode chegar a partir de s, dado o digrafo G. i.e. lbl[w]=1 se existe caminho de v --> w*/
/*void pathR(Digraph G, Vertex v){*/
/*    link p;*/
/*    lbl[v] = 1;*/
/*    for(p = G->adj[v]; p; p = p->next)*/
/*        if(!lbl[p->w]){*/
/*            parnt[p->w] = v;*/
/*            pathR(G, p->w);*/
/*        }*/
/*}*/

/*Resolucao do professor para pathR parando ao encontrar t*/
int pathR(Digraph G, Vertex v, Vertex t){
    link p;
    lbl[v] = 1;
    if(v==t) return 1;
    for(p = G->adj[v]; p; p = p->next)
        if(!lbl[p->w]){
            parnt[p->w] = v;
            if (pathR(G, p->w, t))
                return 1;
        }
    return 0;
}

/*Func que busca ciclos em um dado grafo O(A(V+A))*/
/*int DIGRAPHcycle(Digraph G){*/
/*    Vertex v;*/
/*    link p;*/
/*    for(v = 0; v < G->V; v++)*/
/*        for(p = G->adj[v]; p; p = p->next)*/
/*            if(DIGRAPHpath(G, p->w , v))*/
/*                return 1;*/
/*    return 0;*/
/*}*/

/*Func que busca ciclos usando os tipos de arcos encontrados na arvore O(V+A)*/
int DIGRAPHcycle(Digraph G){
    Vertex v;
    time = 0;
    for(v = 0; v < G->V; v++)
        d[v] = f[v] = parnt[v] = -1;
    for(v = 0; v < G->V; v++)
        if(d[v] == -1){
            parnt[v] = v;
            if(cycleR(G,v) == 1) return 1;
        }
    return 0;
}

/*Func interna recursiva utilizada no DIGRAPHcycle*/
int cycleR(Digraph G, Vertex v){
    link p;
    d[v] = time++;
    for(p = G->adj[v]; p; p = p->next){
        if(d[p->w] == -1){
            parnt[p->w] = v;
            if(cycleR(G, p->w)) return 1;
        }
        else if(f[p->w] == -1) return 1;
    }
    f[v] = time++;
    return 0;
}

/* Algoritmo Kosaraju: para descobrir componentes fortemente conexas - Devolve o numero de componentes e um vetor delas*/
/*int DIGRAPHsc(Digraph G){
    Vertex v;
    int id, i;
    Digraph R = DIGRAPHreverse(G);
    cnt = 0;
    for(v = 0; v < R->V; v++)
        sc[v] -1;
    for(v = 0; v < R->V; v++)
        if(sc[v] == -1)
            dfsRsc(R, v, 0);
    for(i = 0; i < G-V, i++)
        sopR[i] = sop[i];
    cnt = id = 0;
    for(v = 0; v < R->V; v++)
        sc[v] = -1;
    for(i = G-V-1; i > 0; i--)
        if(sc[sopR[i]] == -1)
            dfsRsc(G, sopR[i], id++);
    DIGRAPHdestroy(R);
    return id;
}
*/
/* Parte recursiva do algoritmo de Kosaraju: DFS com fila de prioridade */
/*void dfsRsc(Digraph G, Vertex v, int id){*/
/*    link p;*/
/*    sc[v] = id;*/
/*    for(p = G->adj[v]; p; p = p->next)*/
/*        if(sc[p->w] == -1)*/
/*            dfsRsc(G, p->w, id);*/
/*    pos[v] = cnt;  não precisa */
/*    sop[cnt++] = v;*/
/*}*/
    
/* Parte para inverter o digrafo, necessaria no algoritmo de Kosaraju */
Digraph DIGRAPHreverse(Digraph G){
    Vertex v; 
    link p;
    Digraph R = DIGRAPHinit(G->V);
    for(v = 0; v < G->V; v++)
        for(p = G->adj[v]; p; p= p->next)
            DIGRAPHinsert(G,p->w,v);
    return R;
}
