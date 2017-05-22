
#include "ReadText.h"
using namespace std;





int main() {

	ulli sum = 0 , summ =0;
	for (ulli i = 3125 ; i < 2000000 ; i++)
	{
		int temp = i;
		sum = 0;
		while (temp) {
			int num =  temp % 10;
			sum += pow(num, 5);
			temp /= 10;
			if (sum == i && !temp) {
				cout << i <<" ";
				summ += sum;
			}	
		}
	}
	cout << summ;


	system("pause");
	return 0;
}