#ifndef __LINEARTABLE__
#define __LINEARTABLE__

#include <random>
#include <cstdlib>
#include <iostream>

//data����������
#define ElemType int

//��������
typedef struct node {
	ElemType data;
	node *link;
}LNode, *LinkList;

int myrandom(); //���������
LinkList CREATE(ElemType n); //����������
int LINKLEN(LinkList list); //��������
bool ISEMPTY(LinkList list); //������Ϊ��
LinkList FIND(LinkList list, ElemType item); //���ҵ�����dataΪitem�Ľ��
void PRINTLIST(LinkList list); //��ӡ������
void INSERTLINK1(LinkList *list, ElemType item); //�ڷǿյ������һ�����ǰ����item���
void INSERTLINK2(LinkList list, ElemType item); //�ڷǿյ�����ĩβ����item���
void INSERTLINK3(LinkList *list, LinkList q, ElemType item); //�ڵ�����q��ָ���ǰ����item���
void INSERTLINK4(LinkList list, const int i, ElemType item); //�ڵ������i���������item���
void INSERTLINK5(LinkList *list, ElemType item); //�ڰ�ֵ����ĵ������в���item���
void DELETELINK1(LinkList *list, LinkList q); //�ӷǿյ�������ɾ��q��ָ���
void DELETELIST(LinkList *list); //ɾ��������
void DELETELINK2(LinkList *list, ElemType item); //ɾ��������������dataΪitem�Ľ��
void INVERT(LinkList *list); //��ת������
void CONNECT(LinkList lista, LinkList listb); //��������������
LinkList MERGELIST(LinkList lista, LinkList listb); //�ϲ�������ֵ��������
LinkList COPY(LinkList list); //���Ƶ�����
void LINKSORT(ElemType group[], int len); //���õ��������������
void REMOVE(LinkList *list); //�������������������ĩβ


#endif