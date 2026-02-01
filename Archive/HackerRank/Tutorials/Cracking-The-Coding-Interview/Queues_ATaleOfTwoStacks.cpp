#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        int size = 0;
        void push(int x) {
           stack_oldest_on_top.push(x);
           size++;
        }

        void pop() {
            if (size > 0)
            {
                if (!stack_newest_on_top.empty())
                {
                    stack_newest_on_top.pop();
                }
                else
                {
                    if (!stack_oldest_on_top.empty())
                    {
                        int a;
                        while(!stack_oldest_on_top.empty())
                        {
                            a = stack_oldest_on_top.top();
                            stack_oldest_on_top.pop();
                            stack_newest_on_top.push(a);
                        }
                        stack_newest_on_top.pop();
                    }
                }
                size--;
            }
        }

        int front() {
            if (size > 0)
            {
                if (!stack_newest_on_top.empty())
                {
                    return stack_newest_on_top.top();
                }
                else
                {
                    if (!stack_oldest_on_top.empty())
                    {
                        int a;
                        while(!stack_oldest_on_top.empty())
                        {
                            a = stack_oldest_on_top.top();
                            stack_oldest_on_top.pop();
                            stack_newest_on_top.push(a);
                        }
                        return stack_newest_on_top.top();
                    }
                }
            }
            return -1;
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
