#include "libmx.h"

static char *mx_full(void) {
	char		*res;

	if (!(res = (char *)malloc(1)))
		return (0);
	res[0] = '\0';
	return (res);
}

char *mx_strtrim(const char *str) {
	size_t		i;
	size_t		j;
	char		*res;
	char		*pstr;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = mx_strlen(str) - 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (i >= j)
		return (mx_full());
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
		j--;
	if (!(res = (char *)malloc(j - i + 2)))
		return (0);
	res[j - i + 1] = '\0';
	pstr = res;
	while (i < j + 1) {
		*res++ = str[i];
		i++;
	}
	return (pstr);
}
