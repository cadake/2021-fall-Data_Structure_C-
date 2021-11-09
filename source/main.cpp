#include <iostream>
#include "../include/stack.h"

using namespace std;

class A{
    public:
        int data;
        double d = 0;
        A(int data): data(data) {}
};

int main()
{
    // stack<int> s;
    // for (int i=0; i<10; i++)
    //     s.push(i);
    // while ( !s.isEmpty() )
    //     cout << s.pop() << " ";
    // cout << endl;

    stack<A> s;
    s.push(A(3));
    s.push(A(2));
    s.push(A(0));

    while (!s.isEmpty())
    {
        A a = s.pop();
        cout << a.data << " " << a.d << " ";
    }
    cout << endl;

    return 0;
}