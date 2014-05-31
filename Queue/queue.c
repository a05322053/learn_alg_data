#include <stdio.h>
#define TRUE	1
#define FALSE	0
#define LEN		20
typedef int ElementType;
typedef int BOOL;
struct queue{
	ElementType data[LEN];
	int head;
	int tail;
	BOOL is_full;
	BOOL is_empty;
};

BOOL ENQUEUE(struct queue *Q,ElementType x){
	if(Q->is_full == TRUE){
		return FALSE;
	}
	Q->data[Q->tail]=x;
	if(Q->tail == LEN-1){
		Q->tail = 0;
	}else{
		Q->tail = Q->tail + 1;
	}
	if(Q->tail == Q->head){
		Q->is_full = TRUE;
	}else{
		Q->is_empty = FALSE;
	}
	return TRUE;
}

ElementType DEQUEUE(struct queue *Q){
	ElementType x;
	if(Q->is_empty){
		printf("This queue is empty\n");
		return ;
	}
	x = Q->data[Q->head];

	if(Q->head == LEN - 1){
	 Q->head = 0;
	}else{
		Q->head = Q->head + 1;
	}
	if(Q->head == Q->tail){
		Q->is_empty = TRUE;
	}else{
		Q->is_full = FALSE;
	}
	return x;	
}

int main(){
	struct queue Qu;
	int i;
	Qu.head=0;
	Qu.tail=0;
	Qu.is_full = FALSE;
	Qu.is_empty = TRUE;

	DEQUEUE(&Qu);
	ENQUEUE(&Qu,5);
	ENQUEUE(&Qu,3);
	ENQUEUE(&Qu,2);
	ENQUEUE(&Qu,7);
	for(i=Qu.head;i<Qu.tail;i++){	
		printf("%d\n",Qu.data[i]);
	}
	printf("%d\n",DEQUEUE(&Qu));
	printf("%d\n",DEQUEUE(&Qu));
	printf("%d\n",DEQUEUE(&Qu));
	printf("%d\n",DEQUEUE(&Qu));
	return 0;
}
