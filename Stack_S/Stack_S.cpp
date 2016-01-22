#include "Stack_S.h"

Stack_S::Stack_S() {
    top = -1;
}

bool Stack_S::Empty() {
    return (top == -1);
}

bool Stack_S::Full() {
    return (top == MAXSTACK - 1);
}

void Stack_S::Clear() {
    top = -1;
}

int Stack_S::GetCount() {
    return top + 1;
}

ErrorCode Stack_S::Push(const int & Item) {
    if (Full())
        return Overflow;
    Entry[top + 1] = Item;
    top++;
    return Success;
}

ErrorCode Stack_S::Top(int & Item) {
    if (Empty())
        return Underflow;
    Item = Entry[top];
    return Success;
}

ErrorCode Stack_S::Pop() {
    if (Empty())
        return Underflow;
    top--;
    return Success;
}

ErrorCode Stack_S::Pop(int & Item) {
    if (Empty())
        return Underflow;
    Top(Item);
    Pop();
    return Success;
}

void Stack_S::Display() {
    for (int i = 0; i < GetCount(); i++)
        cout << Entry[i] << endl;
}
