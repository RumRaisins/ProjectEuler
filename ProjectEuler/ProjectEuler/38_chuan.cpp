#include <stdio.h>
#include <math.h>
#include <inttypes.h>

bool IsPandigital(int32_t n, int32_t *result) {
	int32_t num = 0, a[10] = { 0 };
	int32_t ret = 0, i = 1, x;
	while (num < 9) {
		x = n * i;
		while (x) {
			if (x % 10 == 0) return false;
			if (a[x % 10]) return false;
			a[x % 10] = (++num);
			x /= 10;
		}
		ret *= (int32_t)pow(10, floor(log10(n * i)) + 1);
		ret += n * i;
		++i;
	}
	(*result) = ret;
	return true;
}

int32_t main() {
	bool flag;
	int32_t num, max_num = 0;
	for (int32_t i = 1; i <= 10000; i++) {
		if (!IsPandigital(i, &num)) continue;
		if (num > max_num) max_num = num;
	}
	printf("%d\n", max_num);
	return 0;
}