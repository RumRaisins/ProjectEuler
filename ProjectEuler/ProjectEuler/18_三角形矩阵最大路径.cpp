#include<iostream>
#include<vector>

#include "ReadText.h"
using namespace std;




int main() {

	string path = "Z:\\ProjectEuler\\ProjectEuler\\ProjectEuler\\18.txt";
	vector<vector<int> > vec;
	vec = readTriangleInt(path);
	for (int i = 0 ; i  < vec.size() ; i++)
	{
		for (int j = 0 ; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}



	system("pause");
	return 0;
}