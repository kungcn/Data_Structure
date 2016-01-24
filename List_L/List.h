#include <cstdlib>
#include <iostream>
using namespace std;

enum ErrorCode {
	success,
	underflow,
	overflow
};

template<class ListEntry>
struct Node {
	ListEntry entry;
	Node<ListEntry> *next;
};

template<class ListEntry>
class List_L {
  public:
    List_L();
    ~List_L();
    List_L(const List_L<ListEntry> &copy);
    void operator =(const List_L<ListEntry> &copy);
    void clear();
    bool empty() const;
    bool full() const;
    int size() const;
    ErrorCode insert(int position, const ListEntry &entry);
    ErrorCode remove(int position, ListEntry &entry);
    ErrorCode retrieve(int position, ListEntry &entry) const;
    ErrorCode replace(int position, const ListEntry &entry);
    void traverse(void (*visit)(ListEntry &));

  protected:
  	int count;
  	Node<ListEntry> *head;

  	mutable int curPosition;
  	mutable Node<ListEntry> *current;

  	void setPosition(int position) const;

};
