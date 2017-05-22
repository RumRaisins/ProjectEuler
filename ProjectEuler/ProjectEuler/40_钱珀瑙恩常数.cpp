#include"ReadText.h"
using namespace std;


int main() {

	string str;
	int sum = 0;
	for (int i = 1;; i++)
	{
		int n = i;
		string tempstr;
		while (n) {
			char temp = n % 10 +'0';		
			tempstr = temp + tempstr;
			n = n / 10;
		}
		str += tempstr;
		
		if (str.length() > 1000000) {
			sum = (str[1 - 1] - '0') * (str[10 - 1] - '0') * (str[100 - 1] - '0')
				*(str[1000 - 1] - '0') * (str[10000 - 1] - '0') * (str[100000 - 1] - '0') * (str[1000000 - 1] - '0');
			cout << sum << endl;
			break;
		}
	/*	if (i > 22) {
			cout << str[8]<<endl;
			break;
		}*/
	}
	//cout << str;
	system("pause");
	return 0;
}