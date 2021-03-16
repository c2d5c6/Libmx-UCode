#include "libmx.h"

char *mx_strdup(const char *str) {
    char *duplicate;
    int res = 0;
    
    res = (mx_strlen(str));
    duplicate = (mx_strnew(res));
    mx_strcpy(duplicate, str);
    return duplicate;
}
