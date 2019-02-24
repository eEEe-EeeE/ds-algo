#ifndef __LINEARTABLE__
#define __LINEARTABLE__

#include <random>
#include <cstdlib>
#include <iostream>

//data域数据类型
#define ElemType int

//单链表结点
typedef struct node {
	ElemType data;
	node *link;
}LNode, *LinkList;

int myrandom(); //产生随机数
LinkList CREATE(ElemType n); //创建单链表
int LINKLEN(LinkList list); //单链表长度
bool ISEMPTY(LinkList list); //单链表为空
LinkList FIND(LinkList list, ElemType item); //查找单链表data为item的结点
void PRINTLIST(LinkList list); //打印单链表
void INSERTLINK1(LinkList *list, ElemType item); //在非空单链表第一个结点前插入item结点
void INSERTLINK2(LinkList list, ElemType item); //在非空单链表末尾插入item结点
void INSERTLINK3(LinkList *list, LinkList q, ElemType item); //在单链表q所指结点前插入item结点
void INSERTLINK4(LinkList list, const int i, ElemType item); //在单链表弟i个结点后插入item结点
void INSERTLINK5(LinkList *list, ElemType item); //在按值有序的单链表中插入item结点
void DELETELINK1(LinkList *list, LinkList q); //从非空单链表中删除q所指结点
void DELETELIST(LinkList *list); //删除单链表
void DELETELINK2(LinkList *list, ElemType item); //删除单链表中所有data为item的结点
void INVERT(LinkList *list); //逆转单链表
void CONNECT(LinkList lista, LinkList listb); //连接两个单链表
LinkList MERGELIST(LinkList lista, LinkList listb); //合并两个按值有序单链表
LinkList COPY(LinkList list); //复制单链表
void LINKSORT(ElemType group[], int len); //利用单链表对数组排序
void REMOVE(LinkList *list); //将单链表中最大结点移至末尾


#endif