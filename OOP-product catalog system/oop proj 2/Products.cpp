#include "Products.h"

Products::Products()
{
	stock = 0;
	price = 0;
	name = new char[150];
	catagory = new char[150];
}

void Products::display()
{
	cout << "Name: " << name;
	cout << "Catagory: " << catagory;
	cout << "Stoc: " << name << endl;
	cout << "Price: " << price << endl << endl;
}

void Products::displayCat()
{
	cout << "Name: " << name<<endl;
	cout << "Price: " << price << endl;
	cout << "Catagory: " << catagory<<endl<<endl;
}

char* Products::getName()
{
	return name;
}

int Products::getPrice()
{
	return price;
}

char* Products::getCatagory()
{
	return catagory;
}

int Products::getStock()
{
	return stock;
}

void Products::setName(char* n)
{
	name = n;
}

void Products::setPrice(int n)
{
	price = n;
}

void Products::setCatagory(char* n)
{
	catagory = n;
}

void Products::setStock(int n)
{
	stock = 0;
}
