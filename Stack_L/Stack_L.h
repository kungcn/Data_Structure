#include <cstdlib>
#include <iostream>
using namespace std;

enum ErrorCode {
	success,
	underflow,
	overflow
};

template<class StackEntry>
struct Node {
	StackEntry data;
	Node *next;
};

template<class StackEntry>
class Stack_L {
  public:
    Stack_L();
    bool empty() const;
    ErrorCode pop();
    ErrorCode top(StackEntry &item) const;
    ErrorCode push(const StackEntry &item);
    void clear();
    int size() const;
  private:
    Node<StackEntry> *pTop;
};
