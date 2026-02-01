#include <iostream>
#include <map>
#include <string.h>
using namespace std;

bool mark[100005];

int main() {
  int t, r, p;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    printf("0.");
    r = 1;
    memset(mark, 0, sizeof(mark));
    while(true){
      p = (10*r)/n;
      r = (10*r)%n;
      if (mark[r]) break;
      mark[r] = true;
      printf("%d", p);
    }
    printf("\n");
  }
  return 0;
}