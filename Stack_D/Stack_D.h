#include <iostream>
#define INITSIZE 100
#define TIMES 2
using namespace std;

enum ErrorCode {
    Success,
    Underflow,
    Overflow
};

//typedef int StackEntry;

static int maxStackSize = 0;

template<class StackEntry>
class Stack_D {
    public:
        Stack_D();
        ErrorCode Push(const StackEntry & Item);
        ErrorCode Top(StackEntry & Item);
        ErrorCode Pop();
        ErrorCode Pop(StackEntry & Item);
        void Lengthen();  //  new function
        bool Empty();
        bool Full();
        void Display();
        void Clear();
        int GetCount();
    private:
        int top;  //  record the position of the top entry
        StackEntry *Entry;
};

