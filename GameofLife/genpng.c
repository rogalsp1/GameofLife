#include "genpng.h"



int createPNG(life_t t, char *file)
{


    const char* filename = file;
    unsigned width = t->cols*4, height = t->rows*4;
    unsigned char* image = malloc(width * height * 4);
    unsigned x, y;
    int i,j;
//==================== tworzenie powiekszonej planszy ===============================================
    int **tab=(int**) malloc((height) *(sizeof(int*)));
    for (i=0;i<=height;i++)
        tab[i] = (int*)malloc((width) * sizeof(int));
    for(j=0;j<height;j++)
        for(i=0;i<width;i++)
            tab[j][i]=0;


    for(j=0;j<t->rows;j++)
        for(i=0;i<t->cols;i++)
            if(t->grid[j][i]==1)
                tab[4*j][4*i]=1;





    for(j=0;j<height;j+=4)
        for(i=0;i<width;i+=4)
            if(tab[j][i]==1)
        {
            for(y=j;y<(j+4);y++)
                for(x=i;x<(i+4);x++)
                    tab[y][x]=1;
        }



    for(y = 0; y < height; y++)
        for(x = 0; x < width; x++)
            if(tab[y][x]==1){

                image[4*width * y + 4* x + 0] = 0 ;
                image[4*width * y + 4*x + 1] = 0;
                image[4*width * y +  4*x + 2] = 0;
                image[4* width * y +  4*x + 3] = 255;

            }
            else{
                image[4 * width * y + 4 * x + 0] = 255;
                image[4 * width * y + 4 * x + 1] = 255;
                image[4 * width * y + 4 * x + 2] = 255;
                image[4 * width * y + 4 * x + 3] = 255;
            }

//=====================tworzenie pliku png========================================================================
    unsigned error = lodepng_encode32_file(filename, image, width, height);

    if(error)
    {
        printf("error %u: %s\n", error, lodepng_error_text(error));
        free(image);
        return 1;
    }
    printf("Stworzono plik %s.\n",file);

    free(image);
    return 0;
}



