#include"ReadText.h"
using namespace std;
int main() {

	//long long int n = 600851475143;
	//int *isPrime = new int[0x7fffffe]();
	//for (int i = 2; i < n; i++) {
	//	if (!isPrime[i]) {
	//		isPrime[++isPrime[0]] = i;
	//		if ( n % i == 0) {
	//			//cout << i<<" ";
	//			n = n / i;
	//			cout << n<<" ";
	//			if (n == 0)
	//				break;
	//		}
	//	}
	//	for (int j = 1 ; j <= isPrime[0] && i*isPrime[j] <= n; j++){
	//		isPrime[i*isPrime[j]] = 1;
	//		if (i%isPrime[j] == 0) {
	//			break;
	//		}
	//	}
	//}
	int32_t n = 600851475143;
	int maxPrime = 2;
	for (size_t i = 2; i*i < n; i++)
	{
		while(n %i == 0){
			n = n / i;
			maxPrime = i;
		}
	}
	if (n != 1) maxPrime = n;
	cout << n;
	system("pause");
	return 0;
}