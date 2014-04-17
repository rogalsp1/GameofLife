#include "generator.h"
#include <stdio.h>
#include <stdlib.h>

int life(life_t t,char *name,int n)
{
    life_t p;
    p=alloc_grid(p,t->cols,t->rows);
    int x,y,i;
    char plik[10];
    for(i=0;i<n;i++)
    {
        sprintf(plik,"%s_%d.png",name,i+1);

        if((createPNG(t,plik))==1)
            {
                printf("Nie udało sie stworzyc pliku\n");
                return 1;
            }
        for(y=0; y<t->rows; y++)
          {
            for(x=0; x<t->cols;x++)
                if(rules(t,x,y)==1)
                    p->grid[y][x]=1;
                   else p->grid[y][x]=0;
          }
        for(y=0;y<t->rows;y++)
            for(x=0;x<t->cols;x++)
                t->grid[y][x]=p->grid[y][x];


    }
    free(p);
    return 0;

}
