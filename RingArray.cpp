#include <iostream>

using namespace std;

const int MAX_QUEUE = 100;

template <class QueueItemType>
class Queue
{
    private:
        int back;
        int front;
        int count;
        QueueItemType info[MAX_QUEUE];
    public:
        Queue();
        void addQueue(QueueItemType);
        void deleteQueue();
        QueueItemType getFront() const;

        bool isEmpty() const
        {
            return count = 0;
        }
        bool isFull() const
        {
            return count = MAX_QUEUE;
        }

};

class Bad
{

};

template <class QueueItemType>
Queue<QueueItemType>::Queue()
{
    count = 0;
    back = MAX_QUEUE-1;
    front = 0;
}

template <class QueueItemType>
void Queue<QueueItemType>::addQueue(QueueItemType x)
{
    if(isFull())
    {
        throw Bad();
    }else
    {
        back = (back + 1) % MAX_QUEUE;
        info[back] = x;
        count++;
    }
}

template <class QueueItemType>
void Queue<QueueItemType>::deleteQueue()
{
    if(isFull())
    {
        throw Bad();
    }else
    {
        front = (front+1)%MAX_QUEUE;
        count--;
    }
}

template <class QueueItemType>
QueueItemType Queue<QueueItemType>::getFront() const
{
    if(isEmpty())
    {
        throw Bad();
    }else
    {
        return info[front];
    }
}

int main()
{

    return 0;
}