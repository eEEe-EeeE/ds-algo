#ifndef __LINEARTABLE__
#define __LINEARTABLE__

#include <random>
#include <cstdlib>

#define ElemType int

typedef struct node {
	ElemType data;
	node *link;
}LNode, *LinkList;

int myrandom();
LinkList CREATE(ElemType n);
int LINKLEN(LinkList list);
bool ISEMPTY(LinkList list);
LinkList FIND(LinkList list, ElemType item);

#endif