#include "Queue_Stack.h"

template<class QueueEntry>
bool Queue_Stack<QueueEntry>::IsEmpty() const {
    return (first.size()==0&&second.size()==0);
}

template<class QueueEntry>
int& Queue_Stack<QueueEntry>::front() {
    while (!first.empty()) {
        QueueEntry temp = first.top();
        second.push(temp);
        first.pop();
    }
    return second.top();
}

template<class QueueEntry>
void Queue_Stack<QueueEntry>::push(QueueEntry a) {
    if (!second.size()) {
        first.push(a);
    } else {
        while (!second.size()) {
            QueueEntry temp = second.top();
            first.push(temp);
            second.pop();
        }
        first.push(a);
    }
}

template<class QueueEntry>
void Queue_Stack<QueueEntry>::pop() {
    while (!first.empty()) {
        QueueEntry temp = first.top();
        second.push(temp);
        first.pop();
    }
    second.pop();
    while (!second.empty()) {
        QueueEntry tmp = second.top();
        first.push(tmp);
        second.pop();
    }
}

