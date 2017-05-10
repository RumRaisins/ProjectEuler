#include<iostream>
#include<math.h>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;




int main() {

	int *isPrime = new int[0x7ffffff]();
	int n = 0;
	unsigned long long  int sum = 0;
	while (cin >> n) {
		for (int i = 0; i < 0x7ffffff; i++)
		{
			isPrime[i] = 0;
		}
		for (int i = 2; i < n; i++)
		{
			if (!isPrime[i]) {
				isPrime[++isPrime[0]] = i;
			}
			for (int j = 1; j <= isPrime[0] && i*isPrime[j] <= n; j++)
			{
				isPrime[i*isPrime[j]] = 1;
				if (i%isPrime[j] == 0) {
					break;
				}
			}
		}

		string s = "Z:\\ProjectEuler\\ProjectEuler\\ProjectEuler\\ËØÊý±í.txt";
		fstream out(s);
		if (out.is_open()) {
			for (int i = 0; i <= isPrime[0]; i++)
			{
				out << isPrime[i] << endl;
			}
		}

		out.close();
	}
	system("pause");
	return 0;
}