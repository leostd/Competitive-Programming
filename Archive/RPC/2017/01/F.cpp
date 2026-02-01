#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef pair<int, string> ir;
typedef vector<ir> vir;

int arr[105];
int n, m;

int main(){
    fill(arr, arr+105, -1);
    arr[1] = 1;
    string str;
    int id;
    scanf("%d %d", &n, &m);
    arr[m] = 0;
    for (int i = 0; i < n; i++){
        cin >> id >> str;
        if (str[0] == 'S')
            arr[id] = 1;
        else
            arr[id] = 0;
    }
    int ans1 = 1, ans2 = m;
    for (int i = m; i >= 1; i--)
    {   
        if (arr[i] != 1)
            ans2 = i;
        else
            break;
    }
    for (int i = 1; i <= m; i++)
    {
        if (arr[i] != 0)
            ans1 = i;
        else
            break;
    }
    printf("%d %d\n", ans2, ans1);
    return 0;
}
