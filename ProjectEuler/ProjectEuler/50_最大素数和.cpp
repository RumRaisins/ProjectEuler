#include"ReadText.h"

#define MAX_N 1000000
int isPrimer[MAX_N + 5] = { 0 };
int Primer[MAX_N + 5] = { 0 };


using namespace std;

void InitPrime(int *primer, int range, int *isprimer) {
	isprimer[0] = 1, isprimer[1] = 1;
	for (size_t i = 2; i <=	 range; i++)
	{
		if (!isprimer[i]) { primer[++primer[0]] = i; isprimer[i] = i; }
		for (size_t j = 1; j <= primer[0] && primer[j] * i < range; j++) {
			isprimer[primer[j] * i] = 1;
			if (i%primer[j] == 0)break;
		}
	}
}
int main() {
	InitPrime(Primer, MAX_N, isPrimer);
	int sum = 0 ,Max = 0;
	//for (int i = 1; i < Primer[0]; i++)
	//{
	//	cout << sum << "+"<<Primer[i]<<" = ";
	//	sum += Primer[i];
	//	cout << sum <<endl;
	//	if (sum > 1000) {
	//		break;
	//	}
	//	if (isPrimer[sum] != 1) {
	//		//cout << sum<<endl;
	//		if (sum > Max) {
	//			Max = sum;
	//		}
	//	}
	//}
	int counter = 0; int maxCounter = 0;
	for (int i = 1; i < Primer[0]; i++)
	{
		sum = 0; counter = 0; if (Primer[i] > 1000000)break;
		for (size_t j = i;j < Primer[0]; j++)
		{
			//cout << sum << "+" << Primer[j] << " = ";
			sum += Primer[j];
			counter++;
			//cout << sum << endl;
			if (sum > 1000000) {
				break;
			}
			if (isPrimer[sum] != 1) {
				//cout << sum<<endl;
				if (counter > maxCounter) {
					Max = sum;
					maxCounter = counter;
					//cout << sum<<"га" << counter << "Иі" << endl;
				}
			}
		}
		//cout << endl;
		
	}
	cout << Max;





	system("pause");
	return 0;
}