#include<iostream>
#include<math.h>
using namespace std;




int main() {

	for (int a = 1; a < 1000; a++)
	{
		for (int b = 2;b<1000;b++)
		{
			int c = 1000 - a - b;
			if(a+b <= c)
				continue;
			if (a*a + b*b == c*c) {
				cout << a<<" "<<b<<" "<<c<<""<<a*b*c<<endl;
				break;
			}

		}

	}








	system("pause");
	return 0;
}