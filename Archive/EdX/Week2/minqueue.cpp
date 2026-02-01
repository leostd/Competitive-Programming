#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("queuemin.in");
    std::ofstream cout("queuemin.out");
#else
    #include <iostream>
    using std::cin;
    using std::cout;
#endif

#include <stack>
#include <queue>
#include <limits>

typedef long long int lli;

int main()
{
    int n;
    int size = 0;
    lli x;
    char op;
    cin >> n;
    std::stack<lli> s1, s2;
    std::stack<lli> mins1, mins2;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        if (op == '+')
        {
            cin >> x;
            if(s1.empty())
            {
                s1.push(x);
                s2.push(x);
                mins1.push(x);
                mins2.push(x);
            }
            else
            {
                lli minaux = mins2.top();
                s2.push(x);
                if (x < minaux)
                    mins2.push(x);
                else
                    mins2.push(minaux);
                flag = true;
            }
            ++size;
        }
        else if (op == '-')
        {   
            s1.pop();
            mins1.pop();
            --size;
            if (!mins2.empty())
            {

            }
            lli tail = s2.top();
            if (s1.empty())
            {
                for (int i = 0; i < size; ++i)
                {
                    lli f = s2.top();
                    s1.push(f);
                    if (mins1.empty())
                    {
                        mins1.push(f);
                    }
                    else
                    {
                        lli minaux = mins1.top();
                        if (f < minaux)
                            mins1.push(f);
                        else
                            mins1.push(minaux);
                    }
                    s2.pop();
                    mins2.pop();
                }
                while(!mins2.empty() || !s2.empty())
                {
                    mins2.pop();
                    s2.pop();
                }
                if(!s1.empty())
                {
                    mins2.push(tail);
                    s2.push(tail);    
                }
                flag = false;
            }

        }
        else if (op == '?')
        {
            if (flag)
            {
                cout << (mins2.top() < mins1.top() ? mins2.top() : mins1.top()) << "\n";
            }
            else
            {
                cout << mins1.top() << "\n";
            }
        }
        cin.ignore();
    }
    return 0;
}