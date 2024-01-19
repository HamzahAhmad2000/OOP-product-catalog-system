#include "Manager.h"



Manager::Manager(Inventory* temp)
{
	in = temp;
}

void Manager::Menu()
{
		int input;
		//if (login("Manager.bin")) {
		if (1) {
			do {
				cout << "           MENU           " << endl;
				cout << "Select an option" << endl;
				cout << "1. View Inventory" << endl;
				cout << "2. Add to Inventory" << endl;
				cout << "3. Edit product in Inventory" << endl;
				cout << "4. Remove from Inventory" << endl;
				cout << "5.	View other inventories" << endl;
				cout << "6. logout" << endl;
				cin >> input;

				switch (input) {
				case 1:
					in->display();
					break;
				case 2:
					in->add();
					break;
				case 3:
					in->edit();
					break;
				case 4:
					in->removeProd();
					break;
				case 5:
					cout << "didnt do this part hehe" << endl;
					break;
				case 6:
					cout << "Logging out" << endl;
					break;
				default:
					cout << "Wrong choice" << endl;

				}
			} while (input != 6);
		}
		else
			return;
}
