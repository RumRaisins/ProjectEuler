#include<iostream>
#include<vector>

#include "ReadText.h"

#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;




int main() {

	string path = "Z:\\ProjectEuler\\ProjectEuler\\ProjectEuler\\18.txt";
	vector<vector<int> > vec;
	vec = readTriangleInt(path);
	//for (int i = 0; i < vec.size(); i++)
	//{
	//	for (int j = 0; j < vec[i].size(); j++)
	//	{
	//		//vec[i][j] = max(vec[i + 1][j], vec[i + 1][j + 1]) + vec[i][j];
	//		cout << vec[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	for (int i = vec.size() - 2 ; i  >= 0 ; i--)
	{
		for (int j = 0 ; j < vec[i].size(); j++)
		{
			vec[i][j] = max(vec[i + 1][j], vec[i + 1][j + 1]) + vec[i][j];
			//cout << vec[i][j] << " ";
		}
		//cout << endl;
	}
	cout << vec[0][0] <<endl;



	system("pause");
	return 0;
}