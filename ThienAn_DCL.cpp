//======DANH SÁCH LIÊN KẾT ĐƠN VÒNG=====
// ===TẠO NODE, THÊM ĐẦU, THÊM ĐUÔI,THÊM BẤT KỲ=====
#include <iostream>
using namespace std;

// Cấu trúc node
struct Node {
    int data;
    struct Node* next; // trỏ tới vị trí  kết tiếp
    struct Node* prev; // trỏ tới vị trí trước
};
//Hàm tạo node
void Create(struct Node** start, int value)
{
    if (*start == NULL) {
        struct Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
        

    /* Find last node */
    Node* last = (*start)->prev;

    // Create Node dynamically
    struct Node* new_node = new Node;
    new_node->data = value;

    // Start is going to be next of new_node
    new_node->next = *start;

    // Make new node previous of start
    (*start)->prev = new_node;

    // Make last preivous of new node
    new_node->prev = last;

    // Make new node next of old last
    last->next = new_node;

}
//Hàm hiển thị danh sách
void display(struct Node* start)
{
    struct Node* temp = start;

    while (temp->next != start) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}
//===Hàm INSERT vào đầu list
void insertBegin(struct Node** start, int value)
{
    // Pointer points to last Node
    struct Node* last = (*start)->prev;

    struct Node* new_node = new Node;
    new_node->data = value;   // Inserting the data

    // setting up previous and next of new node
    new_node->next = *start;
    new_node->prev = last;

    // Update next and previous pointers of start
    // and last.
    last->next = (*start)->prev = new_node;

    // Update start pointer
    *start = new_node;
}
// ==Hàm INSERT vào cuối list
void insertEnd(struct Node** start, int value)
{
    // If the list is empty, create a single node
    // circular and doubly list
    if (*start == NULL)
    {
        struct Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }

    // If list is not empty

    /* Find last node */
    Node* last = (*start)->prev;

    // Create Node dynamically
    struct Node* new_node = new Node;
    new_node->data = value;

    // Start is going to be next of new_node
    new_node->next = *start;

    // Make new node previous of start
    (*start)->prev = new_node;

    // Make last preivous of new node
    new_node->prev = last;

    // Make new node next of old last
    last->next = new_node;
}
//==Hàm INSERT vào trị trí sau vị trí X
void insertAfter(struct Node** start, int value1,int value2)
{
    struct Node* new_node = new Node;
    new_node->data = value1; 

    // Tìm kím node có giá trị X (biến value1)
    struct Node* temp = *start;
    while (temp->data != value2)
        temp = temp->next;
    struct Node* next = temp->next;

    // INSERT vào giữa
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}

int main()
{
    // Start với một list trống
    struct Node* start = NULL;
    int n; //biến số phần tử của list
    
    cout << "Nhap vao so phan tu cua list: "; //nhập sô phần tử của list 
    cin >> n;
    int a; // biến giá trị của node
    int value; // biến giá trị thêm vào
    int value1; //biến giá trị trước vị trí cần thêm vào
    for (int i = 0; i < n; i++)
    {   //Nhập vào giá trị của node và tạo list
        cout << "Nhap gia tri Node " << i << ": "; 
        cin >> a;
        Create(&start, a);
    }
    printf("List hien tai: "); 
    display(start);// in ra list hiện tại
    cout << endl;
    int choice; //biến để lựa chọn thao tác insert
    cout << "========================"<<endl;
    cout << "1. Them vao dau list."<<endl;
    cout << "2. Them vao cuoi list."<<endl;;
    cout << "3. Them vao vi tri sau gia tri X."<<endl;
    cin >> choice;
    switch (choice)
    {
        case(1): //===THÊM VÀO ĐẦU DANH SÁCH
            cout << "Nhap vao gia tri can them vao dau danh sach: ";
            cin >> value;
            insertBegin(&start, value);
            cout << "Danh sach sau khi them vao: ";
            display(start); break;
        case(2): //===THÊM VÀO CUỐI DANH SÁCH
            cout << "Nhap vao gia tri can them vao cuoi danh sach: ";
            cin >> value;
            insertEnd(&start, value);
            cout << "Danh sach sau khi them vao: ";
            display(start); break;
        case(3): //==THÊM VÀO VỊ TRÍC TRƯỚC GIÁ TRỊ X
            cout << "Nhap vao gia tri truoc vi tri can them vao: ";
            cin >> value1;
            cout << "Nhap vao gia tri can them vao: ";
            cin >> value;
            insertAfter(&start, value, value1);
            cout << "Danh sach sau khi them vao: ";
            display(start);
       
    }
    return 0;
}