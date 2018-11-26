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
void INSERTLINK5(LinkList *list, ElemType item);//有序插入
//非空表删除q指定的链结点
//删除链表
//删除所有数据为item的结点
//逆转链表
//连接两个非空链表
//合并两个按值有序链表
//复制链表
//用链表对数据排序


#endif