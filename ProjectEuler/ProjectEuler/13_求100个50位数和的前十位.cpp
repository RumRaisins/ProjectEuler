#include<iostream>
#include<math.h>

#include "ReadText.h"

#define  INT_LENGTH 500
using namespace std;




int main() {
	string path = "Z:\\ProjectEuler\\ProjectEuler\\ProjectEuler\\12.txt";
	string *p;
	readBigInt(path,&p,INT_LENGTH,100);
	string sum = p[0];
	for (int i = 1 ; i < 100 ; i++ )
	{
		sum = BigIntAdd(sum, p[i]);
	}
	for (int i = 0 ; i < 10 ; i++)
	{
		cout << sum[i];
	}
	cout << endl;
	system("pause");
	return 0;
}