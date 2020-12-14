#include "level.h"

void mx_print_lvl(t_lvl *lvl) {     // TODO: Delete this file
    printf("%s\n", lvl->name);
    for (int i = 0; lvl->map[i]; i++) {
        printf("%s\n", lvl->map[i]);
    }
    printf("\n\n");
}
