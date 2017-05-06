#include<iostream>
#include<math.h>
using namespace std;


int normal(int n) {
	 n = n - 1;
	int sum = 0;
	int n5 = n / 5;
	int n3 = n / 3;
	int n35 = n / 15;
	sum += (3 + n3 * 3) * n3 >> 1;
	sum += (5 + n5 * 5) * n5 >> 1;
	sum -= (1 + n35) * n35 * 15 >> 1 ;
	return sum;
}

int main() {

	int n;
	while (cin >> n) {
		cout<<normal(n)<<endl;
	}
	
	

	system("pause");
	return 0;
}