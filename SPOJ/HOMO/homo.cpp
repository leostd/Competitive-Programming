#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

typedef long long int lli;

/*
    elements: Set of elements.
    repeated: Set of repeated elements.
    repetitions: Elements' repetitions. The key is the element,
                 the value is the number of repetitions.   
*/
set<lli> elements, repeated;
map<lli, int> repetitions;
bool homo, hetero;

int main()
{
    string operation;
    int n;
    lli k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> operation;
        scanf("%lli", &k);
        if (operation == "insert")
        {
            elements.insert(k);  // insert k in elements
            repetitions[k]++;   // increase by one the repetitions of that number
            if (repetitions[k] > 1) // if true, then k is repeated.
                repeated.insert(k);
        }
        else    // delete
        {
            if (elements.count(k)) // the element exists
            {
                repetitions[k]--; // decrease the repetitions
                if (repetitions[k] == 1) // then k is not a repeated element
                    repeated.erase(k);
                else if (repetitions[k] == 0) // then we need to delete the element
                {
                    repeated.erase(k);
                    elements.erase(k);
                }
            }
        }
        if (elements.size() == 1) // There is only one element
        {
            if (repetitions[*elements.begin()] > 1)
                homo = true;
            else
                homo = false;
            hetero = false;
        }
        else if (elements.size() > 1) // There is more than one element
        {
            hetero = true;
            if (repeated.size() > 0)
                homo = true;
            else
                homo = false;
        }
        else
            hetero = homo = false;
        if (hetero && homo)
            printf("both\n");
        else if (hetero && !homo)
            printf("hetero\n");
        else if (!hetero && homo)
            printf("homo\n");
        else
            printf("neither\n");
    }
    return 0;
}