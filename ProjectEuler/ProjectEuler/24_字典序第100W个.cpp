
#include "ReadText.h"
using namespace std;





int main() {
	ulli *p = new ulli[11]();
	p[0] = 1;
	int target = 1000000;
	for (int i =1 ; i <= 10 ; i++)
	{
		p[i] = p[i - 1] * i;
		cout << p[i] << endl;
	}
	string s = "0123456789";
	int ps = 0;
	
	for (int i = 10 ; i >= 1 ; i--)
	{
		bool isUsed[10];
		for (int i = 0; i <= 9; i++)
		{
			isUsed[i] = false;
		}
		int counter = 0;
		while (1) {
			if (target < p[i]) {
				break;
			}
			target = target - p[i];
			counter++;
		}
		if (i != 10) {
			ps = 9 - i;
			s[ps] = s[ps] - '0' + counter + '0';
			for (int j = 0; j <= ps; j++) {
				isUsed[s[j] - '0'] = true;
				//cout << s[j] - '0' << " ";
			}
			
			for (int j = 0; j <= 9; j++)
			{
				if (!isUsed[j]) {
					//cout << j << " ";
					if (ps != 10) {
						s[++ps] = j + '0';
					}
					else
						s[ps] = j + '0';
				}
			}
			cout << s<<endl;
		}
				
	}
	cout << s;
	system("pause");
	return 0;
}