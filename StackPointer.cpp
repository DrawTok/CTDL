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

int convertToInt(char c)
{
    return (int)c - 48;
}
int main()

{
    // Stack<char> stk;
    // stk.push(2);
    // stk.push(3);
    // stk.push(4);
    // stk.push(5);
    // stk.pop();
    // cout << stk.getTop() << endl;

    // int rs;
    // stk.pop(rs);
    // cout << rs << endl;
    /*string s;
    cin >> s;
    Stack<char> stkChar;
    char c = ' ';
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        c = s[i];
        if (c == '{')
        {
            stkChar.push('{');
        }

        if (c == '}')
        {
            count++;

            if (stkChar.getTop() == '{')
            {
                stkChar.pop();
                count--;
            }
        }
    }
    if (stkChar.isEmpty() && count == 0)
    {
        cout << "Balance" << endl;
    }
    else
    {
        cout << "Not balance" << endl;
    }*/

    // chuyển trung tố sang hậu tố
    /*Stack<char> stk;
    string s = "(a+b)/(c+d)", kq;
    char c = ' ';
    for (int i = 0; s[i] != '\0'; i++)
    {
        c = s[i];
        if (c == '(' || c == '+' ||
            c == '-' || c == '*' ||
            c == '/')
        {
            stk.push(c);
        }
        else if (c == ')')
        {
            if (s[i + 1] != '(')
            {
                kq += stk.getTop();
            }
            stk.pop();
        }
        else
        {
            kq += c;
        }
    }
    stk.pop();
    kq += stk.getTop();
    cout << kq;*/
    // tính toán biểu thức hậu tố

    Stack<int> stkInt;
    string s = "53*2+";
    int a1, a2, rs;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isdigit(c))
        {
            stkInt.push(c - '0');
        }
        else
        {
            a1 = stkInt.getTop();
            stkInt.pop();
            a2 = stkInt.getTop();
            stkInt.pop();

            switch (s[i])
            {
            case '+':
                rs = a1 + a2;
                break;
            case '-':
                rs = a1 - a2;
                break;
            case '*':
                rs = a1 * a2;
                break;
            case '/':
                rs = a1 / a2;
                break;
            default:
                break;
            }
            stkInt.push(rs);
        }
    }

    cout << stkInt.getTop();
    return 0;
}
