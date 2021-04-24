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

node* getNodeAt(douList* list, int k) {
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

    return getNodeAt(list, k)->data;
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

void Q11_printList(douList* list) {
    printList(list);
}

void Q12_printInReverse(douList* list) {
    for (int i=getLength(list)-1; i >= 0; i--)
        cout << getDataAt(list, i) << " ";
}

void Q13_addHead(douList* list, int data) {
    addHead(list, data);
}

void Q14_addTail(douList* list, int data) {
    addTail(list, data);
}

void Q15_addAt(douList* list, int k, int data) {
    addAt(list, k-1, data);
}

void Q16_addAtMiddle(douList* list, int data) {
    int mid = 0;
    if (getLength(list)%2 == 0)
        mid = getLength(list)/2;
    else 
        mid = getLength(list)/2 + 0.5;

    addAt(list, mid, data);
}

void Q17_deleteHead(douList* list) {
    deleteHead(list);
}

void Q18_deleteTail(douList* list) {
    deleteTail(list);
}

void Q19_deleteAt(douList* list, int k) {
    deleteAt(list, k-1);
}

void Q20_deleteAtMiddle(douList* list) {
    int mid = 0;
    if (getLength(list)%2 == 0)
        mid = getLength(list)/2;
    else 
        mid = getLength(list)/2 + 0.5;

    deleteAt(list, mid);
}

void Q21_maxValue(douList* list) {
    if (getLength(list) == 0) {
        cout << "List is empty. \n";
        return;
    }

    int maxVal = getDataAt(list, 0);
    for (int i=0; i<getLength(list); i++)
        if (getDataAt(list, i) > maxVal)
            maxVal = getDataAt(list, i);
    
    cout << "The Maximum Value in the Linked List : " << maxVal << "\n";
}

int main() {
	douList* list = createList();
	addTail(list, 6);
    addTail(list, 7);
    addTail(list, 20);
    addTail(list, 9);

    Q21_maxValue(list);

    printList(list);
    cout << "\n";
	return 0;
}