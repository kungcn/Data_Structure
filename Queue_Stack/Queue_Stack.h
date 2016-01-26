#include <iostream>
#include <stack>  //  can use the static stack written by myself
using namespace std;

#define MAXQUEUE 5

enum ErrorCode {
    Success,
    Underflow,
    Overflow
};

template<class QueueEntry>
class Queue_Stack {
  public:
    bool IsEmpty() const;
    int &front();
    void push(QueueEntry a);
    void pop();
  private:
    stack<QueueEntry> first;
    stack<QueueEntry> second;
};
    
