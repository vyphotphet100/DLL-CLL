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

void Q1_printList(List* list) {
    printList(list);
}

void Q2_printInReverse(List* list) {
    for (int i=getLength(list)-1; i>=0; i--)
        cout << getDataAt(list, i) << " ";
}

void Q3_getLengthOfList(List* list) {
    cout << "Total number of nodes = " << getLength(list);
}

void Q4_addHead(List* list, int data) {
    addHead(list, data);
}

void Q5_addTail(List* list, int data) {
    addTail(list, data);
}

void Q6_addAt(List* list, int k, int data){
    addAt(list, k-1, data);
} 

void Q7_deleteHead(List* list) {
    deleteHead(list);
}

void Q8_deleteAt(List* list, int k) {
    deleteAt(list, k-1);
}

void Q9_deleteTail(List* list) {
    deleteTail(list);
}

void Q10_indexOf(List* list, int data) {
    for (int i=0; i<getLength(list); i++)
        if (getDataAt(list, i) == data) {
            cout << "Element found at node " << i+1 << "\n";
            break;
        }
}

int main() {
	List* list = createList();
	addTail(list, 2);
    addTail(list, 5);
    addTail(list, 8);

    Q10_indexOf(list, 5);

    printList(list);
    cout << "\n";
	return 0;
}