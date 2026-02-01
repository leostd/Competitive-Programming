 #include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

typedef long long int ui;
typedef std::vector <ui> vui;

vui cl;
ui n;
ui k;

ui dry(ui a, ui b)
{
    if (a < b)
        return 0;
    else
        return a - b;
}

bool dryall(ui t)
{
    vui aux = cl;
    vui radiator_clothes;
    ui acum = 0;
    for (int i = 0; i < n; i++)
    {
        aux[i] = dry(aux[i], t);
        if (aux[i] > 0)
            radiator_clothes.push_back(aux[i]);
    }
    if (radiator_clothes.empty())
        return true;
    if (k > 1)
    {
        for (int i = 0; i < radiator_clothes.size(); i++)
        {
            acum += ceil((double)radiator_clothes[i]/(double)(k-1));
            if (acum > t)
                return false;
        }
        return true;
    }
    else
        return false;
}

ui min_bin_search(ui min, ui max)
{
    while(min < max)
    {
        ui mid = min + (max - min)/2;
        if (dryall(mid))
            max = mid;
        else
            min = mid + 1;
    }
    return min;
}

int main(int argc, char** argv)
{
    FILE *infile = fopen("drying.in", "r");
    FILE *outfile = fopen("drying.out", "w");
    ui min=1;
    ui max = 0;
    fscanf(infile, "%lli", &n);
    cl = vui(n, 0);
    for (int i = 0; i < n; i++)
    {
        fscanf(infile, "%lli", &cl[i]);
        if (cl[i] > max)
            max = cl[i];
        if (i == 1)
            min = cl[0];
        if (cl[i] < min)
            min = cl[i];
    }
    fscanf(infile, "%lli", &k);
    ui  tm = min_bin_search(1, max);
    fprintf(outfile, "%lli\n", tm);
    return 0;
}