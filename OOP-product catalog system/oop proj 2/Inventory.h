#pragma once
#include<iostream>
#include<fstream>
#include"Products.h"
using namespace std;
class Inventory
{
	string fileName;
public:
	Inventory(string name);
	void setName(string name);
	void add();
	void removeProd();
	void display();
	void edit();
};

