#include<iostream>
#include<math.h>
using namespace std;




int main() {
	unsigned long long int sum = 0;
	
	int temp = (1 + 100) * 100 >> 1;
	
	sum = pow(temp, 2);
	cout << sum <<endl;
	for (int i = 1; i <= 100; i++)
	{
		sum -= pow(i, 2);
	}
	cout << sum;





	system("pause");
	return 0;
}