#include "Stack_L.h"

template<class StackEntry>
Stack_L<StackEntry>::Stack_L() {
    pTop = NULL;
}

template<class StackEntry>
bool Stack_L<StackEntry>::empty() const {
		return pTop == NULL;
}

template<class StackEntry>
ErrorCode Stack_L<StackEntry>::pop() {
    Node<StackEntry>* oldTop = pTop;
    if (empty())
        return underflow;
    pTop = pTop->next;
    delete oldTop;
    return success;
}

template<class StackEntry>
ErrorCode Stack_L<StackEntry>::top(StackEntry &item) const {
    if (empty())
        return underflow;
    item = pTop->data;
    return success;
}

template<class StackEntry>
ErrorCode Stack_L<StackEntry>::push(const StackEntry &item) {
    Node<StackEntry> *newTop;
    newTop = new Node<StackEntry>;
    if (newTop == NULL)
        return overflow;

    newTop->data = item;
    newTop->next = pTop;
    pTop = newTop;
    return success;
}

template<class StackEntry>
void Stack_L<StackEntry>::clear() {
    while (!empty())
        pop();
}

template<class StackEntry>
int Stack_L<StackEntry>::size() const {
    Node<StackEntry> *top = pTop;
    int count = 0;
    while (top != NULL) {
        count++;
        top = top->next;
    }
    return count;
}
