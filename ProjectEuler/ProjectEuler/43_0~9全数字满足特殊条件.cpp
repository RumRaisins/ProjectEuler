#include"ReadText.h"
using namespace std;

int prime[7] = { 2,3,5,7,11,13,17 };

bool isSpecial(int*p) {
	int j = 0;
	bool isSp = true;
	for (size_t i = 1; i <= 7 ; i++)
	{
		int temp = p[i] * 100 + p[i + 1] * 10 + p[i + 2];
		if (temp % prime[j]) {
			isSp = false;
			break;
		}
		j++;
		
	}
	return isSp;

}


int main() {
	int p[10] = { 0,1,2,3,4,5,6,7,8,9 };
	ulli sum = 0;
	int n = 0;
	while (next_permutation(p, p + 10)) {
		if (isSpecial(p)) {
			ulli  temp = 0;
			for (size_t i = 0; i < 10; i++)
			{
				temp = temp * 10 + p[i];
			}
			sum += temp;
			cout << temp << endl;

		}
	}
	cout << sum << endl;




	system("pause");
	return 0;

}