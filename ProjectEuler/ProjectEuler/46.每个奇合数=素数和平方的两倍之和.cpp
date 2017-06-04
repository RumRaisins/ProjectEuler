#include"ReadText.h"
using namespace std;

#define MAX_N 10000

int Primer[MAX_N] = { 0 };
int Mark[MAX_N] = { 0 };



int main() {
	for (int i = 2; i < MAX_N; i++)
	{
		if (!Primer[i]) {
			Primer[++Primer[0]] = i;
			Mark[i] = 1;
		}
		for (int j = 1; j <=Primer[0] && Primer[j] * i <= MAX_N; j++)
		{
			Primer[i * Primer[j]] = 1;
			if (i % Primer[j] == 0) break;
		}
	}
	for (int i = 1; i <=Primer[0]; i++)
	{
		for (int n = 1;true; n++)
		{
			if (Primer[i] + 2 * n * n > MAX_N)break;
			Mark[Primer[i] + 2 * n * n] = 1;
		}
	}
	for (int i = 9; i < MAX_N; i+=2)
	{
		if (Mark[i]) continue;
		cout << i;
		break;
	}

	system("pause");
	return 0;

}