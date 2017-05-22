#include "ReadText.h"



std::vector<std::vector<int> > readTriangleInt(std::string path)
{
	std::vector<std::vector<int> > vec;

	char line[500]; int i = 1;
	std::fstream ifile(path);
	while (ifile.good()) {
		std::vector<int> vecc;
		ifile.getline(line,500);
		std::istringstream iss(line);
		for (int j = 1; j <= i; j++)
		{
			int n;
			iss >> n;
			vecc.push_back(n);
		}
		vec.push_back(vecc);
		i++;
	}
	/*for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			std::cout << vec[i][j] << " ";
		}
		std::cout << std::endl;
	}*/
	return vec;
}

void readPrimeText(std::string path, int** p) {
	char line[256];
	std::fstream ifile(path);
	if (ifile.good()) {

		ifile.getline(line, 256);
		std::istringstream  iss(line);
		int n;
		iss >> n;
		*p = new int[n + 1]();
		*p[0] = n;
		for (int i = 1; i < n + 1; i++)
		{
			ifile.getline(line, 256);
			std::istringstream iss(line);
			iss >> (*p)[i];
		}
		ifile.close();
	}
}


void readBigInt(std::string path , std::string** s,int numLength,int Num){
	char* line = new char[numLength];
	*s = new std::string[Num];
	std::fstream ifile(path);
	int i = 0;
	while (ifile.good()) {
		ifile.getline(line, numLength);
		(*s)[i++] = line;
	}
	ifile.close();
}

std::string BigIntAdd(std::string a, std::string b) {
	int la = a.length();
	int lb = b.length();
	if (la < lb) return BigIntAdd(b, a);
	int temp = 0, acc = 0;
	for (int i = lb-1 ; i >= 0 ; i--)
	{
		temp = (a[--la] - '0') + (b[i] - '0') + acc;
		if (temp >= 10) {
			acc = 1;
			temp %= 10;
		}
		else {
			acc = 0;
		}
		a[la] = temp + '0';
	}
	while (la != 0 && acc) {
		temp = a[--la] - '0' + acc;
		if (temp >= 10) {
			acc = 1;
			temp %= 10;
		}
		else {
			acc = 0;
		}
		a[la] = temp + '0';
	}
	if (acc) {
		a = "1" + a;
	}
	return a;
}

std::string BigIntMul(std::string a, std::string b) {
	int la = a.length(), lb = b.length();
	if (a < b)return BigIntMul(b, a);
	int acc = 0;
	lb--;
	std::string zeroNum;
	std::string lastSum = "0";
	while (lb >= 0) {
		int lla = la-1;
		std::string tempSum;
		acc = 0;
		while (lla >= 0) {
			
			int temp = (b[lb] - '0')*(a[lla--] - '0') + acc;		
			if (temp >= 10) {
				acc = temp / 10;
				temp %= 10;
			}
			else
				acc = 0;
			char t = temp + '0';
			tempSum = t +tempSum;
		}
		if (acc) {
			char accc = acc + '0';
			tempSum = accc + tempSum;
		}
		tempSum += zeroNum;
		
		lastSum = BigIntAdd(tempSum, lastSum);
		zeroNum += "0";
		lb--;
	}
	return lastSum;
}