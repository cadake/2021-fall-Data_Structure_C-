#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <typename T>
class queue
{
    struct node
    {
        T obj;
        node *next = nullptr;
        node(const T &obj) : obj(obj){};
    };

    private:
        node *head = nullptr;
        node *tail = nullptr;

    public:
        queue() {}
        void push(const T &obj)
        {
            node *newNode = new node(obj);
            if (head != nullptr)
                head->next = newNode;
            head = newNode;
            if (tail == nullptr)
                tail = head;
        };
        T pop()
        {
            node *ret = tail;
            tail = tail->next;
            if (tail == nullptr)
                head = nullptr;
            T obj = move(ret->obj);
            delete ret;
            return obj;
        };
        bool isEmpty()
        {
            return (tail == nullptr);
        };
        void clear() {
            while (tail) {
                node *pNode = tail;
                tail = tail->next;
                delete pNode;
            }
            head = nullptr;
        }
        ~queue()
        {
            cout << "in ~queue" << endl;
            this->clear();
        };
};

#endif