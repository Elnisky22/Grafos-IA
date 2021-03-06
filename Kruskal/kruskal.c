#include <stdlib.h>
#include <stdio.h>
#include "kruskal.h"
#define N 6

//Realiza a solu��o de Kruskal
void kruskal(int matriz[N][N]) {
	aresta *p = malloc(((N*(N-1))/2) * sizeof(aresta));
	int x = 1, t = 0;

	for(int i = 0; i < N; i++) {
		for(int j = x; j < N; j++) {
			if(matriz[i][j] != 0) {
				(p+t)->v1 = i;
				(p+t)->v2 = j;
				(p+t)->custo = matriz[i][j];
				t++;
			}
		}
		x++;
	}
	p = realloc(p,t * sizeof(aresta));

	ordena(p,t);
	exibir_final(p,t);
}

//Ordena um vetor de ponteiros de aresta
void ordena(aresta *p, int t) {
    int i, j, temp;
    for(i = 1; i < t; i++) {
        temp = (p+i)->custo;
        j = i;
        while(j > 0 && (p+j-1)->custo > temp) {
            (p+j)->custo = (p+j-1)->custo ;
            j--;
        }
        (p+j)->custo = temp;
    }
}

//Exibir o resultado final do algoritmo de Kruskal
void exibir_final(aresta *p, int t) {
	int vj[N];
	for (int i = 0; i < N; i++) {
		vj[i] = -1;
	}

	for(int i = 0; i < t; i++) {
		if (vj[(p+i)->v2] == -1) {
			printf("(%d,%d) = %d\n",(p+i)->v1,(p+i)->v2,(p+i)->custo);
			vj[(p+i)->v2] = 1;
		}
	}
}
