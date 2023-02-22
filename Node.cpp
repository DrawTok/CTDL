#include <iostream>

using namespace std;

template <class T>
class List
{
private:
    struct Node
    {
        T item;
        Node *next;
    };
    Node *head;
    int size;

    Node *find(int index) const
    {
        Node *cur = head;
        for (int i = 1; i < index; i++)
            cur = cur->next;
        return cur;
    }

public:
    List()
    {
        size = 0;
        head = NULL;
    }

    void push_front(T newItem);
    void pop_front();
    void push_back(T newItem);
    void pop_back();
    void insert(T index, T newItem);
    void remove(T index);
    bool empty();
    int getSize();
    T retrive(T index);
};

template <class T>
void List<T>::push_front(T newItem)
{
    Node *newNode;
    newNode = new Node();    // thuê ô nhớ cho newNode
    newNode->item = newItem; // gán giá trị cho vùng nhớ con trỏ newNode
    Node *cur = head;
    head = newNode;      // trỏ con trỏ head tới địa chỉ newNode
    newNode->next = cur; // gán địa chỉ của nút cur(head) vào newNode
    size++;
}

template <class T>
void List<T>::pop_front()
{
    Node *del = head;
    head = head->next;
    del->next = NULL;
    delete del;
    size--;
}

template <class T>
void List<T>::push_back(T newItem)
{
    Node *newNode = new Node;
    newNode->item = newItem;

    Node *prev = find(size);
    prev->next = newNode;
    newNode->next = NULL;
    size++;
}

template <class T>
void List<T>::pop_back()
{
    Node *prev = find(size - 1);
    Node *del = prev->next;
    prev->next = NULL;
    delete del;
    size--;
}

template <class T>
void List<T>::insert(T index, T newItem)
{
    int newSize = size + 1;
    if (index < 0 || index > newSize)
    {
        cout << "Position is invalid" << endl;
    }
    else
    {
        Node *newNode;
        newNode = new Node();
        newNode->item = newItem;
        if (index == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *prev = find(index - 1);
            newNode->next = prev->next;
            prev->next = newNode;
        }
        size = newSize;
    }
}

template <class T>
void List<T>::remove(T index)
{
    if (index < 0 || index >= size)
    {
        cout << "Position is invalid" << endl;
    }
    else
    {
        Node *del;
        if (index == 1)
        {
            del = head;
            head = head->next;
        }
        else
        {
            Node *prev = find(index - 1);
            del = prev->next;
            prev->next = del->next;
        }
        del->next = NULL;
        delete del;
        size--;
    }
}

template <class T>
bool List<T>::empty()
{
    if (size == 0)
    {
        return false;
    }
    return true;
}

template <class T>
int List<T>::getSize()
{
    return size;
}

template <class T>
T List<T>::retrive(T index)
{
    if (index > 0 && index <= size)
    {
        Node *cur = find(index);
        return cur->item;
    }
    else
    {
        cout << "Invalid retrieval location" << endl;
    }
}

int main()

{
    List<int> l;
    l.push_front(1);
    l.push_back(2);
    cout << l.getSize() << endl;

    return 0;
}