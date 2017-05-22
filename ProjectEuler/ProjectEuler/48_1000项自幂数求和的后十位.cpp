#include"ReadText.h"
using namespace std;

int main() {

	string sum = "0", temp = "1";
	for (size_t i = 1; i <= 1000; i++)
	{
		int n = i;
		string tempi;
		while (n) {
			char lastnumber = n % 10 + '0';
			tempi = lastnumber +tempi;
			n /= 10;
		}
		temp = tempi;
		for (size_t j = 2; j <= i; j++)
		{
			temp = BigIntMul(temp, tempi);
			if (temp.length() >= 11) {
				temp = temp.substr(temp.length() - 11, 11);
			}
		}
		
		sum = BigIntAdd(sum, temp);
		if (sum.length() >= 11) {
			sum = sum.substr(sum.length() - 11, 11);
		}
	}
	/*for (size_t i = sum.length()-11; i <= sum.length() - 11; i++)
	{
		cout << sum[i];
	}
	cout << endl;*/
	cout << sum;



	system("pause");
	return 0;
}