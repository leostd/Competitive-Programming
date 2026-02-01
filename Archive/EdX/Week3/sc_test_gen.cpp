#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv)
{
    FILE *outfile = fopen("scarecrow.in", "w");
    int n, k;
    bool flag1 = false, flag2 = true; 
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    fprintf(outfile, "%d %d\n", n, k);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            if (flag2)
            {
                fprintf(outfile, "%lli ", 2);
                flag2 = false;
            }
            else
            {
                fprintf(outfile, "%lli ", 1);
                flag2 = true;
            }
        }
        else
        {
            if (flag1)
            {
                fprintf(outfile, "%lli ", 1);
                flag1 = false;
            }
            else
            {
                fprintf(outfile, "%lli ", 2);
                flag1 = true;
            }
        }
    }
    return 0;
}