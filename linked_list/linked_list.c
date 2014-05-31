#include <stdio.h>
#define TRUE 1
#define FALSE !TRUE
typedef int ElementType;
typedef int BOOL;

struct link_node{
	ElementType data;
	struct link_node * next;
	struct link_node * pre;
};

struct link_info{
	int count;
	struct link_node *head;
	struct link_node *tail;
};
//add a new node after pos node
BOOL add_entry(struct link_node *pos,struct link_node *new){
	struct link_node *last;
	last = pos->next;
	pos->next = new;
	new->pre = pos;
	new->next = last;
	last->pre = new;
	return TRUE;
}

struct link_node list_search(struct link_info *L,ElementType k){
	struct link_node *x;
	x = L->head;
   while(x&&x->data!=k)
		x = x.next;
	return x;
}
