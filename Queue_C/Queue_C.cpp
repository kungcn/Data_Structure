#include "Queue_C.h"

template <class QueueEntry>
Queue_C<QueueEntry>::Queue_C() {
	front = 0; 
	rear = maxQueue - 1;
}

template <class QueueEntry>
bool Queue_C<QueueEntry>::empty() const {
    return size() == 0;
}

template <class QueueEntry>
ErrorCode Queue_C<QueueEntry>::append(const QueueEntry &item) {
	if (full())
        return overflow;
    else {
    	rear = ((rear + 1 == maxQueue))? 0 : rear + 1;
    	entry[rear] = item;
    	return success;
    }
}

template <class QueueEntry>
ErrorCode Queue_C<QueueEntry>::serve() {
	if (empty())
	    return underflow;
	else {
		front = ((front + 1) == maxQueue)? 0 : front + 1;
		return success;
	}
}

template <class QueueEntry>
ErrorCode Queue_C<QueueEntry>::retrieve(QueueEntry &item) const {
    if (empty())
        return underflow;
    else {
    	item = entry[front];
    	return success;
    }
}

template <class QueueEntry>
bool Queue_C<QueueEntry>::full() const {
    return size() == maxQueue - 1;
}

template <class QueueEntry>
int Queue_C<QueueEntry>::size() const {
    return (rear - front + 1 + maxQueue) % maxQueue;
}

template <class QueueEntry>
void Queue_C<QueueEntry>::clear() {
	while(!empty())
		serve();
}

template <class QueueEntry>
ErrorCode Queue_C<QueueEntry>::retrieve_and_serve(QueueEntry &item) {
	if (empty())
	    return underflow;
	else {
	retrieve(item);
	serve();
	return success;
}
}
