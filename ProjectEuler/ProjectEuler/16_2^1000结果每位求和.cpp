#include<iostream>
#include<math.h>

#include "ReadText.h"

using namespace std;





int main() {
	string a = "2";
	for (int i = 1 ; i < 1000 ; i++)
	{
		a = BigIntMul(a, "2");
	}
	int la = a.length();
	unsigned int sum = 0;
	for (int i = 0; i < la; i++) {
		sum += a[i] - '0';
	}
	cout << sum;
	system("pause");
	return 0;
}