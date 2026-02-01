#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("queue.in");
    std::ofstream cout("queue.out");
#else
    #include <iostream>
    using std::cin;
    using std::cout;
#endif

#include <queue>

typedef long long int lli;

int main()
{
    int n;
    std::queue<lli> q;
    lli x;
    char op;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        if (op == '+')
        {
            cin >> x;
            q.push(x);
        }
        else
        {
            lli f = q.front();
            q.pop();
            cout << f << "\n";
        }
        cin.ignore();
    }
    return 0;
}