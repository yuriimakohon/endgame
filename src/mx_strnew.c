#include "minilibmx.h"

char *mx_strnew(const int size) {
    char *new_str;

    if (size < 0)
        return NULL;

    new_str = malloc(size + 1);
    for (int i = 0; i <= size; i++)
        new_str[i] = 0;
    return new_str;
}
