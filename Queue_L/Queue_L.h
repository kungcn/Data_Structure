#include <cstdlib>
#include <iostream>
using namespace std;

enum ErrorCode {
	success,
	underflow,
	overflow
};

template<class QueueEntry>
struct Node {
	QueueEntry data;
	Node<QueueEntry> *next;
};

template<class QueueEntry>
class Queue_L {
  public:
    Queue_L();
    bool empty() const;
    ErrorCode append(const QueueEntry &item);
    ErrorCode serve();
    ErrorCode retrieve(QueueEntry &item) const;
    int size() const;
    void clear();
    ErrorCode retrieve_and_serve(QueueEntry &item);
  private:
    Node<QueueEntry> *front;
    Node<QueueEntry> *rear;
};
