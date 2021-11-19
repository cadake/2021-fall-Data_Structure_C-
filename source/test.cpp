#include "../include/test.h"
#include "../include/queue.h"
#include "../include/stack.h"
#include <vector>
#include <assert.h>
#include <windows.h>

using namespace std;

test::test() {
    testcases.push_back(stackTest);
    testcases.push_back(queueTest);
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

void printPass(string str)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout << str << "_test passed!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}