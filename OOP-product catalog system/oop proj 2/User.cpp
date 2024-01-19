#include "User.h"

User::User()
{
	name = " ";
	cnic = " ";
	userName = " ";
	password = " ";
	phoneNumber = " ";
	gender = ' ';
	city = " ";
	money = 0;
}

void User::RegMan()
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

	cout << "Enter city" << endl;
	cin >> city;

	cout << "Enter password" << endl;
	cin >> password;

	string temppw;
	cout << "Enter password again" << endl;
	cin >> temppw;

	while (password!=temppw) {
		cout << "Passwords must match, re-enter" << endl;
		cin >> temppw;
	}

	ofstream myFile("Manager.bin", ios::binary | ios::app);
	if (myFile.write((char*)this, sizeof(this)))
		cout << "Manager has been registeref!" << endl;
	else
		cout << "Can not register, system down" << endl;
	myFile.close();

}

bool User::login(string fileName)
{
	bool in = false;
	string uName, pass;
	cout << "Enter username" << endl;
	cin >> uName;
	cout << "Enter password" << endl;
	cin >> pass;

	User temp;
	ifstream myFile(fileName, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		//if (strcmp(temp.userName, uName) == 0 && strcmp(temp.password, pass) == 0) {
		if (temp.getUsername() == uName && temp.getPassword() == password) {
			cout << "Logged in" << endl;
			in = true;
			myFile.close();
		}
	}
	if (in == false) {
		cout << "Login failed" << endl;
		exit(0);
	}
	return in;
}

//bool User::login(string fileName)
//{
//	return 0;
//}



void User::display()
{
	cout << "Name: " << name << endl;
	cout << "CNIC: " << cnic << endl;
	cout << "Username: " << userName << endl;
	cout << "Password: " << password << endl;
}

string User::getUsername()
{
	
	return userName;

}

string User::getPassword()
{
	return password;
}

string User::getName()
{
	return name;
}
string User::getCnic()
{
	return cnic;
}
string User::getNum()
{
	return phoneNumber;
}
char User::getGender()
{
	return gender;
}
string User::getCity()
{
	return city;
}
string User::getMoney()
{
	string n = to_string(money);
	return n;
}


void User::setName(string n) {
	name = n;
}
void User::setUsername(string n) {
	userName = n;
}
void User::setCnic(string n) {
	cnic = n;
}
void User::setPassword(string n) {
	password = n;
}
void User::setnum(string n) {
	phoneNumber = n;
}
void User::setGender(char n) {
	gender = n;
}
void User::setCity(string n) {
	city = n;
}
void User::setMoney(int n) {
	money = n;
}