#include "level.h"

static void get_map_size_from_fd(int fd, char ch, int *width, int *height) {
    char *map_size = mx_strnew(2);

    for (int i = 0; read(fd, &ch, 1) && ch != '\n'; i++)
        map_size[i] = ch;
    *width = atoi(map_size);
    mx_strdel(&map_size);
    map_size = mx_strnew(2);
    for (int i = 0; read(fd, &ch, 1) && ch != '\n'; i++)
        map_size[i] = ch;
    *height = atoi(map_size);
    mx_strdel(&map_size);
}

static char **read_map_from_fd(int fd, char ch) {
    int i;
    int j;
    int width;
    int height;
    char **map = NULL;

    get_map_size_from_fd(fd, ch, &width, &height);
    map = malloc(sizeof(char*) * (height + 1));
    for (i = 0; i < height; i++) {
        map[i] = mx_strnew(width);
        for (j = 0; read(fd, &ch, 1) && ch !='\n'; j++)
            map[i][j] = ch;
    }
    map[i] = NULL;
    return map;
}

void mx_fill_map(int fd, t_lvl *lvl) {
    int i;
    char ch;

    if (fd != -1) {
        lvl->name = mx_strnew(MX_MAX_LVL_NAME);
        for (i = 0; i < MX_MAX_LVL_NAME && read(fd, &ch, 1) && ch != '\n'; i++)
            lvl->name[i] = ch;
        lvl->map = read_map_from_fd(fd, ch);
        close(fd);
    }
    else {
        lvl->name = NULL;
        lvl->map = NULL;
    }
}
