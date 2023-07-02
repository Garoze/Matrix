#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

#define CLEAR_SCREEN printf("\e[1;1H\e[2J");

#define WAIT                                                                   \
    getchar();                                                                 \
    getchar();

#define BUFFER_SIZE 300

FILE* load_file(char* filename, char* sep)
{
    printf("Digite o separador: ");
    scanf(" %c", sep);

    FILE* file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Cannot open the file: %s\n", filename);
        exit(1);
    }

    return file;
}

int main(void)
{
    int op;
    bool menu = true;

    FILE* file;
    Matrix* matrix = Matrix_init();

    char sep;
    char buffer[BUFFER_SIZE];

    while (menu)
    {
        CLEAR_SCREEN
        printf("-- MENU --\n\n1 - Carregar arquivos\n2 - Mostrar matrix\n0 - "
               "Sair\n");
        printf("> ");
        scanf("%d", &op);
        menu = false;

        switch (op)
        {
            case 1:
            {
                printf("Digite o nome do arquivo: ");
                fgetc(stdin);
                fgets(buffer, BUFFER_SIZE, stdin);
                buffer[strlen(buffer) - 1] = '\0';

                file = load_file(buffer, &sep);
                Matrix_parse_size(matrix, file, sep);
                Matrix_populate(matrix, file, sep);
                menu = true;
            }
            break;

            case 2:
            {
                Matrix_show(matrix);
                WAIT menu = true;
            }
            break;

            case 0:
                menu = false;
                break;

            default:
                menu = true;
                break;
        }
    }

    Matrix_free(matrix);

    return 0;
}
