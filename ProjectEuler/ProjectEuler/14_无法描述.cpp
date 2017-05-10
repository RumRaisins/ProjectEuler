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
	//����
		
		ulli nFindKey = 3 * n +1;            //Ҫ���ҵ�Key
		//cout << nFindKey << endl;
									 //����һ����Ŀ����(ʵ����ָ��)
		map<ulli,ulli>::iterator it = BST.find(nFindKey);
		if (it == BST.end()) {
			//û�ҵ�
			return BST[n] = NofChain(nFindKey) + 1;
		}
		else {
			return BST[n] = BST[nFindKey] + 1;
		}
	}
	else {
		ulli nFindKey =  n >> 1;            //Ҫ���ҵ�Key
		//cout << nFindKey << endl;									  //����һ����Ŀ����(ʵ����ָ��)
		map<ulli, ulli>::iterator it = BST.find(nFindKey);
		if (it == BST.end()) {
			//û�ҵ�
			return BST[n] = NofChain(nFindKey) + 1;
		}
		else {
			//�ҵ�
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