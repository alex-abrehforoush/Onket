#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#include "Node.h"

template <typename T>
class LinkedList
{
    Node<T>* head=nullptr;
    Node<T>* tail=nullptr;

public:

    void addFront(const T& data)
    {
        Node<T>* temp=new Node<T> (data);
        if(head == nullptr)
        {
            head=temp;
            tail=head;
            return;
        }

      else
        {
            temp->setNext(head);
            head->setPrev(temp);
            head=temp;
            return;
        }

    }

    void pushBack(const T& data)
    {
        Node<T>* temp=new Node<T> (data);
        if(tail == nullptr)
        {
            tail=temp;
            head=tail;
            return;
        }

        else
        {
            temp->setPrev(tail);
            tail->setNext(temp);
            tail=temp;
            return;
        }


    }
    void push(int index, const T& data)
    {
         Node<T>* current=head;
         Node<T>* last=nullptr;
         int cnt=0;

        for(;cnt<index && current != nullptr ;cnt++)
        {   last=current;

            current=current->getNext();
        }

        if(last == nullptr)//index is zero or addfront
        {
            this->addFront(data);
        }

        else if(current == nullptr )
             {
                 if(cnt < index)
                      {
                         return;
                       }

                 else
                 {

                      this->pushBack(data);
                 }

                }
        else
        {
            Node<T>* temp=new Node<T> (data);
            temp->setPrev(last);
            last->setNext(temp);

            temp->setNext(current);
            current->setPrev(temp);

        }
     }



    void popFront()
    {
        if(head==nullptr)
        {
            return;
        }
        else if(head==tail)
        {
            delete head;
            head=tail=nullptr;
        }
        else
        {
            Node<T>* temp =head;
            head=head->getNext();
            head->setPrev(nullptr);
           delete temp;
        }

    }
    void popBack()
    {
        if(head==nullptr)
        {
            return;
        }
        else if(tail==head)
        {
            delete tail;
            tail=head=nullptr;
        }
        else
        {
            Node<T>* temp=tail;
            tail=tail->getPrev();
            tail->setNext(nullptr);
            delete temp;

        }
    }

    void pop(int index)
    {
        Node<T>* current=head;
         Node<T>* last=nullptr;
         int cnt=0;
         for(;cnt<index && current != tail ;cnt++)
         {   last=current;

             current=current->getNext();
         }

         if(last == nullptr)//index is zero or addfront
         {
           this->popFront();
         }
         else if(current == tail)
         {
             if(cnt<index)
                 return;

            this->popBack();

         }
         else
         {
             last->setNext(current->getNext());
             current->getNext()->setPrev(last);

             delete current;
             current=nullptr;
         }
    }


    LinkedList()
        :head(nullptr), tail(nullptr)
    {
        //constructor
    }
    LinkedList(const LinkedList& rvalue)
    :head(nullptr),tail(nullptr)
    {
        Node<T>* current=rvalue.head;

        while(current!=nullptr)
        {
            this->pushBack(current->getData());
            current=current->getNext();
        }
    }


    LinkedList(LinkedList&& rvalue)
        :head(nullptr),tail(nullptr)

    {
        this->head=rvalue.head;
        this->tail=rvalue.tail;

        rvalue.head=rvalue.tail=nullptr;
    }
    ~LinkedList()
    {


        while(head !=nullptr)
            {

        this->popFront();
            }
       head=tail=nullptr;
}

    LinkedList operator=  (const LinkedList& rvalue)
    {
        this->~LinkedList();
        Node<T>* current=rvalue.head;

        while(current!=nullptr)
        {
            this->pushBack(current->getData());
            current=current->getNext();
        }

    }
    bool operator== (const LinkedList& rvalue)
    {
        Node<T>* curr_1=this->head;
        Node<T>* curr_2=rvalue.head;

        while(curr_1 != nullptr && curr_2 != nullptr)
        {
            if(curr_1->getData() != curr_2->getData())
                return false;
            curr_1=curr_1->getNext();
            curr_2=curr_2->getNext();
        }
        if(curr_1 != curr_2)
            return false;

        return true;

    }
    bool operator!= (const LinkedList& rvalue)
    {
        return !(*this == rvalue);
    }

    LinkedList operator+ (const T& data)
    {
        LinkedList res=*this;
        res.pushBack(data);
        return res;
    }
    void operator+= (const T& data)//pushback
    {
        this->pushBack(data);
    }
    Node<T>& operator[] (int index)
    {
        Node<T>* current=head;
        int cnt=0;
        for(;cnt<index && current != nullptr;cnt ++)
        {
            current=current->getNext();
        }

        if(current==nullptr || index<0)
        {
           throw invalid_argument("nullptr");
        }
        else
        {
            return *current;
        }
    }




    int search(const T& data)const //return index of instance
    {
        Node<T>* current=head;

       for(int cnt=0;current != nullptr;cnt++)
       {
           if(current->getData() == data)
               return cnt;
           current=current->getNext();
       }
       return -1;//not found
    }
};




template<typename T>
ostream& operator<< (ostream& out, const LinkedList<T>& list)
{//print list
    return out;
}



#endif // LINKEDLIST_H
