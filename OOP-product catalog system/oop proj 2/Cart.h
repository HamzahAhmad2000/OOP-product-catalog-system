#pragma once
#include<iostream>
#include<fstream>
#include"Products.h"
#include"Inventory.h"
using namespace std;
class Cart
{
	string fileName;
	Inventory invent;

public:
	Cart();
	void add();
	void display();


};

