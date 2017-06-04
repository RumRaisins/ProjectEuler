#include <stdio.h>
#include <inttypes.h>
#include<iostream>

typedef int64_t(*calcFunc)(int64_t);

int64_t Hexagonal(int64_t n) {
	return n * (2 * n - 1);
}

int64_t Pentagonal(int64_t n) {
	return n * (3 * n - 1) / 2;
}

int64_t Triangle(int64_t n) {
	return n * (n + 1) / 2;
}

bool Valid(int64_t n, calcFunc f) {
	int64_t mind = 1, maxd = n, mid;
	int64_t t;
	mid = (mind + maxd) >> 1;
	while (mind <= maxd) {
		t = f(mid);
		if (t < n) {
			mind = mid + 1;
		}
		else if (t > n) {
			maxd = mid - 1;
		}
		else if (t == n) {
			return true;
		}
		mid = (mind + maxd) >> 1;
	}
	return false;
}

int32_t main() {
	int64_t n = 1, t, cnt = 2;
	while (cnt) {
		++n;
		t = Hexagonal(n);
		if (Valid(t, Pentagonal) && Valid(t, Triangle)) {
			--cnt;
		}
	}
	std::cout << t;
	system("pause");
	return 0;
}