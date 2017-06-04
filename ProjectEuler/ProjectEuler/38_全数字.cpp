#include"ReadText.h"
using namespace std;




bool isPandigital(int n, int& result) {
	int num = 0, a[10] = { 10 };
	int ret = 0, i = 1, x;
	while (num < 9) {
		x = n * i;
		while (x) {
			if (x % 10 == 0)return false;
			if (a[x % 10])return false;
			a[x % 10] = (++num);
			x /= 10;
		}

		ret *= static_cast<int>(pow(10, floor(log10(n*i) + 1)));
		ret += n*i;
		++i;
	}
	result = ret;
	return true;
}



int main() {
	int num = 0, maxNum = 0;
	for (int i = 1; i < 10000; i++)
	{
		if (!isPandigital(i, num))continue;
		if (num > maxNum) maxNum = num;
	}
	cout << num;

	system("pause");
	return 0;
}