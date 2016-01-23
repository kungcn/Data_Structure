#include <iostream>
using namespace std;

#define MAXQUEUE 5

enum ErrorCode {
    Success,
    Underflow,
    Overflow
};

template<class QueueEntry>
class Queue_S {
  public:
    Queue_S();
    Err_Code Append(const Queue_Entry & Item);
    Err_Code Server();
    Err_Code Retrieve(Queue_Entry & Item) const;
    bool Empty() const;
    bool Full() const;
    int GetRear();
    void Display();
  private:
    int rear;
    Queue_Entry Entry[MAXQUEUE];
};
