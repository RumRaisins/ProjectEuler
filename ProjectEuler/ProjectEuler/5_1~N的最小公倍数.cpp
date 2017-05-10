#include<iostream>
using namespace std;
//最大公约数
int GCD(int m, int n) {
	int temp = 0;
	while (n != 0) {
		temp = m%n;
		m = n;
		n = temp;
	}

	return m;
}
//最小公倍数
unsigned long long int LCM( unsigned long long int m, unsigned long long int n) {
	return m*n/GCD(m,n);
}



int main() {
	unsigned long long int n = 232792560 , lcm = 1;
	//cout << <<endl;
	//cout << n*20<<endl;
	//unsigned long int n = 0, lcm = 1;
	while (cin >> n) {
		lcm = 1;
		for (int i = 2; i <= n; i++)
		{
			lcm = LCM(lcm, i);
			cout << lcm << " i:"<<i<<" ";
		}
		cout << lcm<<endl;
	}
	





	system("pause");
	return 0;
}