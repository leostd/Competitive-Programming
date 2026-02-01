#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("stacks.in");
    std::ofstream cout("stacks.out");
#else
    #include <iostream>
    using std::cin;
    using std::cout;
#endif

#include <stack>
#include <utility>

typedef std::pair<int, int> ii;

int main()
{
    int n;
    int cup;
    ii minv, aux;
    std::stack<ii> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cup;
        if (s.empty())
        {
            s.emplace(1,1);
        }
        else
        {
            minv = s.top();
            if (cup == 0)
            {
                s.pop();
                minv.second--;
                minv.first++;
                if (s.empty())
                {
                    aux = minv;
                    if (minv.second == 0)
                        s.emplace(minv.first, 1);
                    else
                    {
                        s.emplace(minv.first, 1);
                        s.emplace(minv.first-1, minv.second);
                    }
                }
                else
                {
                    aux = s.top();
                    s.pop();
                    if (minv.first > aux.first)
                    {
                        if (minv.second == 0)
                            minv.second++;
                        s.push(minv);
                        s.push(aux);
                    }
                    else if (minv.first == aux.first)
                    {
                        aux.second++;
                        s.push(aux);
                        if (minv.second > 0)
                            s.emplace(minv.first-1, minv.second);
                    }
                    else if (minv.first < aux.first)
                    {
                        if (minv.second == 0)
                        {
                            minv.second++;
                            s.push(aux);
                            s.push(minv);
                        }
                        else
                        {
                            s.push(aux);
                            s.emplace(minv.first, 1);
                            s.emplace(minv.first - 1, minv.second);
                        }
                    }
                }

            }
            else
            {
                if (minv.first == 1)
                {
                    minv.second++;
                    s.pop();
                }
                else
                {
                    minv.first = 1;
                    minv.second = 1;
                }
                s.push(minv);       
            }
        }
    }
    while(!s.empty())
    {
        aux = s.top();
        s.pop();
    }
    cout << aux.first;
    return 0;
}