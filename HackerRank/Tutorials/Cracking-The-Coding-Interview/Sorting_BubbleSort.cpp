#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nswap = 0;

void bubbleS(vector<int> &ns)
{
    int sswap;
    for (int i = 0; i < ns.size(); i++)
    {
        sswap = 0;
        for (int j = 0; j < (int)ns.size()-1; j++)
        {
            if (ns[j] > ns[j+1])
            {
                swap(ns[j], ns[j+1]);
                sswap++;
            }
        }
        
        nswap += sswap;
        if (sswap == 0)
            return;
    }
}

int main() {
   int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    bubbleS(a);
    cout << "Array is sorted in " << nswap << " swaps.\n";
    cout << "First Element: " << a[0] << "\n";
    cout << "Last Element: " << a[n-1] << "\n";
  return 0;
}
