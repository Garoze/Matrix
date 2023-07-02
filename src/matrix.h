#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdio.h>

typedef struct
{
    int rows;
    int cols;
    int** data;
} Matrix;

Matrix* Matrix_init();

void Matrix_alloc(Matrix* matrix, int rows, int cols);
void Matrix_populate(Matrix* matrix, FILE* file, char sep);
void Matrix_parse_size(Matrix* matrix, FILE* file, char sep);

void Matrix_show(Matrix* matrix);
void Matrix_free(Matrix* matrix);

#endif
