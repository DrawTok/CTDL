#include <iostream>

const int MAX = 100;

using namespace std;

template <class T>
class Queue
{
    private:
        struct Node
        {
            T item;
            Node *next;
        };
        Node *head;
        Node *tail;
    public:
    Queue()
    {
        head = tail = NULL;
    }

    void addQueue(T newItem);// chèn cuối
    void deleteQueue(); // xóa đầu

    T getFront();
    T getBack();

};

template <class T>
void Queue<T>::addQueue(T newItem)
{
    Node *newNode= new Node();
    newNode -> item = newItem;
    if(tail == NULL)
    {
        head = tail = newNode;
    }else
    {
        tail -> next = newNode;
        tail = newNode;
    }
    
}

template <class T>
void Queue<T>::deleteQueue()
{
    if(head == NULL)
    {
        cout << "Queue is empty" <<endl;
    }else
    {
        Node *del = head;
        if(head -> next == NULL)
        {
            head = tail = NULL;
        }else
        {
            head = head -> next;
        }
        del -> next = NULL;
        delete del;
    }
    
}

template <class T>
T Queue<T>::getFront()
{
    return head->item;
}

template <class T>
T Queue<T>::getBack()
{
    return tail->item;
}

// Stack
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
    Stack();
    void push(T newItem);
    void pop();
    void pop(T &topItem);
    T getTop() const;
    bool isEmpty() const;
};

template <class T>
Stack<T>::Stack()
{
    size = 0;
    head = NULL;
}

template <class T>
void Stack<T>::push(T newItem)
{
    Node *newNode = new Node;
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
void Stack<T>::pop(T &itemTop)
{
    if (isEmpty())
    {
        cout << "Array is empty" << endl;
    }
    else
    {
        Node *del = head;
        itemTop = del->item;
        del->next = NULL;
        delete del;
        size--;
    }
}

template <class T>
T Stack<T>::getTop() const
{
    return head->item;
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return size == 0;
}


int main()
{
    bool check = false;
    
    string str = "A c b i b c a";
    Queue<char> queue;
    Stack<char> stack;
    char c = ' ';
    for(int i = 0; i < str.size(); i++)
    {
        c = tolower(str[i]);
        stack.push(c);
        queue.addQueue(c);
    }
    

    for(int i = 0; i < str.size(); i++)
    {
        
        if(stack.getTop() == queue.getFront()) 
        {
            stack.pop();
            queue.deleteQueue();
            check = true;
        }else
        {
            check = false;
            
        }
    }

    if(check == true)
    {
        cout << "this is Palindrome string"<<endl;
    }else{
        cout << "this is not Palindrome string"<<endl;
    }
    
}