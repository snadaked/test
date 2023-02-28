#include <stdio.h>
#include <stdlib.h>

typedef struct lst_it{
	int val;
	struct lst_it *next;
}lst_it;

int*** list2mat(int V, lst_it *ar[V]){
	int E = 0, i, j = 0;
	lst_it *tmp;
	for (i = 0; i<V; i++){
		tmp = ar[i];
		tmp1 = i;
		while(tmp != NULL){
			E++;
			tmp=tmp->next;
		}
	}
	//mat[V][E]
	int ***mat = (int***)malloc(V*sizeof(int*));
	for (i = 0; i<V; i++)
		*mat[i] = (int*)calloc(E, sizeof(int));
	for (i = 0; i<V; i++){
		tmp = ar[i];
		while (tmp->next != NULL){
			*mat[i][j] = -1;
			*mat[(tmp->val)-1][j] = 1;
			j++;
		}
	}
	return mat;
}

