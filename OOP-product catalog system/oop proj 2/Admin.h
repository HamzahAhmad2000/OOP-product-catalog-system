#pragma once
#include"User.h"
#include"Catalog.h"
#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;
class Admin: protected User
{
	Catalog* catalog;
	string fileName;

public:
	Admin(Catalog* cat);
	void Menu();//add feedback class and remove stuff from it
				//display customers and remove them if need be
	void Register();
	void display(int , User&);
	bool adLogin();
	string getUsername();
	void cts(string x, char arr[150]);
};

