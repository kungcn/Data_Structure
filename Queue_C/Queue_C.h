#include <iostream>
#define maxQueue 100
using namespace std;

enum ErrorCode {
	success,
	underflow,
	overflow
};

template <class QueueEntry>
class Queue_C {
	public:
	    Queue_C();
		bool empty() const;
		ErrorCode append(const QueueEntry &item);
		ErrorCode serve();
		ErrorCode retrieve(QueueEntry &item) const;
		bool full() const;
		int size() const;
		void clear();
		ErrorCode retrieve_and_serve(QueueEntry &item);
		//void print();
	private:
		int front;
		int rear;
		QueueEntry entry[maxQueue];
};
