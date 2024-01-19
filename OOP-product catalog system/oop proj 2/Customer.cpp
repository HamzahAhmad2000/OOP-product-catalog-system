#include "Customer.h"

Customer::Customer(Inventory* in)
{
	invent = in;
}

void Customer::Register()
{
	//cout << "Enter name" << endl;
	//cin.getline(name, 150);

	//cout << "Enter cinc" << endl;
	//cin.getline(cnic, 150);

	//cout << "Enter address" << endl;
	//cin.getline(address, 150);

	//cout << "Enter username" << endl;
	//cin.getline(userName, 150);

	//char opt = '1';
	//cout << "Select city" << endl;
	//cout << "1. Karachi" << endl;
	//cout << "2. Lahore" << endl;
	//cout << "3. Islamabad" << endl;
	//cin >> opt;

	//string k = "Karachi";
	//string i = "Islamabad";
	//string l = "Lahore";

	//if (opt == '1')
	//	city = &k[0];
	//if (opt == '2')
	//	city = &i[0];
	//if (opt == '3')
	//	city = &l[0];


	//cout << "Enter password" << endl;
	//cin.getline(password, 150);

	//char temppw[150];
	//cout << "Enter password again" << endl;
	//cin.getline(temppw, 150);
	//
	//while (strcmp(password, temppw) != 0) {
	//	cout << "Passwords must match, re-enter" << endl;
	//	cin.getline(temppw, 150);
	//}
	//cout << "Enter gender" << endl;
	//cin >> gender;

	//cout << "Enter money" << endl;
	//cin >> money;
	//
	//ofstream myFile("Customer.bin", ios::binary | ios::app);
	//if (myFile.write((char*)&*this, sizeof(Customer)))
	//	cout << "You have been registered!" << endl;
	//else
	//	cout << "Can not register, system down" << endl;
	//myFile.close();

}

void Customer::Menu()
{
	int input;
	//if (login("Customer.bin")) {
	if (1) {
		do {
			cout << "           MENU           " << endl;
			cout << "Select an option" << endl;
			cout << "1. View store" << endl;
			cout << "2. Add to cart" << endl;
			cout << "3. Checkout" << endl;
			cout << "4. Remove from cart" << endl;
			cout << "5.	See cart" << endl;
			cout << "6. logout" << endl;
			cin >> input;
			
			switch(input) {
			case 1:
				invent->setName("Inventory.bin");
				invent->display();
				break;
			case 2:
				addToCart();
				break;
			case 3: 
				checkout();
				break;
			case 4: 
				removeFromCart();
				break;
			case 5:
				seeCart();
				break;
			default:
				cout << "Wrong choice" << endl;
				break;
			}
		} while (input != 6);
	}
	else
		return;
}

void Customer::addToCart()
{
	char name[150];
	int n = 0;
	bool found = 0;
	cout << "Enter name of product you want to buy" << endl;
	cin.getline(name, 150);
	cout << "Enter amount you want to buy" << endl;
	cin >> n;

	Products temp;
	ifstream myFile("Inventory.bin", ios::binary);
	while (myFile.read((char*)&temp, sizeof(Products))) {
		if (temp.getName() == name && temp.getStock()>=n) {
			found = 1;
			break;
			myFile.close();
		}
	}
	temp.setStock(n);

	if (found == 1) {
		
		ofstream myFile("Cart.bin", ios::binary | ios::app);
		if (myFile.write((char*)&temp, sizeof(Products)))
			cout << "Added to Cart!" << endl;
		else
			cout << "Couldnt add to cart" << endl;
		myFile.close();
	}

	if (found == 0)
		cout << "couldnt add to cart" << endl;
	return;
}

void Customer::seeCart()
{
	Products temp;
	ifstream myFile("Inventory.bin", ios::binary);
	while (myFile.read((char*)&temp, sizeof(Products))) {
		temp.display();
	}
	myFile.close();
}

void Customer::removeFromCart()
{
	char name[150];
	cout << "Enter name of product you want to buy" << endl;
	cin.getline(name, 150);

	Products temp;
	fstream myFile("Cart.bin", ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(Products))) {
		if (temp.getName() != name) {
			myFile_temp.write((char*)&temp, sizeof(Products));
		}
	}
	myFile.close();
	myFile_temp.close();
	remove("Cart.bin");
	rename("temp.bin", "Cart.bin");
}

void Customer::checkout()
{
	int total = 0;
	Products temp;
	ifstream myFile("Cart.bin", ios::binary);
	while (myFile.read((char*)&temp, sizeof(Products))) {
		total+=temp.getPrice()*temp.getStock();
	}
	myFile.close();

	cout << "Money in your account is: " << money << endl;
	cout << "Your total is: " << total<<endl;
	if (money >= total) {
		money -= total;
		cout << "Thank you for shopping" << endl;
	}
	else
		cout << "Insuffient ballaance" << endl;

	char feedback[150];
	cout << "Please give feedback" << endl;
	cin.getline(feedback, 150);

	//why this no work
	ofstream File("Feedback.bin", ios::binary | ios::app);
	if (File.write((char*)&feedback, sizeof(char)))
		cout << "Feedback recorded!" << endl;
	else
		cout << "couldnt record feedback" << endl;
	File.close();

}

