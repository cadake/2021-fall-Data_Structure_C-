#ifndef TEST_H
#define TEST_H
#include <vector>
#include <string>

using namespace std;

class A
{
    public:
        int data;
        double d;

    public:
        A(int data, double d) : data(data), d(d){};
};

class test{
    private:
        vector<void(*)()> testcases;

    public:
        test();
        void runTest();
};

void printPass(string str);
void stackTest();
void queueTest();
void AVLTreeTest();

#endif