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