#ifndef TXT_H
#define TXT_H
#include "grid.h"
#include <stdio.h>
int read_ref (FILE *in, int *x,int *y);

int read_grid (FILE *in, life_t t);

void save_grid (FILE *out, life_t t);

#endif // TXT_H
