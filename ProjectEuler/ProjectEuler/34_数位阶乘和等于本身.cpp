
#include "ReadText.h"

using namespace std;




int main() {

	int *p = new int[11]();
	p[0] = 1;
	for (int i = 1; i < 10; i++) {
		p[i] = p[i-1] * i;
	}
	for (int i = 10; i < 100000; i++) {
		int temp = i ,sum = 0;
		bool jump = false;
		while (temp) {
			if (p[temp % 10] > i || sum > i) {
				jump = true;
				break;
			}
			sum += p[temp % 10];
			temp /= 10;
		}
		if (jump)
			continue;
		if (sum == i)
			cout << i<<endl;
	}
	

	system("pause");
	return 0;
}