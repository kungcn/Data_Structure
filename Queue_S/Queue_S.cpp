#include "Queue_S.h"

template<class QueueEntry>
Queue_S<QueueEntry>::Queue_S() {
    rear = -1;
}

template<class QueueEntry>
ErrorCode Queue_S<QueueEntry>::Append(const Queue_Entry & Item) {
    if (rear == MAXQUEUE - 1)
        return Overflow;
    Entry[rear + 1] = Item;
    rear++;
    return Success;
}

template<class QueueEntry>
ErrorCode Queue_S<QueueEntry>::Server() {
    if (rear == 0)
        return Underflow;
    for (int i = 0; i < rear; i++)
        Entry[i] = Entry[i + 1];
    rear--;
    return Success;
}

template<class QueueEntry>
ErrorCode Queue_S<QueueEntry>::Retrieve(Queue_Entry & Item) const {
    if (rear == 0)
        return Underflow;
    Item = Entry[0];
    return Success;
}

template<class QueueEntry>
int Queue_S<QueueEntry>::GetRear() {
    return rear;
}

template<class QueueEntry>
bool Queue_S<QueueEntry>::Empty() const {
    return rear==0;
}

template<class QueueEntry>
bool Queue_S<QueueEntry>::Full() const {
    return rear == MAXQUEUE - 1;
}

template<class QueueEntry>
void Queue_S<QueueEntry>::Display() {
    cout << "The queue is :" << endl;
    for (int i = 0; i < rear + 1; i++)
        cout << Entry[i] << " ";
    cout << endl;
}
