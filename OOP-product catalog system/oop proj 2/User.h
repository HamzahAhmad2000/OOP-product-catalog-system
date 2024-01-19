#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;
class User
{
protected:	//so i can easily access in inherited classes
	string name;
	string cnic;
	string userName;
	string password;
	string phoneNumber;
	char gender;
	//char* address;
	string city;
	int money;

public:
	User();
	void RegMan();
	bool login(string filename);
	void display();

	string getUsername();
	string getPassword();

	string getName();
	string getCnic();
	string getNum();
	char getGender();
	string getCity();
	string getMoney();

	void setName(string n);
	void setUsername(string n);
	void setCnic(string n);
	void setPassword(string n);
	void setnum(string n);
	void setGender(char n);
	void setCity(string n);
	void setMoney(int n);

};

