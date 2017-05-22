
#include "ReadText.h"
using namespace std;





int main() {
	
	ulli sum = 0;

	for (int i = 2; i <= 501 ; i++)
	{
		sum += 4 * (2 * i - 1)*(2 * i - 1) - 12*(i - 1);
	}
	cout << sum + 1;

	system("pause");
	return 0;
}