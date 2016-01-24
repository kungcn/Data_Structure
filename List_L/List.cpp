#include "List.h"

template<class ListEntry>
List_L<ListEntry>::List_L() {
    count = curPosition = 0;
    head = current = NULL;
}

template<class ListEntry>
List_L<ListEntry>::~List_L() {
    clear();
}

template<class ListEntry>
List_L<ListEntry>::List_L(const List_L<ListEntry> &copy) {
    if (copy.head == NULL) {
        count = curPosition = 0;
        head = current = NULL;
    } else {
        Node<ListEntry> *temp = copy.head;
        Node<ListEntry> *temp1 = new Node<ListEntry>;
        temp1->entry = temp->entry;
        temp1->next = NULL;
        head = temp1;
        while (temp->next!=NULL) {
            temp = temp->next;
            Node<ListEntry> *temp2 = new Node<ListEntry>;
            temp2->entry = temp->entry;
            temp2->next = NULL;
            temp1->next = temp2;
            temp1 = temp2;
        }
        curPosition = 0;
        count = copy.size();
        current = head;
        setPosition(copy.curPosition);
    }
}

template<class ListEntry>
void List_L<ListEntry>::operator =(const List_L<ListEntry> &copy) {
    clear();
    if (copy.head == NULL) {
        count = curPosition = 0;
        head = current = NULL;
    } else {
        if (copy.head == head) return;
        Node<ListEntry> *temp = copy.head;
        Node<ListEntry> *temp1 = new Node<ListEntry>;
        temp1->entry = temp->entry;
        temp1->next = NULL;
        head = temp1;
        while (temp->next!=NULL) {
            temp = temp->next;
            Node<ListEntry> *temp2 = new Node<ListEntry>;
            temp2->entry = temp->entry;
            temp2->next = NULL;
            temp1->next = temp2;
            temp1 = temp2;
        }
        curPosition = 0;
        count = copy.size();
        current = head;
        setPosition(copy.curPosition);
    }
}

template<class ListEntry>
void List_L<ListEntry>::clear() {
    curPosition = 0;
    current = NULL;
    while (!empty()) {
        Node<ListEntry> *temp = head;
        head = head->next;
        delete temp;
        count--;
    }
}

template<class ListEntry>
bool List_L<ListEntry>::empty() const {
    return count == 0;
}

template<class ListEntry>
bool List_L<ListEntry>::full() const {
    int tmp = 0;
    Node<ListEntry> *temp = new Node<ListEntry>;
    if (temp == NULL)
        tmp = 1;
    delete temp;
    return tmp == 1;
}

template<class ListEntry>
int List_L<ListEntry>::size() const {
    return count;
}

template<class ListEntry>
ErrorCode List_L<ListEntry>::insert(int position, const ListEntry &entry) {
    if (position < 0 || position > count)
        return underflow;
    if (position == 0) {
        Node<ListEntry> *temp = new Node<ListEntry>;
        temp->entry = entry;
        temp->next = head;
        head = temp;
        count++;
        return success;
    } else {
        setPosition(position - 1);
        Node<ListEntry> *temp = new Node<ListEntry>;
        temp->entry = entry;
        temp->next = current->next;
        current->next = temp;
        count++;
        return success;
    }
}

template<class ListEntry>
ErrorCode List_L<ListEntry>::remove(int position, ListEntry &entry) {
    if (position < 0 || position >= count)
        return underflow;
    if (position == 0) {
        Node<ListEntry> *temp = head;
        entry = head->entry;
        head = head->next;
        delete temp;
        count--;
        return success;
    } else {
        setPosition(position - 1);
        Node<ListEntry> *temp = current->next;
        current->next = temp->next;
        entry = temp->entry;
        delete temp;
        count--;
        return success;
    }
}

template<class ListEntry>
ErrorCode List_L<ListEntry>::retrieve(int position, ListEntry &entry) const {
    if (position < 0 || position >= count)
        return underflow;
    setPosition(position);
    entry = current->entry;
    return success;
}

template<class ListEntry>
ErrorCode List_L<ListEntry>::replace(int position, const ListEntry &entry) {
    if (position < 0 || position >= count)
        return underflow;
    setPosition(position);
    current->entry = entry;
    return success;
}

template<class ListEntry>
void List_L<ListEntry>::traverse(void (*visit)(ListEntry &)) {
    Node<ListEntry> *temp = head;
    while (temp != NULL) {
        (*visit)(temp->entry);
        temp = temp->next;
    }
}

template<class ListEntry>
void List_L<ListEntry>::setPosition(int position) const {
    if (curPosition == 0)
        current = head;
    if (position < curPosition) {
        curPosition = 0;
        current = head;
    }
    for (; curPosition != position; curPosition++) {
        current = current->next;
    }
}
