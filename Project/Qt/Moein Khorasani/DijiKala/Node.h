#ifndef NODE_H
#define NODE_H




#include <iostream>

using namespace std;

template <typename T>
class Node
{
    T data;
    Node<T> * prev=nullptr, * next=nullptr;
public:
    Node(const T& data)
        :prev(nullptr),next(nullptr)
    {
        //Conversion Constructor
        this->data = data;
    }

    Node (const Node<T> & rvalue)
    {
       throw error_code();
    }

    void setData(const T& data) { this->data = data; }
    void setPrev(Node<T>* ptr) { this->prev = ptr; }
    void setNext(Node<T>* ptr) { this->next = ptr; }

    T  getData()const  { return this->data; }
    Node<T>* getPrev()const { return this->prev; }
    Node<T>* getNext()const { return this->next; }

    T operator= (const T& data)
    {
        this->data = data;
        return data;
    }



};


template <typename T>
ostream& operator<< (ostream& out, const Node<T>& node)
{
    //Print Function
    cout << node.getData();
    return out;
}
template <typename T>
void swapContent(Node<T> & a, Node<T>& b)
{
    T temp = a.getData();
    a.setData(b.getData());
    b.setData(temp);

    return;
}




#endif // NODE_H
