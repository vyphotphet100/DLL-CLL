// MAIN FILE - CIRCULAR DOUBLY LINKED LIST
#include<iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* pre;
};
struct cDouList {
	node* head;
};

node* createNode(int data) {
    node* nod = new node;
    nod->data = data;
    nod->next = nullptr;
    nod->pre = nullptr;
}

cDouList* createList() {
	cDouList* list = new cDouList;
    list->head = nullptr;
	return list;
}

int getLength(cDouList* list) {
    if (list->head == nullptr)
        return 0;
    else if (list->head->next == list->head)
        return 1;
    
    int _count = 1;
    node* curP = list->head;
    while(curP->next != list->head) {
        _count++;
        curP = curP->next;
    }

    return _count;
}

void addHead(cDouList* list, int data) {
    node* nod = createNode(data);

    if (getLength(list) == 0) {
        nod->next = nod;
        nod->pre = nod;
        list->head = nod;
    } else {
        nod->next = list->head;
        nod->pre = list->head->pre;
        list->head->pre->next = nod;
        list->head->pre = nod;
        list->head = nod;
    }
}

void addTail(cDouList* list, int data) {
	node* nod = createNode(data);

    if (getLength(list) == 0) {
        nod->next = nod;
        nod->pre = nod;
        list->head = nod;
    } else {
        nod->next = list->head;
        nod->pre = list->head->pre;
        list->head->pre->next = nod;
        list->head->pre = nod;
    }
}

void addAt(cDouList* list, int k, int data) {
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
	for (int i = 1; curP->next != list->head; i++) {
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

void deleteHead(cDouList* list) {
    if (getLength(list) == 0) {
        cout << "Nothing to delete. \n";
        return;
    }

    if (getLength(list) == 1) {
        list->head = nullptr;
        return;
    }

    list->head->next->pre = list->head->pre;
    list->head->pre->next = list->head->next;
    list->head = list->head->next;
}

void deleteTail(cDouList* list) {
    if (getLength(list) == 0) {
        cout << "Nothing to delete. \n";
        return;
    }

    if (getLength(list) == 1) {
        list->head = nullptr;
        return;
    }

    list->head->pre->pre->next = list->head;
    list->head->pre = list->head->pre->pre;
}

void deleteAt(cDouList* list, int k) {
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

int getDataAt(cDouList* list, int k) {
    if (k<0 || k >= getLength(list)) {
        cout << "Invalid index or list is empty. \n";
        return 0;
    }
    
    if (k == 0)
        return list->head->data;

    node* curP = list->head;
    for (int i=1; curP->next != list->head; i++) {
        curP = curP->next;
        if (i == k)
            break;
    }

    return curP->data;
}

void printList(cDouList* list) {
    if (getLength(list) == 0){
        cout << "List is empty. \n";
        return;
    }

	node* p = list->head;
	while (p->next != list->head) {
		cout << p->data << " ";
		p = p->next;
	}
    cout << p->data << " ";
}

int main() {
	cDouList* list = createList();
	addTail(list, 6);
    addTail(list, 7);
    addTail(list, 8);
    addTail(list, 9);

    cout << getDataAt(list, 2);
    cout << "\n";
	return 0;
}