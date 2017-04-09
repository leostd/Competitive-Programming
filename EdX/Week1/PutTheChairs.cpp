#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("chairs.in");
    std::ofstream cout("chairs.out");
#else
    #include <iostream>
    using std::cin;
    using std::cout;
#endif
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>

#define db false 

typedef long double ld;

int main ()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (db)
        cout << a << " " << b << " " << c << std::endl;
    ld r;
    r = (ld)(a + b + c) / 2.0L;
    r /= 3.0L;
    cout.precision(17);
    cout << r << std::endl;
    return 0;
}