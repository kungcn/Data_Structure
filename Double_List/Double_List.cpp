#include "Double_List.h"

template <class List_entry>
Double_List<List_entry>::Double_List() {
    
}

template <class List_entry>
Double_List<List_entry>::~Double_List() {

}

// 拷贝构造函数和赋值运算符重载，注意深拷贝与浅拷贝的差异
template <class List_entry>
Double_List<List_entry>::Double_List(const Double_List<List_entry> &copy) {
S
}

template <class List_entry>
void Double_List<List_entry>::operator =(const Double_List<List_entry> &copy) {

}

// 清空list
template <class List_entry>
void Double_List<List_entry>::clear() {

}

// 判断list是否为空
template <class List_entry>
bool Double_List<List_entry>::empty() const {

}

// 判断list是否已满
template <class List_entry>
bool Double_List<List_entry>::full() const {

}

// 获取list的元素数量
template <class List_entry>
int Double_List<List_entry>::size() const {

}

// 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，依次类推
// 若position < 0 或者 position > count，则返回underflow
template <class List_entry>
Error_code Double_List<List_entry>::insert(int position, const List_entry &entry) {

}

// 删除第position个位置的元素，并将该元素的值保存在entry中
// 若position < 0 或者 position >= count，则返回underflow
template <class List_entry>
Error_code Double_List<List_entry>::remove(int position, List_entry &entry) {

}

// 获取第position个位置的元素，保存在entry中
// 若position < 0 或者 position >= count，则返回underflow
template <class List_entry>
Error_code Double_List<List_entry>::retrieve(int position, List_entry &entry) const {

}

// 将第position个位置的元素替换为entry
// 若position < 0 或者 position >= count，则返回underflow
template <class List_entry>
Error_code Double_List<List_entry>::replace(int position, const List_entry &entry) {

}

// 用visit函数遍历list内所有的元素
template <class List_entry>
void Double_List<List_entry>::traverse(void (*visit)(List_entry &)) {

}

// 设置current指针的位置，指向第position个位置
template <class List_entry>
void Double_List<List_entry>::setPosition(int position) const {

}

