#include<iostream>
#include<math.h>

using namespace std;

unsigned long long int Path(int m, int n) {
	if (m > n) return Path(n, m);
	unsigned long long int *p = new unsigned long long int[m]();
	for (int i = 0 ; i < m ;i++)
	{
		p[i] = 1;
		//cout << p[i];
	}
	for (int j =1 ; j < n ; j++)
	{
		for (int i = 1 ; i < m ; i++)
		{
			p[i] += p[i - 1];
		}
	}
	return p[m - 1];

}



int main() {
	
	cout << Path(21,21);


	system("pause");
	return 0;
}