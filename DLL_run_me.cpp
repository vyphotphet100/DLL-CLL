// MAIN FILE - DOUBLY LINKED LIST
#include<iostream>

using namespace std;

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

int getLength(douList* list) {
    if (list->head == nullptr && list->tail == nullptr)
        return 0;
    else if (list->head->next == nullptr)
        return 1;
    
    int _count = 1;
    node* curP = list->head;
    while(curP->next != nullptr) {
        _count++;
        curP = curP->next;
    }

    return _count;
}

void addHead(douList* list, int data) {
    node* nod = createNode(data);

    if (getLength(list) == 0) {
        list->head = nod;
        list->tail = nod;
    } else {
        nod->next = list->head;
        list->head->pre = nod;
        list->head = nod;
    }
}

void addTail(douList* list, int data) {
	node* nod = createNode(data);

    if (getLength(list) == 0) {
        list->head = nod;
        list->tail = nod;
    } else {
        nod->pre = list->tail;
        list->tail->next = nod;
        list->tail = nod;
    }
}

void addAt(douList* list, int k, int data) {
    if (k < 0 || k > getLength(list)) {
        cout << "Invalid index. \n";
        return;
    }

    if (k == 0) {
        addHead(list, data);
        return;
    }

    if (k == getLength(list)) {
        addTail(list, data);
        return;
    }

	node* curP = list->head;
	for (int i = 1; curP->next != nullptr; i++) {
		curP = curP->next;
        if (i == k)
            break;
	}
	node* temp = createNode(data);
	temp->next = curP;
    temp->pre = curP->pre;
    curP->pre->next = temp;
    curP->pre = temp;
}

void deleteHead(douList* list) {
    if (getLength(list) == 0) {
        cout << "Nothing to delete. \n";
        return;
    }

    if (getLength(list) == 1) {
        list->head = nullptr;
        list->tail = nullptr;
        return;
    }

    list->head = list->head->next;
    delete(list->head->pre);
    list->head->pre = nullptr;
}

void deleteTail(douList* list) {
    if (getLength(list) == 0) {
        cout << "Nothing to delete. \n";
        return;
    }

    if (getLength(list) == 1) {
        list->head = nullptr;
        list->tail = nullptr;
        return;
    }

	list->tail = list->tail->pre;
    delete(list->tail->next);
    list->tail->next = nullptr;
}

void deleteAt(douList* list, int k) {
    if (getLength(list) == 0) {
        cout << "Nothing to delete. \n";
        return;
    }

    if (k >= getLength(list)) {
        cout << "Invalid index. \n";
        return;
    }

    if (k == 0) {
        deleteHead(list);
        return;
    } else if (k == getLength(list) - 1) {
        deleteTail(list);
        return;
    }

	node* curP = list->head;
	for (int i = 1; curP->next != nullptr; i++) {
		curP = curP->next;
        if (i == k)
            break;
	}

    curP->pre->next = curP->next;
    curP->next->pre = curP->pre;
    delete(curP);
}

int getDataAt(douList* list, int k) {
    if (k<0 || k >= getLength(list)) {
        cout << "Invalid index or list is empty. \n";
        return 0;
    }
    
    if (k == 0)
        return list->head->data;

    node* curP = list->head;
    for (int i=1; curP->next != nullptr; i++) {
        curP = curP->next;
        if (i == k)
            break;
    }

    return curP->data;
}

void printList(douList* list) {
    if (getLength(list) == 0){
        cout << "List is empty. \n";
        return;
    }

	node* p = list->head;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}

int main() {
	douList* list = createList();
	addTail(list, 6);
    addTail(list, 7);
    addTail(list, 8);
    addTail(list, 9);

    cout << getDataAt(list, 1);
    cout << "\n";
	return 0;
}