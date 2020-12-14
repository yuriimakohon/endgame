#include "level.h"

static int get_lvl_count();

t_lvl *mx_create_lvl(char *filename) {
    t_lvl *lvl = (t_lvl*)malloc(sizeof(t_lvl));

    mx_fill_map(open(filename, O_RDONLY), lvl);
    mx_fill_positions(filename, &lvl);
    return lvl;
}

t_lvl **mx_create_lvls() {
    t_lvl **lvls = malloc(sizeof(t_lvl) * (get_lvl_count() + 1));
    DIR * dirp = NULL;
    struct dirent * entry;
    int i = 0;

    dirp = opendir(MX_LVL_DIR);
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_name[0] != '.') {
            char lvl_path[80];
            sprintf(lvl_path, "%s/%s", MX_LVL_DIR, entry->d_name);
            lvls[i] = mx_create_lvl(lvl_path);
            i++;
        }
    }
    lvls[i] = NULL;
    closedir(dirp);
    return lvls;
}

static int get_lvl_count() {
    int count = 0;
    DIR * dirp;
    struct dirent * entry;

    dirp = opendir(MX_LVL_DIR);
    while ((entry = readdir(dirp)) != NULL)
        if (entry->d_type == DT_REG)
            count++;
    closedir(dirp);
    return count;
}
