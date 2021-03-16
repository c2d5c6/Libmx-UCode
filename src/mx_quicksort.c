#include "libmx.h"

static void mx_swap_str(char **s1, char **s2)
{
	if (s1 == s2)
		return;
	char *tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

static bool strcmp373(const char *str1, const char *str2) {
	int sum1 = 0;
	int sum2 = 0;

	for (; *str1; str1++, str2++) {
		sum1 += *str1;
		sum2 += *str2;
	}
	return sum1 > sum2;
}

static int count_move(char **arr, int *left, int *right, int *pos)
{
	int res = 0;

	if (*pos == *right)
		--(*right);
	if (*pos == *left)
		++(*left);
	else {
		++res;
		mx_swap_str(&arr[*pos], &arr[*left]);
	}
	if (*left < *right)
		res += mx_quicksort(arr, *left, *right);
	return res;
}

int mx_quicksort(char **arr, int left, int right)
{
	if (!arr)
		return -1;

	int len = mx_strlen(arr[left]);
	int pos = left;

	for (int beg = left, end = right; beg < end; --end)
		if (len > mx_strlen(arr[end]) || (len == mx_strlen(arr[end])
		&& strcmp373(arr[left], arr[end]))) {
			pos = end;
			for (++beg; beg < end; ++beg)
				if (len < mx_strlen(arr[beg]) || (len == mx_strlen(arr[beg])
				&& strcmp373(arr[beg], arr[left]))) {
					pos = beg;
					break;
				}
		}
	return count_move(arr, &left, &right, &pos);
}
