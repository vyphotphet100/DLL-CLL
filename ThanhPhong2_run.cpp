#include <iostream>
using namespace std;


class Node {
public:
	int data;
	Node* next;
};
void push(Node** head_ref, int data)
{
	Node* ptr1 = new Node();
	ptr1->data = data;
	ptr1->next = *head_ref;
	if (*head_ref != NULL)
	{
		
		Node* temp = *head_ref;
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; 

	*head_ref = ptr1;
}


void printList(Node* head)
{
	Node* temp = head;
	if (head != NULL) {
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
	}

	cout << endl;
}

void deleteNode(Node** head, int key)
{

	if (*head == NULL)
		return;

	if ((*head)->data == key && (*head)->next == *head)
	{
		free(*head);
		*head = NULL;
		return;
	}

	Node *last = *head, *d;

	if ((*head)->data == key)
	{

		while (last->next != *head)
			last = last->next;

		last->next = (*head)->next;
		free(*head);
		*head = last->next;
	}


	while (last->next != *head&&last->next->data != key)
	{
		last = last->next;
	}

	
	if (last->next->data == key)
	{
		d = last->next;
		last->next = d->next;
		free(d);
	}
	else
		cout << "no such keyfound\n";
}


void DeleteFirst(Node** head)
{
	Node *previous = *head, *firstNode = *head;

	
	if (*head == NULL) {
		printf("\nList is empty\n");
		return;
	}

	
	if (previous->next == previous) {
		*head = NULL;
		return;
	}

	
	while (previous->next != *head) {

		previous = previous->next;
	}

	
	previous->next = firstNode->next;


	*head = previous->next;
	free(firstNode);
	return;
}

void deleteattail(Node** head)
{
	Node *pre = *head, *last = *head;
	if (*head == NULL) {
		printf("\nList is empty\n");
		return;
	}

	if (pre->next == pre) {
		*head = NULL;
		return;
	}

	while (pre->next != *head) {
		last = pre;
		pre = pre->next;
	}
	
	if (pre->next == *head)
	{
		last->next = pre->next;
		free(pre);
		*head = last->next;
	}
}

void deleteIndex(Node ** head, int index)
{
	Node *pre = *head;
	Node *last = *head, *d;
	if (*head == NULL) {
		printf("\nList is empty\n");
		return;
	}
	int count = 0;

	if (pre->next == pre) {
		*head = NULL;
		return;
	}

	while (count != index) {
		last = pre;
		pre = pre->next;
		count++;
	}

	if (count == index)
	{
		d = last->next;
		last->next = d->next;
		free(d);
	}
}

int main()
{
	
	Node* head = NULL;
	int n, *d;
	cout << "Enter number of Node: ";
	cin >> n;
	d= new int(n);
	for(int i=0;i<n;i++)
	{ 
		cout << "Enter value: ";
		cin >> d[i];
		push(&head, d[i]);
	}
	/*head = NULL;*/
	cout << "List Before Deletion: ";
	printList(head);
	int key,index;
	cout << "Delete value: ";
	cin >> key;
	deleteNode(&head, key);
	cout << "List After Deletion: ";
	printList(head);
	cout << "Delete at: ";
	cin >> index;
	deleteIndex(&head, index);
	cout << "List After Deletion: ";
	printList(head);
	DeleteFirst(&head);
	cout << "List After Deletion of First: ";
	printList(head);
	deleteattail(&head);
	cout << "List After Deletion of tail: ";
	printList(head);

	return 0;
}

