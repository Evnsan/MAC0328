#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "matrixGraph.h"

int main(int argc, char *argv[]){
    int i;
    Digraph G = DIGRAPHinit(5);
    
    if(argc>1){
        for(i=0; i<argc; i++)
            printf("%s ", argv[i]);
        printf("\n");
    }
    
    DIGRAPHinsert(G,0,1);
    DIGRAPHinsert(G,0,3);
    DIGRAPHinsert(G,2,4);
    DIGRAPHinsert(G,4,1);
    GRAPHinsert(G,2,3);
    DIGRAPHshow(G);
    printf("\n");
    
/*
    DIGRAPHremove(G,0,1);
    DIGRAPHremove(G,0,3);
    DIGRAPHremove(G,0,4);
    DIGRAPHremove(G,2,1);
    DIGRAPHremove(G,4,2);
    DIGRAPHremove(G,3,4);
    DIGRAPHshow(G);
    printf("\n");
    
    GRAPHremove(G,2,3);
    GRAPHremove(G,1,4);
    DIGRAPHshow(G);
*/

    if(DIGRAPHpath(G,0,4))
        printf("Existe caminho de 0 --> 4\n");
    else
        printf("Não existe caminho de 0 --> 4\n");
    
     if(DIGRAPHpath(G,1,4))
        printf("Existe caminho de 1 --> 4\n");
    else
        printf("Não existe caminho de 1 --> 4\n");
    
    GRAPHinsert(G,1,3);
    DIGRAPHshow(G);
    printf("\n");
    
    if(DIGRAPHpath(G,1,4))
        printf("Existe caminho de 1 --> 4\n");
    else
        printf("Não existe caminho de 1 --> 4\n");
 /*******/   
    if(stCorte(G,1,4))
        printf("s=1 t=4 é um st corte 1 --> 4\n");
    else
        printf("s=1 t=4 não é um st corte 1 --> 4\n");
 /*******/   
    if(stCorte(G,3,0))
        printf("s=3 t=0 é um st corte\n");
    else
        printf("s=3 t=0 não é um st corte\n");
 /*******/   
    if(stCaminho(G,1,4))
        printf("s=1 t=4 é um caminho reverso no vetor parnt\n");
    else
        printf("s=1 t=4 não é um caminho reverso no vetor parnt\n");
 /*******/   
    if(stCaminho(G,3,0))
        printf("s=3 t=0 é um caminho reverso no vetor parnt\n");
    else
        printf("s=3 t=0 não é um caminho reverso no vetor parnt\n");
    return 1;
}
