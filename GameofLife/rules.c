#include "rules.h"

int rules (life_t t, int x, int y)
{
    int licznik=0;
// dla wierzchołka (0,0)
//===========================================================================================================
    if(x==0 && y==0)
    {
            if(t->grid[1][0]==1) licznik++;
            if(t->grid[1][1]==1) licznik++;
            if(t->grid[0][1]==1) licznik++;
            switch(t->grid[y][x])
            {
                case 0: if(licznik==3)
                    return 1;
                    else return 0;
                    break;
                case 1: if(licznik>1)
                    return 1;
                    else return 0;
                    break;
            }


    }
// dla wierzchołka (0,YMAX)
//===========================================================================================================
    if(x==0 && y==t->rows-1)
    {
            if(t->grid[y-1][0]==1) licznik++;
            if(t->grid[y][1]==1) licznik++;
            if(t->grid[y-1][1]==1) licznik++;
            switch(t->grid[y][x])
            {
                case 0: if(licznik==3)
                    return 1;
                    else return 0;
                    break;
                case 1: if(licznik>1)
                    return 1;
                    else return 0;
                    break;
            }
    }
// dla wierzchołka (XMAX,YMAX)
//===========================================================================================================
    if(x==t->cols-1 && y==t->rows-1)
    {
            if(t->grid[y][x-1]==1) licznik++;
            if(t->grid[y-1][x-1]==10) licznik++;
            if(t->grid[y-1][x]==1) licznik++;
            switch(t->grid[y][x])
            {
                case 0: if(licznik==3)
                    return 1;
                    else return 0;
                    break;
                case 1: if(licznik>1)
                    return 1;
                    else return 0;
                    break;
            }
    }

// dla wierzchołka (XMAX,0)
//===========================================================================================================
    if(x==t->cols-1 && y==0)
    {

            if(t->grid[0][x-1]==1) licznik++;
            if(t->grid[1][x-1]==1) licznik++;
            if(t->grid[1][x]==1) licznik++;
            switch(t->grid[y][x])
            {
                case 0: if(licznik==3)
                    return 1;
                    else return 0;
                    break;
                case 1: if(licznik>1)
                    return 1;
                    else return 0;
                    break;
            }
    }
// dla punktów x=0
//===========================================================================================================

    if(x==0)
    {
            if(t->grid[y-1][x]==1) licznik++;
            if(t->grid[y-1][x+1]==1) licznik++;
            if(t->grid[y][x+1]==1) licznik++;
            if(t->grid[y+1][x+1]==1) licznik++;
            if(t->grid[y+1][x]==1) licznik++;
            switch(t->grid[y][x])
            {
                case 0: if(licznik==3)
                    return 1;
                    else return 0;
                    break;
                case 1: if(licznik>1 && licznik<4)
                    return 1;
                    else return 0;
                    break;
            }
    }

 // dla punktów x=XMAX
//===========================================================================================================

    if(x==t->cols-1)
    {
            if(t->grid[y+1][x]==1) licznik++;
            if(t->grid[y+1][x-1]==1) licznik++;
            if(t->grid[y][x-1]==1) licznik++;
            if(t->grid[y-1][x-1]==1) licznik++;
            if(t->grid[y-1][x]==1) licznik++;
            switch(t->grid[y][x])
            {
                case 0: if(licznik==3)
                    return 1;
                    else return 0;
                    break;
                case 1: if(licznik>1 && licznik<4)
                    return 1;
                    else return 0;
                    break;
            }
    }
// dla punktów y=0
//===========================================================================================================

    if(y==0)
    {
            if(t->grid[y][x-1]==1) licznik++;
            if(t->grid[y+1][x-1]==1) licznik++;
            if(t->grid[y+1][x]==1) licznik++;
            if(t->grid[y+1][x+1]==1) licznik++;
            if(t->grid[y][x+1]==1) licznik++;
            switch(t->grid[y][x])
            {
                case 0: if(licznik==3)
                    return 1;
                    else return 0;
                    break;
                case 1: if(licznik>1 && licznik<4)
                    return 1;
                    else return 0;
                    break;
            }
    }
 // dla punktów y=YMAX
//===========================================================================================================

    if(y==t->rows-1)
    {
            if(t->grid[y][x-1]==1) licznik++;
            if(t->grid[y-1][x-1]==1) licznik++;
            if(t->grid[y-1][x]==1) licznik++;
            if(t->grid[y-1][x+1]==1) licznik++;
            if(t->grid[y][x+1]==1) licznik++;
            switch(t->grid[y][x])
            {
                case 0: if(licznik==3)
                    return 1;
                    else return 0;
                    break;
                case 1: if(licznik>1 && licznik<4)
                    return 1;
                    else return 0;
                    break;
            }
    }
 // dla reszty punktów
//===========================================================================================================

        if(t->grid[y+1][x-1]==1) licznik++;
        if(t->grid[y+1][x]==1) licznik++;
        if(t->grid[y+1][x+1]==1) licznik++;
        if(t->grid[y][x+1]==1) licznik++;
        if(t->grid[y][x-1]==1) licznik++;
        if(t->grid[y-1][x-1]==1) licznik++;
        if(t->grid[y-1][x]==1) licznik++;
        if(t->grid[y-1][x+1]==1) licznik++;
        switch(t->grid[y][x])
            {
                case 0: if(licznik==3)
                    return 1;
                    else return 0;
                    break;
                case 1: if(licznik>1 && licznik<4)
                    return 1;
                    else return 0;
                    break;
            }

return 0;
}
