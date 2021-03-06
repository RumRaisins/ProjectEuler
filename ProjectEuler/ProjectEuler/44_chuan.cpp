#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <inttypes.h>
#include<iostream>

int64_t Pentagonal(int64_t n) {
	return n * (3 * n - 1) / 2;
}
bool isPentagonal(int64_t n) {
	int64_t mind = 1, maxd = n, mid;
	int64_t t;
	mid = (mind + maxd) >> 1;
	while (mind <= maxd) {
		t = Pentagonal(mid);
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
	int64_t miniNum = INT_MAX;
	int64_t n = 1, m, p1, p2;
	while (true) {
		p1 = Pentagonal(n);
		p2 = Pentagonal(n - 1);
		if (p1 - p2 > miniNum) break;
		for (int32_t m = n - 1; m >= 1; m--) {
			p2 = Pentagonal(m);
			if (p1 - p2 >= miniNum) break;
			if (isPentagonal(p1 + p2) && isPentagonal(p1 - p2)) {
				miniNum = p1 - p2;
			}
		}
		++n;
	}
	std::cout << miniNum;
	system("pause");
	return 0;
}