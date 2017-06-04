#include"ReadText.h"
using namespace std;

int main() {

	ulli num6 = 6, num5 = 5, num3 = 3;
	ulli i = 2, j = 2, k = 2;
	while (num3 != num5 || num5 != num6 || num3 != num6 || num3 == 40755) {
		num6 = i*(2 * i - 1);
		i++;
		for (;num6 > num5; j++)
			num5 = j*(3 * j - 1) >> 1;
		for (;num6 > num3; k++)
			num3 = k*(k + 1) >> 1;
	
	}
	
	cout << num6;






	system("pause");
	return 0;
}