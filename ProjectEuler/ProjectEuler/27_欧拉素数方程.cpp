#include"ReadText.h"
using namespace std;

int isPrimer[1000] = { 0 };
int Primer[1000] = { 0 };

int main() {
	for (int i = 2; i < 1000; i++)
	{
		if (!Primer[i]) {
			Primer[++Primer[0]] = i;
			isPrimer[i] = 1;
		}
		for (int j = 1; j <=Primer[0] && i*Primer[j]<=1000; j++)
		{
			Primer[ i*Primer[j]] = 1;
			if (i%Primer[j] == 0)break;
		}
	}
	int maxCounter = 0, counter = 0, result = 0;
	for (int a = -65; a < 1000; a += 2)
	{
		for (int b = 1; b < Primer[0]; b++)
		{
			counter = 0;
			for (int n = 0; true; n++)
			{
				if (!isPrimer[n*n + a*n + Primer[b]]) break;
				counter++;
			}
			if (counter > maxCounter) {
				maxCounter = counter;
				result = a*Primer[b];
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}