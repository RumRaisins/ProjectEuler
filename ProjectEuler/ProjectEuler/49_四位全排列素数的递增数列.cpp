#include"ReadText.h"
using namespace std;

int isPrimer[10000] = { 0 };
int Primer[10000] = { 0 };


int main() {
	for (int i = 2; i < 10000; i++)
	{
		if (!Primer[i]) {
			Primer[++Primer[0]] = i;
			isPrimer[i] = 1;
		}
		for (int j = 1; j <= Primer[0] && Primer[j]*i <= 10000; j++)
		{
			Primer[i*Primer[j]] = 1;
			if ( i % Primer[j] == 0)break;
		}
	}
	cout << Primer[2]<<endl;
	for (int i = 1000; i < 9999; i++)
	{
		if (!isPrimer[i]) continue;
		int temp = i, counter = 3;
		int p[4] = { 0 };
		int list[5] = { 0 };
		while (counter >= 0)
		{
			p[counter--] = temp % 10;
			temp /= 10;
		}
		do {
			temp = 0;
			temp = p[0] * 1000 + p[1] * 100 + p[2] * 10 + p[3];
			//cout << temp << endl;
			if (temp > 10000)continue;
			if (!isPrimer[temp])continue;
			list[++counter] = temp;
		} while (next_permutation(p, p + 4));
		if (list[2] - list[1] == list[1] - list[0]) {
			cout << list[2] << " " << list[1] << " " << list[0] << endl;
		}
		else {
			list[2] = list[1] = list[0] = 0;
		}
		
	}



	system("pause");
	return 0;
}