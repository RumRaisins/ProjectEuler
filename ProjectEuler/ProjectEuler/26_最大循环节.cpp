
#include "ReadText.h"
using namespace std;





int main() {
	

	map<int, int> isCircle;
	int CircleLength[2] = { 0,0 };
	for (int i = 2 ; i < 1000 ; i++)
	{
		int temp = 1, j = 2; isCircle.clear(); isCircle[1] = 1;
		while (1) {
			temp =temp * 10 % i;
			//cout << temp << " ";
			if (temp == 0) {
				break;
			}
			if (isCircle[temp] == 0) {
				isCircle[temp] = j++;
			}
			else {
				j = j - isCircle[temp];
				//cout << j;
				if (j > CircleLength[0]) {
					CircleLength[0] = j;
					CircleLength[1] = i;
				}
				break;
			}
			
		}
		cout << endl;
	}
	cout << CircleLength[1];




	system("pause");
	return 0;
}