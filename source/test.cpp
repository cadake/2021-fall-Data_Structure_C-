#include "../include/test.h"
#include "../include/queue.h"
#include "../include/stack.h"
#include "../include/AVLTree.h"
#include <vector>
#include <assert.h>
#include <windows.h>
#include <ctime>
#include <random>

using namespace std;

test::test() {
    testcases.push_back(stackTest);
    testcases.push_back(queueTest);
    testcases.push_back(AVLTreeTest);
}

void test::runTest() {
    for (int i = 0; i < int(testcases.size()); i++) {
        testcases[i]();
    }
}

void stackTest()
{
    vector<A> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(A(i, 0));
    }
    stack<A> s;
    for (int i = 0; i < int(v.size()); i++)
    {
        s.push(v[i]);
    }
    for (int i = 19; i >= 0; i--)
    {
        assert(s.pop().data == i);
    }
    printPass("stack");
}

void queueTest()
{
    vector<A> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(A(i, 0));
    }
    queue<A> q;
    for (int i = 0; i < int(v.size()); i++)
    {
        q.push(v[i]);
    }
    for (int i = 0; i < 20; i++)
    {
        assert(q.pop().data == i);
    }
    printPass("queue");
}

void AVLTreeTest()
{
    int size = 1000;
    int cnt = 1000000;

    int A[size];
    AVLTree<int> tree;
    for (int i = 0; i < size; i++)
    {
        tree.insert(i);
        A[i] = i;
    }

    default_random_engine e;
    uniform_int_distribution<int> u(0, 999);
    clock_t start, end;

    cout << "with size " << size << " cnt " << cnt << endl;
    start = clock();
    for (int i = 0; i < cnt; i++)
    {
        tree.find(u(e));
    }
    end = clock();
    cout << "AVLTree used " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    for (int i = 0; i < cnt; i++)
    {
        int f = u(e);
        for (int i = 0; A[i] != f; i++)
            ;
    }
    end = clock();
    cout << "Array used " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    printPass("AVLTree");
}

void printPass(string str)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout << str << "_test passed!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}