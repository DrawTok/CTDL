#include <iostream>

const int MAX = 100;

using namespace std;

class SinhVien
{
private:
    string maSV;
    double dTB;

public:
    SinhVien()
    {
        maSV = "";
        dTB = 0;
    }

    SinhVien(string maSV, double dTB)
    {
        this->maSV = maSV;
        this->dTB = dTB;
    }

    friend ostream &operator<<(ostream &os, const SinhVien &sv)
    {
        os << "Ma SV: " << sv.maSV << endl;
        os << "Diem TB: " << sv.dTB << endl;
        return os;
    }

    friend istream &operator>>(istream &is, SinhVien &sv)
    {
        cout << "msv: ";
        is >> sv.maSV;
        cout << "dtb: ";
        is >> sv.dTB;

        return is;
    }
};

template <class T>
class Stack
{
private:
    int size;
    T item[MAX];

public:
    Stack();
    void push(T newItem);
    void pop();
    void pop(T &stackTop);
    bool isEmpty() const;
    bool isFull() const;
    T getTop() const;
};

template <class T>
Stack<T>::Stack()
{
    size = 0;
}

template <class T>
void Stack<T>::push(T newItem)
{
    if (isFull())
    {
        cout << "Array full" << endl;
    }
    else
    {
        item[size] = newItem;
        size++;
    }
}

template <class T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Array empty" << endl;
    }
    else
    {
        size--;
    }
}

template <class T>
void Stack<T>::pop(T &stackTop)
{
    if (isEmpty())
    {
        cout << "Array empty" << endl;
    }
    else
    {
        stackTop = item[size - 1];
        size--;
    }
}

template <class T>
T Stack<T>::getTop() const
{
    return item[size - 1];
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return size == 0;
}

template <class T>
bool Stack<T>::isFull() const
{
    return size == MAX;
}

int main()

{
    SinhVien sv1("A43030", 8.0), sv2("A41063", 8.0);
    SinhVien sv3;
    cin >> sv3;
    Stack<SinhVien> sk;
    sk.push(sv1);
    sk.push(sv2);
    sk.push(sv3);
    cout << sk.getTop() << endl;
    return 0;
}