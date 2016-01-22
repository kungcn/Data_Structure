#define MAXSTACK 100
#include <iostream>
using namespace std;

enum ErrorCode {
    Success,
    Underflow,
    Overflow
};

typedef int StackEntry;

class Stack_S {
    public:
        Stack_S();
        ErrorCode Push(const StackEntry & Item);
        ErrorCode Top(StackEntry & Item);
        ErrorCode Pop();
        ErrorCode Pop(StackEntry & Item);
        bool Empty();
        bool Full();
        void Display();
        void Clear();
        int GetCount();
    private:
        int top;  //  record the position of the top entry
        StackEntry Entry[MAXSTACK];
};

