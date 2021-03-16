#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,
        int c, size_t n) {
    char *m_dst = (char *)dst;
    char *m_src = (char *)src;
    size_t i;

    for (i = 0; i < n; i++) {
        m_dst[i] = m_src[i];
        if (m_src[i] == c)
            break;
    }
    if (i == n)
        return NULL;
    i++;
    return m_src + i;
}

