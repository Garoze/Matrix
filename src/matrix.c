#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

#define BUFFER_SIZE 300

Matrix* Matrix_init()
{
    Matrix* matrix = calloc(1, sizeof(Matrix));

    matrix->rows = 0;
    matrix->cols = 0;
    matrix->data = NULL;

    return matrix;
}

void Matrix_alloc(Matrix* matrix, int rows, int cols)
{
    matrix->rows = rows;
    matrix->cols = cols;

    if (matrix->data == NULL)
    {

        matrix->data = calloc(rows, sizeof(int*));

        for (size_t i = 0; i < rows; ++i)
        {
            matrix->data[i] = calloc(cols, sizeof(int*));
        }
    }
}

void Matrix_populate(Matrix* matrix, FILE* file, char sep)
{
    int rows = 0;
    int cols = 0;

    fseek(file, 0, SEEK_SET);

    char* token;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        char* token = strtok(buffer, &sep);
        int cols = 0;
        while (token != NULL)
        {
            if (matrix->data == NULL)
            {
                printf("You must alloc a matrix first.");
                exit(1);
            }
            matrix->data[rows][cols] = atoi(token);
            token = strtok(NULL, &sep);
            cols++;
        }
        rows++;
    }
}

void Matrix_parse_size(Matrix* matrix, FILE* file, char sep)
{
    int rows = 0;
    int cols = 0;

    char* token;
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        rows++;

        if (cols == 0)
        {
            token = strtok(buffer, &sep);
            while (token != NULL)
            {
                cols++;
                token = strtok(NULL, &sep);
            }
        }
    }

    Matrix_alloc(matrix, rows, cols);
}

void Matrix_show(Matrix* matrix)
{
    for (int i = 0; i < matrix->rows; ++i)
    {
        for (int j = 0; j < matrix->cols; ++j)
        {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void Matrix_free(Matrix* matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        free(matrix->data[i]);
    }
}
