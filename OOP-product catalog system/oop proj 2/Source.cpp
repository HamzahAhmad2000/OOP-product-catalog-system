#include<iostream>
#include<string>
#include<fstream>
#include"User.h"
#include"Inventory.h"
#include"Admin.h"
#include"Customer.h"
#include"Catalog.h"
#include"Manager.h"
using namespace std;

void printFeedback();
void logMenu();
bool login(string filename);
void Register(string filename);
void regMenu();
int main() {

	int input = 0;
	cout << "                    Welcome to New Age Grocery Store                    " << endl << endl << endl<<endl;
	do {
		cout << "Press: " << endl;
		cout << "1- Login" << endl;
		cout << "2- Register" << endl;
		cout << "3- Exit" << endl;
		cout << "Feedback from customer: " << endl;
		printFeedback();

		cout << "Input your choice: ";
		cin >> input;
		switch (input) {
		case 1:
			logMenu();
			break;
		case 2:
			regMenu();
			break;
		case 3:
			return 0;
			break;
		default:
			cout << "Wrong input" << endl;
		}
	} while (true);
}

void printFeedback() {

	char* temp=nullptr;
	ifstream myFile("Feedback.bin", ios::binary);
	while (myFile.read((char*)&temp, sizeof(char*))) {
		cout << temp<<endl;
	}
	myFile.close();
}

void logMenu() {
	int in = 0;
	bool loggedIn = 0;
	User user;
	Catalog catalog("Catalog.bin");
	Inventory inventory("Inventory.bin");
	Admin ad(&catalog);
	Customer cus(&inventory);
	Manager manager(&inventory);
	do {
		cout << "                    SUBMENU                    " << endl << endl << endl;
		cout << "1- Admin" << endl;
		cout << "2- Manager" << endl;
		cout << "3- Customer" << endl;
		cout << "Enter choice: " << endl;
		cin >> in;
		switch (in) {
		case 1:
			if(login("Admin.dat"));
				ad.Menu();
			break;
		case 2:
			if(login("Manager.dat"));
				manager.Menu();
			break;
		case 3:
			if(login("Customer.dat"));
				cus.Menu();
			break;
		default:
			cout << "incorrect input" << endl;
		}
	} while (1);
}

void regMenu() {
	Catalog catalog("Catalog.bin");
	Inventory inventory("Inventory.bin");
	Admin ad(&catalog);
	Customer cus(&inventory);
	int in;
	do {
		cout << "                    REGISTRATION MENU                    " << endl << endl << endl;
		cout << "1- Admin" << endl;
		cout << "2- Customer" << endl;
		cout << "3- Exit" << endl;
		cout << "Enter choice: " << endl;
		cin >> in;
		switch (in) {
		case 1:
			Register("Admin.dat");
			return;
			break;
		case 2:
			Register("Customer.dat");
			return;
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "Incorrect input" << endl;
		}
	} while (1);
}


bool login(string fileName)
{
	bool in = false;
	string uName, pass;
	cout << "Enter username" << endl;
	cin >> uName;
	cout << "Enter password" << endl;
	cin >> pass;

	User temp;
	ifstream myFile;
	string Username;
	string Password;
	myFile.open(fileName, ios::in | ios::binary);
	for (int i = 0; i < 50; i++) {
		if (myFile.is_open()) {

			myFile >> Username;
			myFile >> Password;

			/*cout << Username ;
			cout << Password ;*/

			if (uName == Username && Password == pass) {
				in = true;
				break;
			}
		}
		//cout << endl;
	}
	if (in == false) {
		cout << "Login failed" << endl;
		exit(0);
	}
	return in;
}

void Register(string fileName)
{
	User temp;
	string t;
	cout << "Enter name" << endl;
	cin >> t;
	temp.setName(t);

	cout << "Enter cinc" << endl;
	cin >> t;
	while (t.length() != 13) {
		cout << "CNIC must be 13 digits" << endl;
		cin >> t;
	}
	temp.setCnic(t);

	cout << "Enter username" << endl;
	cin >> t;
	temp.setUsername(t);

	char opt = '1';
	cout << "Select city" << endl;
	cout << "1. Karachi" << endl;
	cout << "2. Lahore" << endl;
	cout << "3. Islamabad" << endl;
	cin >> opt;
	string k = "Karachi";
	string i = "Islamabad";
	string l = "Lahore";
	if (opt == '1')
		temp.setCity("Karachi");
	if (opt == '2')
		temp.setCity("Islamabad");
	if (opt == '3')
		temp.setCity("Lahore");

	cout << "Enter password" << endl;
	cin >> t;
	string tempStr;
	cout << "Re-enter password" << endl;
	cin >> tempStr;
	while (t != tempStr)
	{
		cout << "Passwords must match, re-enter password" << endl;
		cin >> tempStr;
	}
	temp.setPassword(t);
	

	char s;
	cout << "Enter gender" << endl;
	cin >> s;
	temp.setGender(s);
	int n;
	cout << "Enter money" << endl;
	cin >> n;
	temp.setMoney(n);
	
	ofstream myFile;
	myFile.open(fileName, ios::out | ios::app | ios::binary);
	if (myFile.is_open())
	{
		myFile << temp.getUsername() << " " << temp.getPassword() << " " << temp.getName() << " " << temp.getCnic() << " " << temp.getNum() << " " << temp.getGender() << " " << temp.getCity() << " " << temp.getPassword() << " " << temp.getMoney() << endl;
	}
	myFile.close();

	return;
}