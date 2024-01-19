#pragma once
#include<iostream>
using namespace std;
class Products
{
protected:
	int stock;
	char* name;
	char* catagory;
	int price;
public:
	Products();
	void display();
	void displayCat();
	char* getName();
	int getPrice();
	char* getCatagory();
	int getStock();
	void setName(char* n);
	void setPrice(int n);
	void setCatagory(char* n);
	void setStock(int n);

};

