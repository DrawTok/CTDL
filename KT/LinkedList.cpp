#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
private:
    struct Node
    {
        T item;
        Node *next;
    };

    Node *head;
    int size;

public:
    LinkedList()
    {
        size = 0;
        head = NULL;
    }

    void insertElement(int index, T value);
    void deleteElement(int index);
    void findElement();
    void show();
    int findLastElement(int value);
};

template <class T>
void LinkedList<T>::insertElement(int index, T value)
{
    int newSize = size + 1;

    if (index < 0 || index > newSize)
    {
        cout << "Position is invalid" << endl;
    }
    else
    {
        Node newNode = new Node();
        newNode->item = value;
        if (index == 1)
        {
            newNode->next = head;
            head = newNode;
        }
    }
}

int main()

{
    return 0;
}