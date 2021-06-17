#include <iostream>
#include <stack>

using namespace std;

stack<int> A;
stack<int> B;
stack<int> C;

void print_stack(stack<int> s)
{
    if (s.empty())
    {
        return;
    }
    int temp = s.top();
    s.pop();
    print_stack(s);
    cout << temp << " ";
}

void print_stacks()
{
    cout << "----" << endl;
    stack<int> temp = A;
    cout << "A : ";
    print_stack(temp);
    cout << endl;
    temp = B;
    cout << "B : ";
    print_stack(temp);
    cout << endl;
    temp = C;
    cout << "C : ";
    print_stack(temp);
    cout << endl;
    cout << "----" << endl;
}

void toh(int n, stack<int> &initial, stack<int> &intermediate, stack<int> &final)
{
    if (n <= 1)
    {
        final.push(initial.top());
        initial.pop();
        print_stacks();
    }
    else
    {
        toh(n - 1, initial, final, intermediate);
        final.push(initial.top());
        initial.pop();
        print_stacks();
        toh(n - 1, intermediate, initial, final);
    }
}

int main()
{
    int n = 3;
    for (int i = n; i > 0; i--)
    {
        A.push(i);
    }
    print_stacks();
    toh(n, A, B, C);
    return 0;
}