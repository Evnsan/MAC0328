#ifndef _GRAPH_H_
#define _GRAPH_H_

/*Vertice*/
#define Vertex int

/*Arco*/
typedef struct{
	Vertex v;
	Vertex w;
} Arc;
	
/*Func criadora de arcos*/
Arc ARC (Vertex v, Vertex w);

/*Aresta*/
#define Edge Arc

/*Func criadora de Arestas*/
#define EDGE ARC

#endif /*_GRAPH_H_*/
