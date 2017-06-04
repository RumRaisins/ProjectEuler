#include"ReadText.h"

using namespace std;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {

	int p[1001] = { 0 };
	int a, b, c;
	for (int i = 2; i*i < 1000; i++)
	{
		for (int j = 1; j < i; j++)
		{
			a = i*i - j*j;
			b = 2 * i*j;
			c = i*i + j*j;
			int l = a + b + c;
			if (l > 1000)continue;
			if (gcd(gcd(a, b), gcd(b, c)) != 1)continue;
			for (int k = l; k < 1000; k+=l)
			{
				p[k]++;
				if (k == 960)
					cout << a << " " << b << " " << c << endl;
			}
		}
	}
	int maxP = p[0];
	for (int i = 1; i < 1000; i++)
	{
		if (p[i] > p[maxP])
			maxP = i;
	}
	cout << maxP;

	system("pause");
	return 0;
}