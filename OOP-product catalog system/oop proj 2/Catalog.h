#pragma once
#include<fstream>
#include"Products.h"
using namespace std;
class Catalog
{
	string fileName;
public:
	Catalog(string name);
	//void setName(string name);
	void add();
	void removeProd();
	void display();
	void edit();
};

