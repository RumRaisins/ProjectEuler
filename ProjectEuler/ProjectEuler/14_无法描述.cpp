#include<iostream>
#include<math.h>
using namespace std;
#include<map>
typedef unsigned long long int ulli;
map<ulli, ulli> BST;

ulli NofChain(ulli n) {
	if (n == 1)
		return 1;
	if(n & 1){
	//奇数
		
		ulli nFindKey = 3 * n +1;            //要查找的Key
		//cout << nFindKey << endl;
									 //定义一个条目变量(实际是指针)
		map<ulli,ulli>::iterator it = BST.find(nFindKey);
		if (it == BST.end()) {
			//没找到
			return BST[n] = NofChain(nFindKey) + 1;
		}
		else {
			return BST[n] = BST[nFindKey] + 1;
		}
	}
	else {
		ulli nFindKey =  n >> 1;            //要查找的Key
		//cout << nFindKey << endl;									  //定义一个条目变量(实际是指针)
		map<ulli, ulli>::iterator it = BST.find(nFindKey);
		if (it == BST.end()) {
			//没找到
			return BST[n] = NofChain(nFindKey) + 1;
		}
		else {
			//找到
			return BST[n] = BST[nFindKey] + 1;
		}

	}
}


int main() {
	

	for (ulli i = 1; i < 1000000 ; i ++)
	{
		NofChain(i);
	}
	map<ulli, ulli>::iterator it = BST.begin();
	ulli maxTerm = 0, maxNumber = 0;
	for (; it!=BST.end(); it++)
	{
		//cout << it->first << ":" << it->second << endl;
		if (it->second > maxTerm) {
			maxTerm = it->second;
			maxNumber = it->first;
		}
	}
	cout << maxNumber << "  has " << maxTerm << "  iterms" << endl;

	system("pause");
	return 0;
}