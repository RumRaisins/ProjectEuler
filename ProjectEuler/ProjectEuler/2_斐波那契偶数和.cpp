#include<iostream>
#include<math.h>
using namespace std;
int main() {

	int n;
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
	}



	system("pause");
	return 0;
}