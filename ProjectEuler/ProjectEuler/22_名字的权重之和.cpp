
#include "ReadText.h"
using namespace std;





int main() {
	const char* path = "Z:\\ProjectEuler\\ProjectEuler\\ProjectEuler\\names.txt";
	FILE  *file = fopen(path, "r");
	char *s;
	fscanf(file, "\"%s\"",s);
	cout << s;
	//fprintf(file,"\"%s\"\,");
	fclose(file);
	system("pause");
	return 0;
}