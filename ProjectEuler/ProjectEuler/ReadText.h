

#pragma once
#include<string>
#include<fstream>
#include <sstream>
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<inttypes.h>
#include<algorithm>
typedef unsigned long long int ulli;

//void readTriangleInt(std::string path,std::vector<std::vector<int> > vec);
std::vector<std::vector<int> > readTriangleInt(std::string path);
void readPrimeText(std::string path, int **p);
std::string BigIntAdd(std::string a, std::string b);
void readBigInt(std::string path, std::string** s, int numLength, int Num);
std::string BigIntMul(std::string a, std::string b);
