#include<iostream>
#include<math.h>
using namespace std;




int main() {

	int *isPrime = new int[0x7fffff]();

	for (int i = 2 ; i < 1000200 ; i++)
	{
		if (!isPrime[i]) {
			isPrime[++isPrime[0]] = i;
		}
		if (isPrime[0] > 10003) {
			break;
		}
		for (int j = 1 ; j <= isPrime[0] && i*isPrime[j]<=1000200 ; j++)
		{
			isPrime[i*isPrime[j]] = 1;
			if (i % isPrime[j] == 0) {
				break;
			}
		}
	}
	/*for (int i=1 ; i<100;i++)
	{
		cout << i << " : " << isPrime[i] << endl;
	}*/
	cout << isPrime[10001];








	system("pause");
	return 0;
}