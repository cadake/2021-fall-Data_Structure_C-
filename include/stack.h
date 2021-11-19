#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template<typename T>
class stack{
    struct node {
        T obj;
        node* next;
        node(const T & obj): obj(obj) {};
    };

    private:
        node* top = nullptr;

    public:
        stack() {}
        void push(const T & obj) {
            node *newNode = new node(obj);
            newNode->next = top;
            top = newNode;
        };
        T pop() {
            node *ret = top;
            top = top->next;
            T obj = move(ret->obj);
            delete ret;
            return obj;
        };
        bool isEmpty() {
            return (top == nullptr);
        };
        void clear() {
            while (top) {
                node *pNode = top;
                top = top->next;
                delete pNode;
            }
        }
        ~stack() {
            cout << "in ~stack" << endl;
            this->clear();
        };
};

#endif