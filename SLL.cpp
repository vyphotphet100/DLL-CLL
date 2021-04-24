// MAIN FILE - DOUBLY LINKED LIST
#include<iostream>

using namespace std;

struct node {
	int data;
	node* next;
};
struct List {
	node* head;
	node* tail;
};

node* createNode(int data) {
    node* nod = new node;
    nod->data = data;
    nod->next = nullptr;
}

List* createList() {
	List* l = new List;
    l->head = nullptr;
    l->tail = nullptr;
	return l;
}

int getLength(List* list) {
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

void addHead(List* list, int data) {
    node* nod = createNode(data);

    if (getLength(list) == 0) {
        list->head = nod;
        list->tail = nod;
    } else {
        nod->next = list->head;
        list->head = nod;
    }
}

void addTail(List* list, int data) {
	node* nod = createNode(data);

    if (getLength(list) == 0) {
        list->head = nod;
        list->tail = nod;
    } else {
        list->tail->next = nod;
        list->tail = nod;
    }
}

void addAt(List* list, int k, int data) {
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
    node* prevP = list->head;
	for (int i = 1; curP->next != nullptr; i++) {
        prevP = curP;
		curP = curP->next;
        if (i == k)
            break;
	}
	node* temp = createNode(data);
	temp->next = curP;
    prevP->next = temp;
}

void deleteHead(List* list) {
    if (getLength(list) == 0) {
        cout << "Nothing to delete. \n";
        return;
    }

    if (getLength(list) == 1) {
        list->head = nullptr;
        list->tail = nullptr;
        return;
    }

    node* tmp = list->head->next;
    delete(list->head);
    list->head = tmp;
}

node* getNodeAt(List* list, int k) {
    if (k < 0 || k >= getLength(list)) {
        cout << "Invalid index. \n";
        return nullptr;
    }

    if (k == 0)
        return list->head;
    else if (k == getLength(list)-1)
        return list->tail;

    node* curP = list->head;
    for (int i=1; curP->next != nullptr; i++) {
        curP = curP->next;
        
        if (i == k)
            break;
    }

    return curP;
}

void deleteTail(List* list) {
    if (getLength(list) == 0) {
        cout << "Nothing to delete. \n";
        return;
    }

    if (getLength(list) == 1) {
        list->head = nullptr;
        list->tail = nullptr;
        return;
    }

    list->tail = getNodeAt(list, getLength(list)-2);
    delete(list->tail->next);
    list->tail->next = nullptr;
}

void deleteAt(List* list, int k) {
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
    node* prevP = list->head;
	for (int i = 1; curP->next != nullptr; i++) {
        prevP = curP;
		curP = curP->next;
        if (i == k)
            break;
	}

    prevP->next = curP->next;
    delete(curP);
}

int getDataAt(List* list, int k) {
    if (k<0 || k >= getLength(list)) {
        cout << "Invalid index or list is empty. \n";
        return 0;
    }
    
    if (k == 0)
        return list->head->data;

    return getNodeAt(list, k)->data;
}

void printList(List* list) {
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
	List* list = createList();
	addTail(list, 6);
    addTail(list, 7);
    addTail(list, 8);
    addTail(list, 9);

    cout << getDataAt(list, 2);
    cout << "\n";
	return 0;
}