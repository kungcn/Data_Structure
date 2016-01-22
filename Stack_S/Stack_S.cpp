#include "Stack_S.h"

template<class StackEntry>
Stack_S<StackEntry>::Stack_S() {
    top = -1;
}

template<class StackEntry>
bool Stack_S<StackEntry>::Empty() {
    return (top == -1);
}

template<class StackEntry>
bool Stack_S<StackEntry>::Full() {
    return (top == MAXSTACK - 1);
}

template<class StackEntry>
void Stack_S<StackEntry>::Clear() {
    top = -1;
}

template<class StackEntry>
int Stack_S<StackEntry>::GetCount() {
    return top + 1;
}

template<class StackEntry>
ErrorCode Stack_S<StackEntry>::Push(const StackEntry & Item) {
    if (Full())
        return Overflow;
    Entry[top + 1] = Item;
    top++;
    return Success;
}

template<class StackEntry>
ErrorCode Stack_S<StackEntry>::Top(StackEntry & Item) {
    if (Empty())
        return Underflow;
    Item = Entry[top];
    return Success;
}

template<class StackEntry>
ErrorCode Stack_S<StackEntry>::Pop() {
    if (Empty())
        return Underflow;
    top--;
    return Success;
}

template<class StackEntry>
ErrorCode Stack_S<StackEntry>::Pop(StackEntry & Item) {
    if (Empty())
        return Underflow;
    Top(Item);
    Pop();
    return Success;
}

template<class StackEntry>
void Stack_S<StackEntry>::Display() {
    for (int i = 0; i < GetCount(); i++)
        cout << Entry[i] << endl;
}
