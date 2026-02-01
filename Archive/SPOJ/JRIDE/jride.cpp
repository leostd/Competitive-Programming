#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int arr[100006];
int first, last, maxfirst, maxlast, maxelems, elems;
lli sum, maxsum, prevsum;

int main() {
	// your code goes here
	//freopen("jride.txt", "r", stdin);
	int t, route = 1;
	scanf("%d", &t);
	while(t--){
		int s;
		scanf("%d", &s);
		for (int i = 1; i < s; i++)
			scanf("%d", &arr[i]);
		maxsum = prevsum = -1;
		sum = 0;
		first = -1;
		for(int i = 1; i < s; i++){
			if (first == -1)
				first = i;
			sum += arr[i];
			last = i;
			elems++;
            if (sum < 0){
                sum = elems = 0;
                first = -1;
            }
            else{
                if (sum > maxsum || (sum == maxsum && last > maxlast && elems > maxelems)){
                    maxsum = sum;
                    maxlast = last;
                    maxfirst = first;
                    maxelems = elems;
                }
            }
            prevsum = sum;
		}
		if (maxsum >= 0)
            printf("The nicest part of route %d is between stops %d and %d\n", route++, maxfirst, maxlast+1);
        else
            printf("Route %d has no nice parts\n", route++);
	}
	return 0;
}
