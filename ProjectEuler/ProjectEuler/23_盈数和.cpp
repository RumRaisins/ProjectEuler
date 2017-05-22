#include "ReadText.h"
using namespace std;

int PrimeNum(int n,int prime) {
	int i = 0;
	while (n % prime==0)
	{
		i++;
		n /= prime;
	}
	//cout << i;
	return i;
}


int main() {
	
	string path = "Z:\\ProjectEuler\\ProjectEuler\\ProjectEuler\\ËØÊý±í.txt";
	bool noStop = true;
	int *p;
	readPrimeText(path, &p);
	int lp = p[0] + 1;
	/*for (int i = 0 ; i < lp;i++)
	{
		cout << p[i]<<" ";
	}*/
	//map<int, int>abundantInt;
	vector<int> abundantInt2;
	for (int i = 12 ; i <= 20161;i++)
	{
		int temp = i, j = 1, sum = 1;
		while (temp != 1)
		{
			if (temp % p[j] == 0) {
				int n = PrimeNum(temp, p[j]);
				n = pow(p[j], n);
				sum *= (1 - n*p[j]) / (1 - p[j]);
				//cout << sum << " ";
				temp /= n;
				j++;
			}
			else {
				j++;
			}
		}
		if (sum-i > i) {
			abundantInt2.push_back(i);
			//abundantInt[i] = 1;
		}
	}
	ulli sum = 0;
	int ls = abundantInt2.size();
	for (int i = 1; i <= 20161; i++)
	{
		for (int j = 0; j <ls ; j++)
		{
			if (i < abundantInt2[j]) {
				sum += i;
				break;
			}
			vector<int>::iterator it = find(abundantInt2.begin(), abundantInt2.end(), i - abundantInt2[j]);
			if (it != abundantInt2.end()) {
				sum += i;
				break;
			}
		}
		cout << sum << endl;
	}
	cout << sum;


	//ulli sum = (1 + 20161) * 20161 >> 1;
	//cout << sum << endl;
	//for (int i = 1; i <= 20161; i++)
	//{
	//	if (abundantInt[i] == 1)
	//		sum -= i;
	//}
	//cout << sum;

	///*for (int i = 1; i <= 100; i++)
	//{
	//	if (abundantInt[i] == 1)
	//		cout << i << endl;
	//}*/
	system("pause");
	return 0;
}