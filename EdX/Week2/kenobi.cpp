#include <iostream>
#include <string>
#include <deque>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *infile = fopen("kenobi.in", "r");
    FILE *outfile = fopen("kenobi.out", "w");
    int n;
    int ls;
    int size;
    char op[12];
    std::deque<int> *dl, *dr;
    dl = new std::deque<int>();
    dr = new std::deque<int>();
    size = 0;
    fscanf(infile, "%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        fgets(op, 5, infile);
        if (strstr(op, "add") != NULL)
        {
            fscanf(infile, "%d\n", &ls);
            dr->push_back(ls);
            size++;
            if(size % 2 == 0)
            {
                dl->push_back(dr->front());
                dr->pop_front();
            }

        }
        else if(strstr(op, "take") != NULL)
        {
            fscanf(infile, "%*c");
            dr->pop_back();
            if (size % 2 == 0)
            {
                dr->push_front(dl->back());
                dl->pop_back();
            }
            size--;
        }
        else if(strstr(op, "mum!") != NULL)
        {
            fscanf(infile, "%*c");
            std::deque<int> *aux;
            aux = dl;
            dl = dr;
            dr = aux;
            if (size % 2 != 0)
            {
                dr->push_front(dl->back());
                dl->pop_back();
            }
        }
    }
    fprintf(outfile, "%d\n", size);
    while(!dl->empty())
    {
        fprintf(outfile, "%d ", dl->front());
        dl->pop_front();
    }
    while(!dr->empty())
    {
        fprintf(outfile, "%d ", dr->front());
        dr->pop_front();
    }
    return 0;

}