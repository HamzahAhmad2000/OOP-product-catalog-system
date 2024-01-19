#pragma once
#include<iostream>
#include<string>
#include"Inventory.h"
#include"User.h"
class Manager: public User
{
	Inventory* in;

public:
	Manager(Inventory* temp);
	void Menu();

};

