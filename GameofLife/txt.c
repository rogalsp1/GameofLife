#include "txt.h"

int read_ref (FILE *in, int *x,int *y)
{
    fscanf(in,"%d %d",x,y);
    if(*x>0 && *y>0)
    {
        printf("Wprowadzono rozmiar planszy : %d x %d \n", *x,*y);
        return 0;
    }
    else
    {
        printf("Wprowadzono bledny rozmiar planszy.");
        return 1;
    }
}

int read_grid (FILE *in, life_t t)
{
    int x;
    int y;
    while(!feof(in))
    {
        if((fscanf(in,"%d %d",&x,&y)==2) && (x<t->cols && y<t->rows))
        {
            t->grid[y][x]= 1;
            printf("Wczytano punkt (%d,%d).\n",x,y);
    }
        else if(x>=t->cols && y>=t->rows)
                printf("Pominięto punkt(%d,%d).\n",x,y);
    }
    return 0;
}

void save_grid (FILE *out, life_t t)
{
    int i,j;
 fprintf(out,"%d %d\n", t->cols,t->rows);
    for(i=0;i<t->rows;i++)
        for(j=0;j<t->cols;j++)
	{

            if(t->grid[i][j]==1)
                fprintf(out,"%d %d\n",j,i);
	}
    printf("Zapisano dane do pliku.\n");
}
