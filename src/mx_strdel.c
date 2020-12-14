#include "minilibmx.h"

void mx_strdel(char **s) {
    if (*s) {
        free(*s);
        *s = NULL;
    }
}