#include <stdio.h>
#define TRUE 1
#define FALSE 0 
#define LEN 20
struct stack{
	int data[LEN];
	int top;
};

int stack_is_empty(struct stack *S){
	if(S->top==0)
		return TRUE;
	else
		return FALSE;
}

int PUSH(struct stack *S,int x){
	if(S->top<LEN-1){
		S->top = S->top + 1;
		S->data[S->top]=x;
		return TRUE;
	}else{
		return FALSE;
	}
}

int POP(struct stack *S){
	if(S->top!=0){
		S->top = S->top - 1;
		return S->data[S->top+1];
	}else{
		return;
	}
}

int main(){
	struct stack Te;
	int i;
	Te.top = -1;
	PUSH(&Te,3);
	PUSH(&Te,5);
	PUSH(&Te,2);
	PUSH(&Te,1);
	for(i=0;i<=Te.top;i++){
		printf("%d\n",Te.data[i]);
	}

	printf("%d\n",POP(&Te));
	return 0;
}
