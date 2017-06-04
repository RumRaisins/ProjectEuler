#include "ReadText.h"
using namespace std;


#define MAX_N 28123
int Primer[MAX_N + 5] = { 0 };
using namespace std;

void InitPrime(int *primer, int range) {
	for (size_t i = 2; i <= range; i++)
	{
		if (!primer[i]) primer[++primer[0]] = i;
		for (size_t j = 1; j <= primer[0] && primer[j] * i < range; j++) {
			primer[primer[j] * i] = 1;
			if (i%primer[j] == 0)break;
		}
	}
}

int PrimeNum(int n,int prime) {
	int i = 0;
	while (n % prime == 0)
	{
		i++;
		n /= prime;
	}
	return i;
}


int main() {
	InitPrime(Primer, MAX_N);
	int abundantInt[28123] = { 0 };
	int int28123[28124] = { 0 };
	int counter = 0;
	
	for (int i = 12 ; i <= 28123;i++)
	{
		int temp = i, j = 1, sum = 1;
		while (temp != 1)
		{
			if (temp % Primer[j] == 0) {
				int n = PrimeNum(temp, Primer[j]);
				n = pow(Primer[j], n);
				sum *= (1 - n*Primer[j]) / (1 - Primer[j]);
				//cout << sum << " ";
				temp /= n;
				j++;
			}
			else {
				j++;
			}
		}
		if (sum-i > i) {
			abundantInt[counter]=i;
			//abundantInt[i] = 1;
			counter++;
		}
	}
	ulli sum = 0;
	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j <counter ; j++)
		{
			if (abundantInt[i] + abundantInt[j] > 28123)break;
			int28123[abundantInt[i] + abundantInt[j]] = 1;
			if(abundantInt[i] + abundantInt[j] ==20)
				cout << i << " " << j << endl;;
		}
	}
	
	for (int i = 1; i <= 28123; i++)
	{
		
		if (!int28123[i]) {
			sum += i;//, cout << i << " ";
		}
	}
	cout << sum;
	system("pause");
	return 0;
}