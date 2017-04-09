/*
    Input
The ﬁrst line of the input ﬁle contains a single integer number N (1 ≤ N ≤ 106) – the number of commands. 
N lines follow, each line contains exactly one command. There are the following commands:
+ x: push x to the stack. Every x will be an integer such that |x|≤ 109. The symbol + 
and the number will be separated by exactly one white space.
−: pop an element from the stack. It is guaranteed that this operation 
will never be executed on an empty stack. There will be at least one such operation.

    Output
Output the integers popped from the stack, one per line, in the order they were popped.
*/

#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("stack.in");
    std::ofstream cout("stack.out");
#else
    #include <iostream>
    using std::cin;
    using std::cout;
#endif

#include<stack>

typedef long long int lli;

int main()
{
    int n;
    char op;
    std::stack<lli> stk;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        if (op == '+')
        {
            lli num;
            cin >> num;
            stk.push(num);
        }
        if(op == '-')
        {
            lli num = stk.top();
            stk.pop();
            cout << num << "\n";
        }
        cin.ignore();
    }
    return 0;
}