#include"ReadText.h"
using namespace std;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a%b);
}

int main() {
	int x1, x2, y1, y2;
	int sum1 = 1, sum2 = 1;
	for (size_t i = 10; i <= 99; i++)       //i·Ö×Ó
	{
		for (size_t j = i+1; j <= 99; j++)  //j·ÖÄ¸
		{
			x1 = i / 10; x2 = i % 10;
			y1 = j / 10; y2 = j % 10;
			if (!x1 || !x2 || !y1 || !y2) continue;
			if (x1 == y1 && x2 * j == y2 * i && x2 != 0) sum1 *=i,sum2*=j;
			if (x1 == y2 && x2 * j == y1 * i && x2 != 0) sum1 *= i, sum2 *= j;
			if (x2 == y2 && x1 * j == y1 * i && x1 != 0) sum1 *= i, sum2 *= j;
			if (x2 == y1 && x1 * j == y2 * i && x1 != 0) sum1 *= i, sum2 *= j;
		}
	}
	int c = gcd(sum1,sum2);
	sum2 /= c;
	cout << sum2;







	system("pause");
	return 0;
}