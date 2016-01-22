#include "Stack_D.h"

template<class StackEntry>
Stack_D<StackEntry>::Stack_D() {
    top = -1;
    Entry = new StackEntry[INITSIZE];
    maxStackSize = INITSIZE;
}

template<class StackEntry>
bool Stack_D<StackEntry>::Empty() {
    return (top == -1);
}

template<class StackEntry>
bool Stack_D<StackEntry>::Full() {
    return (top == maxStackSize - 1);
}

template<class StackEntry>
void Stack_D<StackEntry>::Clear() {
    top = -1;
    delete []Entry;
}

template<class StackEntry>
int Stack_D<StackEntry>::GetCount() {
    return top + 1;
}

template<class StackEntry>
ErrorCode Stack_D<StackEntry>::Push(const StackEntry & Item) {
    if (Full())
        Lengthen();
    Entry[top + 1] = Item;
    top++;
    return Success;
}

template<class StackEntry>
ErrorCode Stack_D<StackEntry>::Top(StackEntry & Item) {
    if (Empty())
        return Underflow;
    Item = Entry[top];
    return Success;
}

template<class StackEntry>
ErrorCode Stack_D<StackEntry>::Pop() {
    if (Empty())
        return Underflow;
    top--;
    return Success;
}

template<class StackEntry>
ErrorCode Stack_D<StackEntry>::Pop(StackEntry & Item) {
    if (Empty())
        return Underflow;
    Top(Item);
    Pop();
    return Success;
}

template<class StackEntry>
void Stack_D<StackEntry>::Lengthen() {
    StackEntry *temp;
    int count = maxStackSize;
    temp = new StackEntry[maxStackSize];
    for (int i = 0; i < count; i++)
        temp[i] = Entry[i];
    delete []Entry;
    maxStackSize *= TIMES;
    Entry = new StackEntry[maxStackSize];  //  Actually count will not change until the top position changes
    for (int i = 0; i < count; i++)
        Entry[i] = temp[i];
    delete []temp;
}

template<class StackEntry>
void Stack_D<StackEntry>::Display() {
    for (int i = 0; i < GetCount(); i++)
        cout << Entry[i] << endl;
}
