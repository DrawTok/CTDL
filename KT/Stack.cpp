#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    struct Node
    {
        T item;
        Node *next;
    };

    int size;
    Node *head;

public:
    Stack()
    {
        size = 0;
        head = NULL;
    }
    void push(T newItem);
    void pop();
    T getTop();
    bool isEmpty();
};

template <class T>
void Stack<T>::push(T newItem)
{
    Node *newNode = new Node();
    newNode->item = newItem;
    if (head == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
    }
    head = newNode;
    size++;
}

template <class T>
void Stack<T>::pop()
{

    if (isEmpty())
    {
        cout << "Array is empty" << endl;
    }
    else
    {
        Node *del = head;
        head = head->next;
        del->next = NULL;
        delete del;
        size--;
    }
}

template <class T>
T Stack<T>::getTop()
{
    return head->item;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return size == 0;
}

int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    cout << stack.getTop();
    return 0;
}