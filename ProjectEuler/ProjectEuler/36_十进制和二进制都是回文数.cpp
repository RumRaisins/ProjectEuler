#include "ReadText.h"
using namespace std;

bool isCircleNumber(int n) {
	int temp = n;
	int changen = 0;
	while (temp) {
		changen = changen * 10 + temp % 10;
		temp /= 10;
	}
	return changen == n;
}
bool isCircleNumber(string s) {
	int ls = s.length();
	if (ls == 1)
		return true;
	if (ls == 2) 
		return s[0] == s[1];
	if (ls & 1) {
		ls--;
		for (int i = 0; i != ls; i++, ls--)
		{
			if (s[i] != s[ls]) {
				return false;
			}
		}
		return true;
	}
	int i = 0;
	ls--;
	for (i = 0; i +1!= ls; i++, ls--)
	{
		if (s[i] != s[ls]) {
			return false;
		}
	}
	return s[i] == s[ls];
	
	
}
string tenTotwo(int n) {
	string two;
	while (n) {
		char s = n % 2 + '0';
		two = s + two;
		n /= 2;
		if (n == 1) {
			two = '1'+ two;
			break;
		}
	}
	return two;
}


int main() {
	int n = 101;
	//cout << tenTotwo(1000000);
	//cout << isCircleNumber("1012001");
	//cout << isCircleNumber(tenTotwo(1));
	int sum = 0;
	for (int i = 1 ; i < 1000000; i++)
	{
		if (isCircleNumber(i) && isCircleNumber(tenTotwo(i))) {
			cout << i << endl;
			sum += i;
		}
	}
	cout << sum;
	system("pause");
	return 0;
}