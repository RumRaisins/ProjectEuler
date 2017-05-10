#include<iostream>
#include<vector>
using namespace std;
int main() {

	long long int n = 600851475143;
	int *isPrime = new int[0x7fffffe]();
	for (int i = 2; i < n; i++) {
		if (!isPrime[i]) {
			isPrime[++isPrime[0]] = i;
			if ( n % i == 0) {
				//cout << i<<" ";
				n = n / i;
				cout << n<<" ";
				if (n == 0)
					break;
			}
		}
		for (int j = 1 ; j <= isPrime[0] && i*isPrime[j] <= n; j++){
			isPrime[i*isPrime[j]] = 1;
			if (i%isPrime[j] == 0) {
				break;
			}
		}
	}
	//cout << isPrime[10001];
	/*for (int i = 1 ; i <isPrime[0]; i++)
	{
		cout << isPrime[i] << " ";
	}
	cout << endl;*/
	



	system("pause");
	return 0;
}