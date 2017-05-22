
#include "ReadText.h"

#include <stdio.h>
#include <time.h>

using namespace std;





int main() {
	clock_t start, finish;
	double totaltime;
	start = clock();
	const double EPSINON = 0.0001;
	//const double EPSINON = 10;
	//vector<double> vec;
	//vec.push_back(2); vec.push_back(3);
	map<double, int> mapp;
	for (double a = 2 ; a <= 100 ; a++)
	{
		for (double b= 2 ; b <= 100 ; b++)
		{
			//double temp = static_cast<double>(log(a) / log(2)*b);
			////cout << temp << endl;
			//for (double c:vec)
			//{
			//	if (c - temp > EPSINON) {
			//		vec.push_back(temp);
			//		break;
			//	}
		
			//}
			double temp = pow(a, b);
			if (mapp[temp] == 0) {
				mapp[temp] == 1;
			}
		}
	}
	cout << mapp.size();
	//cout << vec.size();
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;

	system("pause");
	return 0;
}