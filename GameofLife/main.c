#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grid.h"
#include "txt.h"
#include "generator.h"


int main(int argc, char **argv)
{
    int x,y;
    if(argc==1)
    {
        printf("GameofLife - przykladowe wywolanie:\n");
        printf("./GameofLife <plik z danymi> <plik do zapisu danych> <ilosc generacji> <nazwa plikow .png>\n");
        return 1;
    }
    if(argc<5)
    {
        printf("Podano za mało argumentów.\n");
        printf("./GameofLife <plik z danymi> <plik do zapisu danych> <ilosc generacji> <nazwa plikow .png>\n");
        return 1;

    }

    FILE *in = fopen(argv[1],"r");
    if(in==NULL) {
        fprintf (stderr, "Blad przy otwieraniu pliku: %s", argv[1]); return 1;
        }

    FILE *out = fopen(argv[2],"w");
    if(out==NULL) {
        fprintf (stderr, "Blad przy otwieraniu pliku: %s", argv[2]); return 1;
        }
    if(read_ref(in,&x,&y)==1)
        return 1;
    life_t t;
    t = alloc_grid(t,x,y);
    if(!t)
    {
        printf("Brak miejsca w pamieci.\n");
        return 1;
    }
    if(read_grid(in,t)==1)
        return 1;
    if(life(t,argv[4],atoi(argv[3]))==1)
    {
        printf("Koniec programu");
        return 1;
    }
    save_grid(out,t);


    fclose(in);
    fclose(out);
    free(t);

    return 0;
}
