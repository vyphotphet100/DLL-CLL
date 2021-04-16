#include<iostream>

using namespace std;

// Cong Thuong
struct node {
	int data;
	node* next;
	node* pre;
};
struct douList {
	node* head;
	node* tail;
};

node* createNode(int data) {
    node* nod = new node;
    nod->data = data;
    nod->next = nullptr;
    nod->pre = nullptr;
}
douList* createList() {
	douList* l = new douList;
    l->head = nullptr;
    l->tail = nullptr;
	return l;
}
void addHead(douList* l, int x) {
    node* nod = createNode(x);

    if (l->head == nullptr && l->tail == nullptr) {
        l->head = nod;
        l->tail = nod;
    } else {
        nod->next = l->head;
        l->head->pre = nod;
        l->head = nod;
    }
}
void addTail(douList* l, int x) {
	node* nod = createNode(x);

    if (l->head == nullptr && l->tail == nullptr) {
        l->head = nod;
        l->tail = nod;
    } else {
        nod->pre = l->tail;
        l->tail->next = nod;
        l->tail = nod;
    }
}
void addAt(douList* l, int k, int x) {
	node* p = l->head;
	for (int i = 0; i < k - 1; i++) {
		p = p->next;
	}
	node* temp = createNode(x);
	temp->pre = p;
	temp->next = p->next;
	p->next = temp;
}

// Thanh Thien
void deleteHead(douList* l) {
    if (l->head == nullptr && l->tail == nullptr)
        return;
    if (l->head->next == nullptr) {
        l->head = nullptr;
        l->tail = nullptr;
        return;
    }

	node* p = l->head->next;
	node* temp = l->head;
	p->pre = NULL;
	l->head = p;
	delete(temp);
}
void deleteTail(douList* l) {
    if (l->head == nullptr && l->tail == nullptr)
        return;
    if (l->head->next == nullptr) {
        l->head = nullptr;
        l->tail = nullptr;
        return;
    }

	node* p = l->tail->pre;
	node* temp = l->tail;
	p->next = NULL;
	l->tail = p;
	delete(temp);
}

void deleteAt(douList* l, int k) {
    if (l->head == nullptr && l->tail == nullptr)
        return;
    if (l->head->next == nullptr) {
        l->head = nullptr;
        l->tail = nullptr;
        return;
    }
    if (k == 0) {
        deleteHead(l);
        return;
    }

	node* p = l->head;
	for (int i = 0; i < k - 1; i++) {
		p = p->next;
	}
    if (p->next->next == nullptr) {
        deleteTail(l);
        return;
    }

	node* temp = p->next;
	node* p2 = temp->next;
	p->next = p2;
	p2->pre = p;
	delete(temp);
}

void printList(douList* l) {
	node* p = l->head;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}

int main() {
	douList* list = createList();
	addTail(list, 6);
    //addTail(list, 7);
    //addTail(list, 8);

    deleteAt(list, 1);
	printList(list);
	return 0;
}