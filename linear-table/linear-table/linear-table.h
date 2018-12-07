#ifndef __LINEARTABLE__
#define __LINEARTABLE__

#include <random>
#include <cstdlib>
#include <iostream>
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
void PRINTLIST(LinkList list);
void INSERTLINK1(LinkList *list, ElemType item);
void INSERTLINK2(LinkList list, ElemType item);
void INSERTLINK3(LinkList *list, LinkList q, ElemType item);
void INSERTLINK4(LinkList list, const int i, ElemType item);
void INSERTLINK5(LinkList *list, ElemType item); //在按值有序的单链表中插入item结点
void DELETELINK1(LinkList *list, LinkList q);
void DELETELIST(LinkList *list);
void DELETELINK2(LinkList *list, ElemType item);
void INVERT(LinkList *list);
void CONNECT(LinkList lista, LinkList listb);
LinkList MERGELIST(LinkList lista, LinkList listb);
LinkList COPY(LinkList list);
void LINKSORT(ElemType group[], int len);
void REMOVE(LinkList *list);


#endif