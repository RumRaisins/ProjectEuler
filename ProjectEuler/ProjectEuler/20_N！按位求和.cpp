#include<iostream>
#include<string>

#include "ReadText.h"
using namespace std;




int main() {
	string sum = "1";
	//ulli sum = 1, wsum = 0;
	for (int i = 1; i <= 100; i++)
	{
		string si;
		int tempi = i;
		while (tempi) {
			char c = tempi % 10 + '0';
			tempi /= 10;
			si = c + si;
		}
		//cout << si << endl;
		sum = BigIntMul(sum, si);
		cout << sum << endl;
	}
	ulli sums = 0;
	for (int i = 0 ; i < sum.length(); i++)
	{
		sums += sum[i] - '0';
	}
	cout << sums;
	system("pause");
	return 0;
}