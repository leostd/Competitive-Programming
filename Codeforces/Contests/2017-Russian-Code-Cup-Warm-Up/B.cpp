#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef pair <int, int> ii;
int n, k;

vi rangers[5];
int maximal, minimal;
set<ii> seats;


bool checkRanger(int r, int s, int ranger)
{
    if (ranger == 1)
    {
        if (r == minimal && (!seats.count(ii(r, 1)) || !seats.count(ii(r, 2))))
        {
            if (!seats.count(ii(r, 1)) && !seats.count(ii(r, 2)) && s == 2)
                return false;
            return true;
        }
        return false;
    }
    else if (ranger == 2)
    {
        if (r == minimal && (!seats.count(ii(r, 1)) || !seats.count(ii(r, 2))))
        {
            if (!seats.count(ii(r, 1)) && !seats.count(ii(r, 2)) && s == 1)
                return false;
            return true;
        }
        return false;
    }
    else if (ranger == 3)
    {
        if (r == maximal && (!seats.count(ii(r, 1)) || !seats.count(ii(r, 2))))
        {
            if (!seats.count(ii(r,1)) && !seats.count(ii(r,2)) && s == 2)
                return false;
            return true;
        }
        return false;
    }
    else if (ranger == 4)
    {
        if (r == maximal && (!seats.count(ii(r, 1)) || !seats.count(ii(r, 2))))
        {
            if (!seats.count(ii(r, 1)) && !seats.count(ii(r, 2)) && s == 1)
                return false;
            return true;
        }
        return false;
    }
}


int main()
{
    scanf("%d %d", &n, &k);
    int row, s;
    minimal = 1; maximal = n;
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &row, &s);
        rangers[4].push_back(i+1); // pink likes any seat
        if (checkRanger(row, s, 1))// red
            rangers[0].push_back(i+1);
        if (checkRanger(row, s, 2)) // blue
            rangers[1].push_back(i+1);
        if (checkRanger(row, s, 3)) // black
            rangers[2].push_back(i+1);
        if (checkRanger(row, s, 4)) // yellow
            rangers[3].push_back(i+1);
        seats.insert(ii(row, s));
        while(seats.count(ii(minimal, 1)) && seats.count(ii(minimal, 2)))
            minimal++;
        while(seats.count(ii(maximal, 1)) && seats.count(ii(maximal, 2)))
            maximal--;
    }
    for (int i = 0; i < 5; i++)
    {
        vi aux = rangers[i];
        cout << aux.size() << " ";
        for (int j = 0; j < aux.size(); j++)
        {
            cout << aux[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}