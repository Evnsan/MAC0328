#include "QUEUE.h"
#include <stdlib.h>

/* Atributos */
Item *q;
int inicio, fim;


/* Rotinas */
void QUEUEinit(int maxN){
    q = (Item*) malloc(maxN*sizeof(Item));
    inicio = 0;
    fim = 0;
}

int QUEUEempty(){
    return inicio == fim;
}

void QUEUEput(Item item){
    q[fim++] = item;
}

Item QUEUEget(){
    return q[inicio++];
}

void QUEUEfree(){
    free(q);
}
