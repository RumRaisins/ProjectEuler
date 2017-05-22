
#include "ReadText.h"
using namespace std;



int main() {
	bool isUsed[11];
	int s = 0;
	map<int, int> mapp;
	for (int i = 12; i <= 98; i++)
	{
		bool Stop = false;
		for (int k = 0 ; k < 11 ; k ++)
		{
			isUsed[k] = false;
		}						//初始化
		int j = 0;
		int tempi = i;
		while (tempi) {
			if (isUsed[tempi % 10]) {
				Stop = true;
			}
			isUsed[tempi % 10] = true;
			tempi /= 10;
		}						//判断i被用过
		if (Stop) {
			continue;
		}
		int counter = 0, jl = 1;
		while (counter != 3) {
			if (!isUsed[jl]) {
				j = j * 10 + jl;
				counter++;
				jl++;
			}
			else
				jl++;
		}			
		for (; j <= 9876; j++) {
			bool isStop = false;
			int temp = i*j;
			if (temp > 10000) 
				continue;
			bool isPrefectNumber = true;//判断是否越界
			bool isUUsed[11];
			for (int f = 0 ; f < 10 ; f++)
			{
				isUUsed[f] = isUsed[f];
			}
										//拷贝使用过的i
			int tempj = j;
			while (tempj) {
				if (isUUsed[tempj % 10] || tempj % 10==0 ) {
					isStop = true;
					break;
				}
				isUUsed[tempj % 10] = true;
				tempj /= 10;
			}							//判断使用过的j
			if (isStop) {
				continue;
			}
			int temptemp = temp;
			while (temptemp) {
				if (isUUsed[temptemp  % 10]|| temptemp % 10 ==0){
					isPrefectNumber = false;
					break;
				}
				isUUsed[temptemp % 10] = true;
				temptemp /= 10;
			}						//判断积是否被用过
			if (isPrefectNumber) {
				cout << i << "*" << j << "=" << temp << endl;
				mapp[temp] = temp;
			}
		}
	}
	int sum = 0;
	for (auto c:mapp)
	{
		sum += c.first;
	}
	cout << sum;

	system("pause");
	return 0;
}