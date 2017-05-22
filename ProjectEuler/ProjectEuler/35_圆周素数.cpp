#include "ReadText.h"

using namespace std;
map<int, int> prime;

int main() {

	string path = "Z:\\ProjectEuler\\ProjectEuler\\ProjectEuler\\ËØÊý±í.txt";
	char line[256];
	fstream ifile(path);
	if (ifile.good()) {

		ifile.getline(line, 256);
		std::istringstream  iss(line);
		int n;
		iss >> n;
		for (int i = 1; i < n+1 ; i++)
		{
			ifile.getline(line, 256);
			std::istringstream iss(line);
			iss >> n;
			prime[n] = 1;
		}
		ifile.close();
	}
	int counter = 0;
	for (map<int,int>::iterator c = prime.begin() ; c != prime.end(); ++c)
	{
		//cout << c->first << " ";
		int temp = c->first, bit = 0;
		while (temp)
		{
			temp /= 10;
			bit++;
		}
		temp = c->first;
		bool isCircle = true;
		int tempbit = bit - 1;
		
		while (tempbit)
		{
			int i = temp % 10;
			temp = temp / 10 + i*pow(10, bit - 1);
			 map<int, int>::iterator c = prime.find(temp);
			if (c == prime.end()) {
				isCircle = false;
				break;
			}
			//if (prime[temp] == 0) {
			//	//prime[temp] = 0;
			//	isCircle = false;
			//	break;
			//}
			tempbit--;
		}
	
		if (isCircle)
		{
			counter++;
			cout << c->first << " ";
		}

	}
	cout << endl << counter << endl;


	system("pause");
	return 0;
}
