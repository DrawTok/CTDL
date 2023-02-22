#include <iostream>

const int MAX = 100;
typedef int item_type;
using namespace std;

class list
{
private:
    item_type item[MAX];
    int size;

public:
    list()
    {
        item[0] = 1;
        item[1] = 2;
        item[2] = 3;
        item[3] = 5;
        item[4] = 6;
        size = 5;
    };

    void pushFront(item_type newNum)
    {
        if (size <= 100)
        {
            for (int i = size; i > 0; i--)
            {
                item[i] = item[i - 1];
            }
            item[0] = newNum;
            size++;
        }
        if (size > 100)
        {
            cout << "FULL MEMORY" << endl;
        }
    }

    void popFront()
    {
        if (size > 0)
        {
            for (int i = 0; i < size; i++)
            {
                item[i] = item[i + 1];
            }
        }
        size--;
    }

    void pushBack(item_type newNum)
    {
        if (size <= 100)
        {

            item[size] = newNum;
            size++;
        }

        if (size > 100)
        {
            cout << "FULL MEMORY" << endl;
        }
    }

    void popBack()
    {
        if (size > 0)
        {
            size--;
        }
    }

    void insert(item_type newNum, int index)
    {
        if (size > 0)
        {
            size++;
            for (int i = size; i > index; i--)
            {
                item[i] = item[i - 1];
            }
            item[index] = newNum;
        }
    }

    void remove(int index)
    {
        if (size > 0)
        {
            for (int i = index; i < size; i++)
            {
                item[i] = item[i + 1];
            }
            size--;
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << item[i] << " ";
        }
        cout << endl;
    }
};

int main()

{
    list l;
    // l.pushFront(5);
    // l.pushFront(1);
    // l.pushFront(2);
    // l.pushFront(3);
    // l.print();
    // l.popFront();
    // l.popBack();
    l.insert(4, 3);
    // l.remove(2);
    l.print();
    return 0;
}