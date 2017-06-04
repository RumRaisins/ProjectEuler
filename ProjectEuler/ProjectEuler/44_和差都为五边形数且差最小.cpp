#include"ReadText.h"
using namespace std;


ulli Pentagonal(ulli n) {
	return n * (3 * n - 1) / 2;
}
bool isPentagonal(int n) {
	int min = 1, max = n, mind = (min + max) >> 1;
	while (min <= max) {
		int t = Pentagonal(mind);
		if (t > n) max--;
		else if(t < n)min++;
		else if (t == n)return true;
		mind = (min + max) >> 1;

	}
	return false;
}

int main() {

	int i = 2;
	ulli p1, p2;
	int min = 0;
	while (true) {
		p1 = Pentagonal(i);
	    p2 = Pentagonal(i - 1);
		if (p1 - p1 > min) break;
		for (int j = i-1; j >=1; j--)
		{
			p2 = Pentagonal(j);
			if (p1 - p2 > min)break;
			if (isPentagonal(p1 + p2) && isPentagonal(p1 - p2)) {
				min = p1 - p2;
			}
		}
		i++;

	}
	cout << min;

	system("pause");
	return 0;
}