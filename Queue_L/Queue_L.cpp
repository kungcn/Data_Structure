#include "Queue_L.h"

template<class QueueEntry>
Queue_L<QueueEntry>::Queue_L() {
    front = rear = NULL;
}

template<class QueueEntry>
bool Queue_L<QueueEntry>::empty() const {
    if (front == NULL)
        return true;
    return false;
}

template<class QueueEntry>
ErrorCode Queue_L<QueueEntry>::append(const QueueEntry &item) {
    Node<QueueEntry>*goal = new Node<QueueEntry>;
    if (goal == NULL)
        return overflow;
    goal->data = item;
    goal->next = NULL;
    if (rear == NULL)
        front = rear = goal;
    else {
        rear->next = goal;
        rear = goal;
    }
    return success;
}

template<class QueueEntry>
ErrorCode Queue_L<QueueEntry>::serve() {
    if (empty())
        return underflow;
    Node<QueueEntry>*temp = front;
    front = front->next;
    if (front == NULL)
        rear = front;
    delete temp;
    return success;
}

template<class QueueEntry>
ErrorCode Queue_L<QueueEntry>::retrieve(QueueEntry &item) const {
    if (empty())
        return underflow;
    item = front->data;
    return success;
}

template<class QueueEntry>
int Queue_L<QueueEntry>::size() const {
    int count = 0;
    Node<QueueEntry>* temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

template<class QueueEntry>
void Queue_L<QueueEntry>::clear() {
    while (!empty())
        serve();
}

template<class QueueEntry>
ErrorCode Queue_L<QueueEntry>::retrieve_and_serve(QueueEntry &item) {
    if (empty())
        return underflow;
    retrieve(item);
    serve();
    return success;
}
