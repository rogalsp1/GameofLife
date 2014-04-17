#include "grid.h"

life_t  alloc_grid(life_t t,int x, int y)
{
    int i;
    t = malloc(sizeof (life_t));
    t->cols=x;
    t->rows=y;
    t->grid = (int**) malloc((y) *(sizeof(int*)));
    for (i=0;i<=t->rows;i++)
    {
        t->grid[i] = (int*)malloc((x) * sizeof(int));

    }

    return t;



}

