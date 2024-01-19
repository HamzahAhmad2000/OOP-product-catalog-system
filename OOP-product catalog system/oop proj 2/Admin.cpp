#include "Admin.h"

Admin::Admin(Catalog* cat)
{
	catalog = cat;
	fileName = "Admin.dat";
}

void Admin::Menu()
{
	User man;
	int input;
	//if (adLogin()) {
		do {
			cout << "           MENU           " << endl;
			cout << "Select an option" << endl;
			cout << "1. View catalog" << endl;
			cout << "2. Add to catalog" << endl;
			cout << "3. Edit product in catalog" << endl;
			cout << "4. Remove from catalog" << endl;
			cout << "5.	Register manager" << endl;
			cout << "6. logout" << endl;
			cin >> input;

			switch (input) {
			case 1:
				catalog->display();
				break;
			case 2:
				catalog->add();
				break;
			case 3:
				catalog->edit();
				break;
			case 4:
				catalog->removeProd();
				break;
			case 5:
				man.RegMan();
				break;
			case 6:
				cout << "Logging out" << endl;
				exit(0);
				break;
			default:
				cout << "Wrong choice" << endl;
			}
		} while (input != 6);
	//}
	//else {
	//	cout << "Login failed" << endl;
	//	return;
	//}
		
}

void Admin::Register()
{
	cout << "Enter name" << endl;
	cin >> name;

	cout << "Enter cinc, must be 13 digits" << endl;
	cin >> cnic;
	while (cnic.length() != 13) {
		cout << "Enter cinc, must be 13 digits" << endl;
		cin >> cnic;
	}

	cout << "Enter username" << endl;
	cin >> userName;

	cout << "Enter password" << endl;
	cin >> password;

	string temppw;
	cout << "Enter password again" << endl;
	cin >> temppw;

	while (password != temppw) {
		cout << "Passwords must match, re-enter" << endl;
		cin >> temppw;
	}

	ofstream myFile("Admin.bin", ios::binary | ios::app);
	if (myFile.write((char*)this, sizeof(this)))
		cout << "Manager has been registeref!" << endl;
	else
		cout << "Can not register, system down" << endl;
	myFile.close();
}

bool Admin::adLogin() {
	bool in = false;
	string username, password;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	User temp;
	ifstream myFile(fileName, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.getUsername() == username && temp.getPassword() == password) {
			cout << "Logged in" << endl;
			cout << getUsername()<<endl;
			cout << getPassword();
			in = true;
			myFile.close();
		}
	}
	return in;
}

string Admin::getUsername()
{
	return userName;
}


	void Admin :: cts(string x, char arr[150]) {
		int len;
		len = x.length();
		for (int i = 0; i < len; i++) {
			arr[i] = x[i];
		}
	}


void Admin :: display(int myLine, User& obj) {
	fstream file;
	file.open(fileName, ios::in | ios::out | ios::binary);
	file.seekg(myLine * sizeof(obj));
	file.read(reinterpret_cast<char*>(&obj), sizeof(obj));
	file.close();
}



