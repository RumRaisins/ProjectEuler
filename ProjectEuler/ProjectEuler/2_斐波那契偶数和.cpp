#include"ReadText.h"
using namespace std;

int32_t main() {

	/*int n;
	int count = 2;
	int sum = 0;
	while (cin >> n) {
		sum = 0;
		int *p = new int[n]();
		p[0] = p[1] = 1;
		for (int i = 2; i < n; i++) {
			p[i] = p[i - 1] + p[i - 2];
			count++;
			if (count == 3) {
				sum += p[i];
				count = 0;
			}
			if (p[i] > 4000000)
				break;
		}
		cout << sum;

		delete[] p;
	}*/
	int32_t sum = 0;
	int32_t a = 1, b = 1;
	while(b<4000000){
		int temp = b;
		b += a;
		a = temp;
		if (!(b & 1))
			sum += b;
	}


	system("pause");
	return 0;
}