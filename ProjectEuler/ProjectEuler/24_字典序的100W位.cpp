#include <iostream>  
#include <algorithm>  

using namespace std;

const int N = 1000000;

int main()
{
	int val[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int i = 1; i < N; i++)
		next_permutation(val, val + 10);

	for (int i = 0; i < 10; i++)
		cout << val[i];
	cout << endl;
	system("pause");
	return 0;
}

