#include"ReadText.h"
using namespace std;

int main() {

	int i, n;
	scanf("%d", &n);
	for (i = 2; i*i < n; i++) 
		if (n%i == 0)break;
	if (i<n || n == 1)puts("No");
	else puts("Yes");
	system("pause");
	return 0;
}