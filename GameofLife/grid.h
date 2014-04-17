#ifndef GRID_H
#define GRID_H
typedef struct {
    int **grid;
    int rows;
    int cols;

} *life_t;

life_t alloc_grid(life_t t,int x, int y);

#endif // GRID_H
