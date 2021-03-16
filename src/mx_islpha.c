#include "libmx.h"

int ft_isalpha(int c) {
	if ((c <= 'Z' && c >= 'A') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
