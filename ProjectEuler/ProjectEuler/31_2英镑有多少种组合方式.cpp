
#include "ReadText.h"
using namespace std;

int main() {
	////FILE * fin = fopen(fiepath, "r");
	//
	////fscanf(fin, "\"%s\"",);
	////fprintf(fin, ......);
	////fclose(fin);
	int coins[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };
	int TARGET = 200;
	int	matrix[201][8];
	for (auto y = 0; y < TARGET + 1; y++) {
		matrix[y][0] = 1;
	}
	for (int y = 0; y < TARGET + 1; y++) {
		for (int x = 1; x < 8; x++) {
			matrix[y][x] = 0;
			if (y >= coins[x]) {
				matrix[y][x] += matrix[y][x - 1]+ matrix[y - coins[x]][x];
			}
			else {
				matrix[y][x] = matrix[y][x - 1];
			}
			
		}
	}
	cout << matrix[200][7];
	system("pause");
	return 0;
}