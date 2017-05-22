
#include "ReadText.h"
using namespace std;





int main() {
	vector<string> vec;
	vec.push_back("1"); vec.push_back("1");
	int i = 2;
	for (; i < 100000000 ; i++)
	{
		string s = BigIntAdd(vec[i - 1], vec[i - 2]);
		vec.push_back(s);
		if (s.length() == 1000) {
			cout << i;
			break;
		}
	
	

	}

	system("pause");
	return 0;
}