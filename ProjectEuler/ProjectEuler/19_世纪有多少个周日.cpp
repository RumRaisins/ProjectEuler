#include<iostream>
#include<vector>

#include "ReadText.h"

#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;




int main() {
	int days = 0 ;
	int num = 0;

	for (int i = 1901 ; i <= 2000 ; i++)
	{
		for (int j = 1 ; j <= 12 ; j++)
		{
			if (days % 7 == 6)num++;
			if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8  || j == 10 || j == 12) {
				days += 31;
			}
			else if (j == 4 || j == 6 || j == 9 || j == 11) {
				days += 30;
			}
			else if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
				days += 29;
			}
			else {
				days += 28;
			}

		}
		
	}
	cout << num -1;



	system("pause");
	return 0;
}