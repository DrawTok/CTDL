#include <iostream>
#include <ctime>
typedef int type_item;
const int MAX = 100;
using namespace std;

class list
{
private:
    type_item item[MAX];
    int size;

public:
    list()
    {
        size = 0;
    }

    void pushFront(type_item newNum)
    {
        size++;
        for (int i = size; i > 0; i--)
        {
            item[i] = item[i - 1];
        }
        item[0] = newNum;
    }

    void popFront()
    {
        for (int i = 0; i < size; i++)
        {
            item[i] = item[i + 1];
        }
        size--;
    }

    void pushBack(type_item newNum)
    {

        item[size] = newNum;
        size++;
    }

    void popBack()
    {
        size--;
    }

    void insert(int index, type_item newNum)
    {
        size++;
        for (int i = size; i > index; i--)
        {
            item[i] = item[i - 1];
        }
        item[index] = newNum;
    }

    void remove(int index)
    {
        for (int i = index; i < size; i++)
        {
            item[i] = item[i + 1];
        }
        size--;
    }

    void show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    bool checkEmpty()
    {
        if (size <= 0)
        {
            cout << "Array is empty" << endl;
            return false;
        }
        return true;
    }

    bool isFull()
    {
        if (size > MAX)
        {
            cout << "Memory is full" << endl;
            return false;
        }
        return true;
    }

    int retrieve(int index)
    {
        return item[index];
    }
};

int main()

{

    list l;
    for (int i = 1; i <= 50; i++)
    {
        l.pushBack(rand());
    }
    l.show();
    double avg;
    int x;
    int max = l.retrieve(0);
    int min = l.retrieve(0);
    for (int i = 1; i < 50; i++)
    {
        x = l.retrieve(i);
        if (x > max)
        {
            max = x;
        }
        if (x < min)
        {
            min = x;
        }
        avg += x;
    }
    avg /= 50;
    cout << "MIN: " << min << endl;
    cout << "MAX: " << max << endl;
    cout << "AVERAGE: " << avg << endl;

    int find;
    cout << "Enter num: ";
    cin >> find;
    bool check = false;
    for (int i = 0; i < 50; i++)
    {
        if (find == l.retrieve(i))
        {
            check = true;
            cout << "Position: " << i << endl;
            break;
        }
    }
    if (!check)
    {
        cout << "Not found" << endl;
    }

    return 0;
}