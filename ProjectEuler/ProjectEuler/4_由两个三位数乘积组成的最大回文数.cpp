#include<iostream>
using namespace std;
int main() {

	bool stop = true;
	for (int i = 997799; (i >= 10001)&&stop; i--)
	{
		
		int fi = 0, temp = i;
		while (temp != 0) {
			fi = (fi * 10 + temp % 10);
			temp = temp / 10;
		}
		if (fi == i) {
			for (int j = 100 ;j <= 999 ; j++)
			{
				if (i%j == 0) {
					if ((i/j) / 1000 == 0) {
						cout << j << " " << (i / j) << " i:" << i << endl;
						stop = false;
						break;
					}	
				}
			}
		}
	}
	



	system("pause");
	return 0;
}