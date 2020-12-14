#pragma once

#include <stdlib.h>

char *mx_strnew(const int size);
void mx_strdel(char **s);
void mx_del_strarr(char ***arr);
