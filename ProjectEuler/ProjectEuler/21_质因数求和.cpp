#include<iostream>
#include<string>
#include<map>
#include "ReadText.h"
using namespace std;

map<int, int> BST;



int main() {

	ulli sum = 0;

	for (int i =1 ; i <10000 ; i++)
	{
		sum = 1;
		for (int j =2 ; j < i ; j++)
		{
			if (i%j == 0) {
				int temp = i / j;
				if (temp < j) {
					break;
				}
				sum += (temp + j);
			}
		}
		
		if (sum != 1) {
			if (BST[i] == 0) {
				BST[i] = sum;
				BST[sum] = i;
			}
			else {
				if (BST[i] == sum) {
					cout << i << " ºÍ " << sum << endl;
				}
			}		
		}
	}
	system("pause");
	return 0;
}