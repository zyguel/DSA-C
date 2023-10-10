#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef struct node {
	int data[MAX];
	struct node *link;
	int count;
}cptr, *LIST;

void init_list(LIST *A){
	*A = (LIST) calloc(1,sizeof(cptr));
		//LIST is without pointer since LIST is already a pointer 
}

int main (int argc, char* argv){
	LIST A;
	init_list(&A);
	printf("list count and data[0] is %d and %d", A->count, A->data[0]);
	free(A);
	return 0;
}