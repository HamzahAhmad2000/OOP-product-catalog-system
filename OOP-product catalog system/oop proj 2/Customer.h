#pragma once
#include"User.h"
#include"Inventory.h"
#include<string>
#include<fstream>
#include<cstring>

class Customer: public User
{
	Inventory* invent;

public:
	Customer(Inventory* in);
	void Register();
	void Menu();//delete cart after a customer makes purchase
	void addToCart();
	void seeCart();
	void removeFromCart();
	void checkout();
};

