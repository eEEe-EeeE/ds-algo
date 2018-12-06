#include "linear-table.h"

int myrandom() {

	std::random_device seed;
	std::mt19937 gen(seed());
	std::uniform_int_distribution<> dis(0, 2147483647);

	return dis(gen);
}

LinkList CREATE(ElemType n) {
	
	LinkList p = nullptr, r = nullptr, list = nullptr;
	ElemType d = 0;
	for (int count = 0; count < n; ++count) {
		d = (myrandom() % 10);
		if (d >= 10)
			return nullptr;
		p = (LinkList)malloc(sizeof(LNode));
		if (p == nullptr)
			return nullptr;
		p->data = d;
		p->link = nullptr;
		if (list == nullptr)
			list = p;
		else
			r->link = p;
		r = p;
	}

	return list;
}

void PRINTLIST(LinkList list) {

	if (list != nullptr) {
		for (LinkList p = list; p != nullptr; p = p->link) {
			std::cout << p->data << ' ';
		}
		std::cout << "#END#" << std::endl;
	}
}

int LINKLEN(LinkList list) {

	int count = 0;
	for (LinkList p = list; p != nullptr; p = p->link) {
		++count;
	}

	return count;
}

bool ISEMPTY(LinkList list) {

	if (list == nullptr)
		return true;
	else
		return false;
}

LinkList FIND(LinkList list, ElemType item) {

	for (LinkList p = list; p != nullptr; p = p->link) {
		if (p->data == item)
			return p;
	}
	return nullptr;
}

void INSERTLINK1(LinkList *list, ElemType item) {

	if (*list == nullptr)
		return;

	LinkList p = nullptr;
	p = (LinkList)malloc(sizeof(LNode));
	if (p == nullptr)
		return;
	p->data = item;
	p->link = *list;
	*list = p;

}

void INSERTLINK2(LinkList list, ElemType item) {

	LinkList r = nullptr, p = nullptr;
	r = list;
	while (r->link != nullptr) {
		r = r->link;
	}
	p = (LinkList)malloc(sizeof(LNode));
	if (p == nullptr)
		return;
	p->data = item;
	p->link = nullptr;
	r->link = p;
}

void INSERTLINK3(LinkList *list, LinkList q, ElemType item) {

	LinkList p = nullptr;
	p = (LinkList)malloc(sizeof(LNode));
	if (p == nullptr)
		return;
	p->data = item;
	if (*list == nullptr) {
		p->link = nullptr;
		*list = p;
	}

	p->link = q->link;
	q->link = p;
}

void INSERTLINK4(LinkList list, const int i, ElemType item) {

	LinkList p = nullptr;
	int count = 1;
	p = list;

	while (p != nullptr) {
		if (count == i)
			break;
		++count;
		p = p->link;
	}

	if (p == nullptr)
		return;

	LinkList q = nullptr;
	q = (LinkList)malloc(sizeof(LNode));
	q->data = item;
	q->link = p->link;
	p->link = q;
}

// ´ý¼ìÑé
void INSERTLINK5(LinkList *list, ElemType item) {

	LinkList pre = nullptr;
	LinkList cur = nullptr;
	LinkList temp = nullptr;
	cur = *list;
	pre = cur;

	while (cur != nullptr) {
		if (cur->data > item) {
			temp = (LinkList)malloc(sizeof(LNode));
			if (temp != nullptr) {
				temp->data = item;
				temp->link = cur;
				if (pre == *list)
					pre = temp;
				pre->link = temp;
			}
			return;
		}
		pre = cur;
		cur = cur->link;
	}
	temp = (LinkList)malloc(sizeof(LNode));
	if (temp != nullptr) {
		temp->data = item;
		temp->link = nullptr;
		pre->link = temp;
	}
	return;

}


void DELETELINK1(LinkList *list, LinkList q) {

	LinkList p = nullptr;
	p = *list;
	if (q == *list) {
		*list = (*list)->link;
		free(p);
		return;
	}
	while (p->link != q && p->link != nullptr)
		p = p->link;
	if (p->link == nullptr)
		return;
	else {
		p->link = q->link;
		free(q);
	}
	return;

}


void DELETELIST(LinkList *list) {

	LinkList p = *list;
	while (*list != nullptr) {
		p = (*list)->link;
		free(*list);
		*list = p;
	}
	return;

}

void DELETELINK2(LinkList *list, ElemType item) {

	LinkList cur = *list;
	LinkList pre = cur;
	while (cur != nullptr) {
		if (cur->data == item) {
			pre->link = cur->link;
			free(cur);
			cur = pre->link;
			continue;
		}
		else {
			pre = cur;
			cur = cur->link;
		}
	}
	return;

}


void INVERT(LinkList *list) {

	LinkList cur = *list;
	LinkList pre = nullptr;
	LinkList nex = cur;
	while (nex != nullptr) {
		nex = cur->link;
		cur->link = pre;
		pre = cur;
		cur = nex;
	}
	*list = pre;

}


void CONNECT(LinkList lista, LinkList listb) {

	if (lista == nullptr || listb == nullptr)
		return;
	LinkList ptr = nullptr;
	ptr = lista;
	while (ptr->link != nullptr)
		ptr = ptr->link;
	ptr->link = listb;
	return;

}


LinkList MERGELIST(LinkList lista, LinkList listb) {


}


LinkList COPY(LinkList list) {

	LinkList ptr = nullptr;

}