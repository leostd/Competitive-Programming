#include<bits/stdc++.h>
using namespace std;

int h1, h2, m1, m2, k=0;

void incH(){
    if (h1 == 2 && h2 == 3)
        h1 = h2 = 0;
    else if (h2 == 9) {
        h1++; h2 = 0;
    }
    else
        h2++;
}

void incM() {
    if (m1 == 5 && m2 == 9){
        m1 = m2 = 0;
        incH();
    }
    else if (m2 == 9 && m1 < 5){
        m1++;
        m2 = 0;
    }
    else
        m2++;
}
int main() {
    scanf("%1d%1d:%1d%1d", &h1, &h2, &m1, &m2);
    while(1) {
        if (h1 == m2 && h2 == m1) break;
        k++;
        incM();
    }
    printf("%d\n", k);
    return 0;
}