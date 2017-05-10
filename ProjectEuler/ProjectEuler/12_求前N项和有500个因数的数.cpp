#include<iostream>
#include<string>
#include"ReadText.h"
using namespace std;



int PrimeNumber(int* p, int sum) {
	int flag = 0 ,ans = 1;
	int counter = 1;
	while (sum > 1) {
		flag = 0;
		while(sum % p[counter] == 0) {
			sum /= p[counter];
			flag++;
		}
		ans *= (flag + 1);
		counter++;
	}
	return ans;
}

int main() {
	string path = "Z:\\ProjectEuler\\ProjectEuler\\ProjectEuler\\ËØÊý±í.txt";
	bool noStop = true;
	int *p;
	readPrimeText(path,&p);
	int lp = p[0] + 1;
	int sum = 0;
	for (int i = 1; noStop; i++) {
		sum += i;
		int num = PrimeNumber(p, sum);
		cout << num << endl;
		if ( num >= 500) {
			cout << sum<<endl;
			noStop = false;
		}
	}

	delete[] p;
	
	system("pause");
	return 0;
}