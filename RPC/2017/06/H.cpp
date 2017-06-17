#include <bits/stdc++.h>
using namespace std;

long long inv;

inline void fastInt(int &a) {
    char c;
    int s = 1;
    a = 0;
    while(1){
        c = getchar_unlocked();
        if (c=='-') s = -1;
        if (c >= '0' && c <='9') break;
    }
    while(1){
        a = a*10 + c-'0';
        c = getchar_unlocked();
        if (c<'0' || c>'9') break;
    }
    a *= s;
}

void printArray(int *ar, int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", ar[i]);
    printf("\n");
}

void merge(int *arr, int l, int r) {
    int i, j, k;
    int m = (r - l)/2 + l;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = j = 0;
    k = l;
    while(i < n1 && j < n2) {
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
            inv += n1-i;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        k++; i++;        
    } 
    while(j < n2) {
        arr[k] = R[j];
        k++; j++;
    }
}

void mergesort(int *arr, int l, int r) {
    if (l < r){
        int m = l + (r-l)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, r);
    }
}


int main() {
    int n,a;
    int arr[1000002];
    while(true) {
        fastInt(n);
        if (!n) break;
        for(int i = 0; i < n; ++i)
            fastInt(arr[i]);
        mergesort(arr,0, n-1);
        //printArray(arr, n);
        printf("%lli\n", inv);
        inv = 0;
    }
    return 0;
}